// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define BUFF_DETECT_HELPER(name)                                                                        \
    if(std::is_same<DetectionDataType, typename SupportType::name>::value)                              \
        return SupportTypeId::name;

#define BUFF_CASE_READ_HELPER(name)                                                                     \
    case SupportTypeId::name:                                                                           \
        read_buff<typename SupportType::name>(first, last);                                             \
        break;
