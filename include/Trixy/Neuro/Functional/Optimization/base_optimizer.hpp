#ifndef BASE_OPTIMIZER_HPP
#define BASE_OPTIMIZER_HPP

#include "Trixy/Neuro/Functional/neuro_functional_id.hpp"

namespace trixy
{

namespace train
{

template <class Optimizeriable, class optimizer_type, typename enable = void>
class Optimizer;

} // namespace train

} // namespace trixy

#endif // BASE_OPTIMIZER_HPP
