// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them
#ifndef TRIXY_NEURO_CHECKER_DETAIL_MACRO_SCOPE_HPP
#define TRIXY_NEURO_CHECKER_DETAIL_MACRO_SCOPE_HPP

#include <Trixy/Detail/MetaMacro.hpp> // TRIXY_TEMPLATE

#define TRIXY_ACCURACY_TEMPLATE(...)                                                                    \
    TRIXY_TEMPLATE(template <typename, typename...> class Container, class Sample, class Target)

#define TRIXY_ACCURACY_GUIDE_TEMPLATE(...)                                                              \
    TRIXY_TEMPLATE(class Target, class Prediction)

#endif // TRIXY_NEURO_CHECKER_DETAIL_MACRO_SCOPE_HPP
