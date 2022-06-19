#ifndef TRIXY_NETWORK_LAYER_VOLUME_HPP
#define TRIXY_NETWORK_LAYER_VOLUME_HPP

#include <cstddef> // size_t

#include <Trixy/Neuro/Network/Layer/Detail/MacroScope.hpp>

namespace trixy
{

namespace set
{

// Examples:
// Convolutional(Input(128, 128, 3), Filter(7, 7, 64), Padding(3));
// MaxPooling(Input(64, 64, 3), Pooling(3, 3), Stride(2));
// FullyConnected(Input(512), Output(6));

struct VolumeBase
{
    using size_type = std::size_t;
};

template <std::size_t N>
struct Volume : VolumeBase
{
protected:
    size_type data_[N];
};

template <>
struct Volume<1> : VolumeBase
{
protected:
    size_type value_;
};

TRIXY_LAYER_PARAM_3D(Input);
TRIXY_LAYER_PARAM_3D(Output);
TRIXY_LAYER_PARAM_3D(Filter);

TRIXY_LAYER_PARAM_2D(Pool);
TRIXY_LAYER_PARAM_2D(Stride);
TRIXY_LAYER_PARAM_2D(Padding);

} // namespace set

} // namespace trixy

#include <Trixy/Neuro/Network/Layer/Detail/MacroUnscope.hpp>

#endif // TRIXY_NETWORK_LAYER_VOLUME_HPP
