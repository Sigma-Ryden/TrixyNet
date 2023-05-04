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

#include <iostream> // cin, cout
#include <iomanip> // setprecision, fixed

using Core = trixy::TypeSet<float>;
using Net = trixy::TrixyNet<Core>;

using FullyConnected = trixy::layer::FullyConnected<Net>;

using ReLU = trixy::functional::activation::ReLU<Core::precision_type>;
using SoftMax = trixy::functional::activation::SoftMax<Core::precision_type>;

using CCE = trixy::functional::loss::CCE<Core::precision_type>;
```
Note that <Utility/Core.hpp> is not part of the ```Trixy``` library.

Preparing of the simple train data:
```C++
Core::Container<Core::Tensor> get_simple_test_idata()
{
    return
    {
        {1, 0, 1, 1},
        {1, 1, 1, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {0, 0, 1, 1}
    };
}

Core::Container<Core::Tensor> get_simple_test_odata()
{
    return
    {
        {1, 0, 0},
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 1},
        {0, 1, 0},
        {1, 0, 0}
    };
}
```
Definition of serialization function:
```C++
void simple_test()
{
    trixy::utility::RandomFloating<Core::precision_type> random;
    auto generator = [&random] { return random(-0.5f, 0.5f); };

    // Preparing train data
    auto idata = get_simple_test_idata();
    auto odata = get_simple_test_odata();

    Net net;

    net.add(new FullyConnected(4, 4, new ReLU))
       .add(new FullyConnected(4, 5, new ReLU))
       .add(new FullyConnected(5, 4, new ReLU))
       .add(new FullyConnected(4, 3, new SoftMax));

    net.init(generator);

    trixy::train::Training<Net> train(net);

    train.loss(new CCE);

    auto optimizer = trixy::train::AdamOptimizer(net, 0.01f);

    Timer t;
    train.batch(idata, odata, optimizer, 1000);
    std::cout << "Train second net time: " << t.elapsed() << '\n';

    statistic(net, idata, odata);

    std::ofstream file("simple_test.bin", std::ios::binary);
    if (not file.is_open()) return;

    trixy::Serializer<Net> sr;
    sr.serialize(file, net);

    file.close();
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
Possible output:
```console
Train second net time: 0.011666
<0> [0.999977, 0.000023, 0.000000] : [1.000000, 0.000000, 0.000000]
<1> [0.000014, 0.999986, 0.000000] : [0.000000, 1.000000, 0.000000]
<2> [0.999985, 0.000015, 0.000000] : [1.000000, 0.000000, 0.000000]
<3> [0.008424, 0.002386, 0.989190] : [0.000000, 0.000000, 1.000000]
<4> [0.000015, 0.999985, 0.000000] : [0.000000, 1.000000, 0.000000]
<5> [0.999970, 0.000030, 0.000000] : [1.000000, 0.000000, 0.000000]
Network normal accuracy: 1.000000
```
Definition of deserialization function:
```C++
void simple_test_deserialization()
{
    std::ifstream file("simple_test.bin", std::ios::binary);
    if (not file.is_open()) return;

    Net net;

    trixy::Serializer<Net> sr;
    sr.deserialize(file, net);

    file.close();

    auto idata = get_simple_test_idata();
    auto odata = get_simple_test_odata();

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
<0> [0.999977, 0.000023, 0.000000] : [1.000000, 0.000000, 0.000000]
<1> [0.000014, 0.999986, 0.000000] : [0.000000, 1.000000, 0.000000]
<2> [0.999985, 0.000015, 0.000000] : [1.000000, 0.000000, 0.000000]
<3> [0.008424, 0.002386, 0.989190] : [0.000000, 0.000000, 1.000000]
<4> [0.000015, 0.999985, 0.000000] : [0.000000, 1.000000, 0.000000]
<5> [0.999970, 0.000030, 0.000000] : [1.000000, 0.000000, 0.000000]
Network normal accuracy: 1.000000
```
See full example here: [simple_test](https://github.com/Sigma-Ryden/TrixyNet/tree/master/test/simple_test.cpp).

#### Notes:
Most of the time, you will be preparing data as well as neural networks for training and running.
Therefore, the library provides flexible configuration of neural networks before and during their training.
You can also create and use your own activation and loss functions, optimizers, and even
create your own learning algorithm thanks to the flexibility of the classes.

# License:
This library is an open source project licensed under: [MIT](https://opensource.org/licenses/MIT).
