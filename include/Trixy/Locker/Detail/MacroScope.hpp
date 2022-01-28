// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define TRIXY_LOCKER_TPL_DECLARATION                                                                    \
    template <class Lockable>

#define TRIXY_LOCKER_TPL(is_type)                                                                       \
    Locker<Lockable,                                                                                    \
           typename std::enable_if<is_type<Lockable>::value>::type>
