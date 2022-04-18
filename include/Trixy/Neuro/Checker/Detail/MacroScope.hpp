// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define TRIXY_ACCURACY_TPL_DECLARATION                                                                  \
    template <template <typename, typename...> class Container, class Sample, class Target>

#define TRIXY_ACCURACY_GUIDE_TPL_DECLARATION                                                            \
    template <class Target, class Prediction>
