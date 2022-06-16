// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them
#define TRIXY_LAYER_BASE_TYPES                                                                          \
    public:                                                                                             \
        using typename Base::Vector;                                                                    \
        using typename Base::Matrix;                                                                    \
        using typename Base::Tensor;                                                                    \
                                                                                                        \
        using typename Base::XVector;                                                                   \
        using typename Base::XMatrix;                                                                   \
        using typename Base::XTensor;                                                                   \
                                                                                                        \
        using typename Base::Linear;                                                                    \
                                                                                                        \
        using typename Base::size_type;                                                                 \
        using typename Base::precision_type;                                                            \
        using typename Base::shape_type;                                                                \
                                                                                                        \
        using typename Base::Generator;                                                                 \
        using typename Base::IActivation;

#define TRIXY_RAW_LAYER_BODY                                                                            \
    public:                                                                                             \
        using Base = ILayer<Net>;                                                                       \
        TRIXY_LAYER_BASE_TYPES                                                                          \

#define TRIXY_TRAIN_LAYER_BODY                                                                          \
    public:                                                                                             \
        using Base = ITrainLayer<Net>;                                                                  \
        using typename Base::IOptimizer;                                                                \
        TRIXY_LAYER_BASE_TYPES

