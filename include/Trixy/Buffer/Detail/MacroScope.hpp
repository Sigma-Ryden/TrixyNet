// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them
#ifndef TRIXY_BUFFER_DETAIL_MACRO_SCOPE_HPP
#define TRIXY_BUFFER_DETAIL_MACRO_SCOPE_HPP

#define _BUFF_READ_HELPER(name)                                                                         \
    if (id_ == SupportTypeId::name)                                                                     \
        return read_buff<typename SupportType::name>(first, last);

#define _BUFF_DETECT_HELPER(name)                                                                       \
    if (std::is_same<DetectionDataType, typename SupportType::name>::value)                             \
        return SupportTypeId::name;

#endif // TRIXY_BUFFER_DETAIL_MACRO_SCOPE_HPP
