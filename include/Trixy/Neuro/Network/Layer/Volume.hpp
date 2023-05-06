#ifndef TRIXY_NETWORK_LAYER_VOLUME_HPP
#define TRIXY_NETWORK_LAYER_VOLUME_HPP

#include <cstddef> // size_t

#include <Trixy/Lique/Shape.hpp>

namespace trixy
{

namespace set
{

// Examples:
// Convolutional(Input(3, 128, 128), Filter(7, 64), Padding(3));
// MaxPooling(Input(3, 64, 64), Padding(3, 3), Stride(2));
// FullyConnected(Input(512), Output(6));

using Volume3D = lique::Shape<std::size_t>;

struct Volume2D : Volume3D
{
private:
    using Volume3D::depth;

public:
    Volume2D(size_type h, size_type w) : Volume3D(1, h, w) {}
    Volume2D(size_type s) : Volume3D(s, s) {}
};

using Input = Volume3D;
using Output = Volume3D;
using Filter = Volume3D;

// only for possible square size
using Stride = Volume2D;
using Padding = Volume2D;

} // namespace set

} // namespace trixy

#endif // TRIXY_NETWORK_LAYER_VOLUME_HPP
