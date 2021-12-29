#ifndef BASE_OPTIMIZER_HPP
#define BASE_OPTIMIZER_HPP

#include "Trixy/Neuro/Detail/neuro_function_id.hpp"

namespace trixy
{

namespace train
{
template <typename Optimizeriable, function::OptimizationId optimization_id, typename enable = void>
class Optimizer;

} // namespace train

} // namespace trixy

#endif // BASE_OPTIMIZER_HPP
