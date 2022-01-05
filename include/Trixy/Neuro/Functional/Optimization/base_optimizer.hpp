#ifndef BASE_OPTIMIZER_HPP
#define BASE_OPTIMIZER_HPP

#include "Trixy/Neuro/Functional/neuro_functional_id.hpp"

namespace trixy
{

namespace train
{

template <typename Optimizeriable, functional::OptimizationId optimizer_id, typename enable = void>
class Optimizer;

} // namespace train

} // namespace trixy

#endif // BASE_OPTIMIZER_HPP
