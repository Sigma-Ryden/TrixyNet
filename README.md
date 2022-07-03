# Trixy

```Trixy``` - is a lightweight and flexible C++ machine learning library.
Special features will allow you to completely rebuild the existing core of the system,
without having to rewrite the library code.
The main advantage is user customization.
The implementation of the library is completely platform independent, and the user
can independently implement its own implementation of the functionality and use it.

Are you not satisfied with the performance of the container or tensor you are using?
We will cover you! Use special type sets to inject your types.
Support of the system stable is simple, all types are automatically checked using the Require classes.
And in order not to mistakenly call allocation and mem-move,
all open types of neural networks are wrapped in locking types.
This special term 'Locker' was introduced into the library because it fits well with his duties.
Cross-platform serialization will do away with the errors of the process of restoring objects.

Most library classes and structures can be replaced by custom implementations.
Use ready-made interfaces and wrappers to get things done quickly.

Is a header-only library implemented purely in C++11.

# Main functionality:
* ```Base functional```:
  - Fully Connected NN
  - Convolution NN with different layer types
  - Linear/Polynomial regression
  - Reinforcement learning (under development)
* ```Common functional```:
  - Trainers with any optimizers include user injects
  - Accuracy and Guide classes for NN and Regression checking
  - Functional managers (activation, normalize, loss functions)
  - Cross-platform serialization of NN and regressions
  - Locking types (Lockers)
  - Requires guards
  - ```Portable Linear library```:
    - Vector, Matrix and Tensor
    - Lineary algorithm and operations with
* ```Additional functional```:
  - Injected Generators
  - Parallel algorithms (under development)
  - Container based on std::vector
  - Buffer storage for adaptive data transfer
  
# Features:
```Modularity```: Each class does only the tasks for which it is specialized. No Swiss knives!

```Flexibility```: Most of the functionality can be built in by the user, without affecting the library code. Thanks to template metaprogramming!

```Simplicity```: The friendly interface of the library will allow you to quickly and easily use this. Just play with it a little!

```Extensibility```: Do you want a new feature? Spill it! No more rewriting old code, just write a new one!

```Performance```: We use the best solutions available. Do you want more perfomance? Please refer to item with Flexibility!

# Quick start:
Warning! This is a simple minimal example. You can see real applied examples [here](https://github.com/Sigma-Ryden/TrixyNet/tree/master/test).

Including of common headers for library use:
```C++
#include <Trixy/Core.hpp>
// TrixyNet, Functional, Optimizer, Training
// Serializer, Tensor, Linear, Container, Random

#include <Utility/Core.hpp> // Timer, statistic

#include <cstddef> // size_t
#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed
#include <fstream> // ifstream, ofstream

using namespace trixy;
using namespace trixy::functional;
using namespace trixy::train;
using namespace trixy::utility;

using precision_type = float;
using size_type      = std::size_t;

using Core    = TypeSet<precision_type>;
using FeedNet = FeedForwardNet<Core>;
```
Note that <Utility/Core.hpp> is not part of the ```Trixy``` library.

Preparing of the simple train data:
```C++
template <class Net>
typename Net::template Container<typename Net::Vector> get_simple_test_idata()
{
    return
    {
        {-0.08, 0.04},
        { 0.92, 0.24},
        { 0.4,  0.16},
        {-0.0, -0.24}
    };
}

template <class Net>
typename Net::template Container<typename Net::Vector> get_simple_test_odata()
{
    return
    {
        {1, 0},
        {0, 1},
        {0, 1},
        {1, 0}
    };
}
```
Definition of serialization function:
```C++
void simple_test()
{
    using RandomFloating = RandomFloating<precision_type>;
    using RandomIntegral = RandomIntegral<size_type>;

    auto idata = get_simple_test_idata<FeedNet>();
    auto odata = get_simple_test_odata<FeedNet>();

    // Creating fully connected neural network with 2 inputs, 2 hidden neurons and 2 outputs
    FeedNet net({2, 2, 2});
    
    // The function manager will help us to quickly set up activation, normalization and loss functions
    Functional<FeedNet> manage;

    // The trainer will help us train the neural network, if it's not smart enough
    Training<FeedNet> teach(net);

    // Initialization of weights and biases
    net.inner.initialize(RandomFloating{});

    // Set up some functions
    net.function.activation(manage.get<ActivationId::relu>());
    net.function.normalization(manage.get<ActivationId::softmax>());

    net.function.loss(manage.get<LossId::CCE>());

    // Creating of the optimizer for effective neural network train
    auto optimizer = manage.get<OptimizationId::adam>(net, 0.01);

    Timer t;
    
    // Training of the neural network
    teach.trainStochastic(idata, odata, optimizer, 2000, RandomIntegral{});
    std::cout << "Train time: " << t.elapsed() << '\n';

    statistic(net, idata, odata);

    std::ofstream file("example.bin", std::ios::binary);
    if (not file.is_open()) return;

    // The serializer help us save neural network to some storage
    Serializer<FeedNet> sr;

    // This 2 line below can be replaced by: sr.serialize(net, file);
    sr.prepare(net);
    sr.serialize(file);
    
    out.close();

    std::cout << "End of serialization\n";
}
```
Processing:
```C++
int main()
{
    std::cout << std::fixed << std::setprecision(6);
    
    simple_test();
    
    return 0;
}
```
Output:
```console
Train time: 0.010822
<0> [0.992433, 0.007567] : [1.000000, 0.000000]
<1> [0.000000, 1.000000] : [0.000000, 1.000000]
<2> [0.001142, 0.998858] : [0.000000, 1.000000]
<3> [0.992433, 0.007567] : [1.000000, 0.000000]
Network normal accuracy: 1.000000
End of serialization
```
Definition of deserialization function:
```C++
void simple_test_deserialization()
{
    std::ifstream file("example.bin", std::ios::binary);
    if (not file.is_open()) return;

    auto idata = get_simple_test_idata<FeedNet>();
    auto odata = get_simple_test_odata<FeedNet>();

    Serializer<FeedNet> sr;
    
    // Reading data 
    sr.deserialize(file);
    in.close();

    // Constructing and filling of neural network
    FeedNet net(sr.getTopology());
    Functional<FeedNet> manage;

    net.inner.initialize(sr.getBias(), sr.getWeight());

    net.function.activationSet(manage.get(sr.getAllActivationId()));
    net.function.loss(manage.get(sr.getLossId()));

    // Checking of the result
    statistic(net, idata, odata);
}
```
Processing:
```C++
int main()
{
    std::cout << std::fixed << std::setprecision(6);
    
    simple_test_deserialization();
    
    return 0;
}
```
Output:
```console
<0> [0.998050, 0.001950] : [1.000000, 0.000000]
<1> [0.000000, 1.000000] : [0.000000, 1.000000]
<2> [0.001644, 0.998356] : [0.000000, 1.000000]
<3> [0.999418, 0.000583] : [1.000000, 0.000000]
Network normal accuracy: 1.000000
```
#### Notes:
Most of the time, you will be preparing data as well as neural networks for training and running.
Therefore, the library provides flexible configuration of neural networks before and during their training.
You can also create and use your own activation and loss functions, optimizers, and even
create your own learning algorithm thanks to the flexibility of the classes.

# License:
This library is an open source project licensed under: [MIT](https://opensource.org/licenses/MIT).
