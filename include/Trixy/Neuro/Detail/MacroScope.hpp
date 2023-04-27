// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them
#ifndef TRIXY_NEURO_DETAIL_MACRO_SCOPE_HPP
#define TRIXY_NEURO_DETAIL_MACRO_SCOPE_HPP

#include <Trixy/Detail/MetaMacro.hpp> // TRIXY_TEMPLATE

#define TRIXY_NET_TEMPLATE(...) TRIXY_TEMPLATE(typename TypeSet)
#define TRIXY_SERIALIZER_TEMPLATE(...) TRIXY_TEMPLATE(class Serializable)
#define TRIXY_FUNCTIONAL_TEMPLATE(...) TRIXY_TEMPLATE(class Functionable)
#define TRIXY_OPTIMIZER_TEMPLATE(...) TRIXY_TEMPLATE(class Optimizeriable, class TypeSet)
#define TRIXY_TRAINING_TEMPLATE(...) TRIXY_TEMPLATE(class Trainable)
#define TRIXY_REGRESSION_TEMPLATE(...) TRIXY_TEMPLATE(typename TypeSet)

#define TRIXY_OPTIMIZER_TEMPLATE_CLASS(is_type, optimizer_type)                                         \
    Optimizer<optimizer_type, Optimizeriable, TypeSet, TRWITH(Optimizeriable, is_type)>

#endif // TRIXY_NEURO_DETAIL_MACRO_SCOPE_HPP
