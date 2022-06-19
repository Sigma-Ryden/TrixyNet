// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them
#define TRIXY_LAYER_BASE_TYPES                                                                          \
    public:                                                                                             \
        template <typename T>                                                                           \
        using Container = typename Base::template Container<T>;                                         \
                                                                                                        \
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

#define TRIXY_LAYER_PARAM_2D(name)                                                                      \
    struct name : Volume<2> {                                                                           \
    private:                                                                                            \
        enum { Width, Height };                                                                         \
    public:                                                                                             \
        name(size_type w, size_type h) : Volume() {                                                     \
            data_[Width] = w;                                                                           \
            data_[Height] = h;                                                                          \
        }                                                                                               \
        name(size_type n) : name(n, n) {}                                                               \
        size_type width() const noexcept { return data_[Width]; }                                       \
        size_type height() const noexcept { return data_[Height]; }                                     \
    }

#define TRIXY_LAYER_PARAM_3D(name)                                                                      \
    struct name : Volume<3> {                                                                           \
    private:                                                                                            \
        enum { Wight, Height, Depth };                                                                  \
    public:                                                                                             \
        name(size_type w, size_type h = 1, size_type d = 1) {                                           \
            data_[Wight] = w;                                                                           \
            data_[Height] = h;                                                                          \
            data_[Depth] = d;                                                                           \
        }                                                                                               \
        size_type width() const noexcept { return data_[Wight]; }                                       \
        size_type height() const noexcept { return data_[Height]; }                                     \
        size_type depth() const noexcept { return data_[Depth]; }                                       \
    }
