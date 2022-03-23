#ifndef LIQUE_REQUIRE_HPP
#define LIQUE_REQUIRE_HPP

namespace trixy
{

namespace lique
{

template <class Tensor>
class VectorRequire : private Tensor
{
public:
    using Base = Tensor;

protected:
    using typename Base::size_type;
    using typename Base::precision_type;

    using typename Base::pointer;
    using typename Base::const_pointer;

    using typename Base::reference;
    using typename Base::const_reference;

protected:
    using Base::operator=;

    using Base::copy;

    using Base::size;
    using Base::resize;

    using Base::operator();

    using Base::fill;
    using Base::apply;

    using Base::dot;
    using Base::add;
    using Base::sub;
    using Base::multiply;

    using Base::join;

    using Base::data;
};

template <class Tensor>
class MatrixRequire : private Tensor
{
public:
    using Base = Tensor;

protected:
    using typename Base::Shape;

protected:
    using typename Base::size_type;
    using typename Base::precision_type;

    using typename Base::pointer;
    using typename Base::const_pointer;

    using typename Base::reference;
    using typename Base::const_reference;

protected:
    using Base::operator=;

    using Base::copy;

    using Base::shape;
    using Base::size;
    using Base::resize;
    using Base::reshape;

    using Base::fill;
    using Base::apply;

    using Base::operator();

    using Base::dot;
    using Base::add;
    using Base::sub;
    using Base::multiply;
    using Base::join;

    using Base::transpose;
    using Base::inverse;

    using Base::data;
};

template <class Linear>
class LinearRequire : private Linear
{
public:
    using Base = Linear;

protected:
    using typename Base::size_type;
    using typename Base::precision_type;

protected:
    using Base::first;
    using Base::last;

    using Base::dot;
    using Base::tensordot;

    using Base::add;
    using Base::sub;
    using Base::mul;
    using Base::join;

    using Base::apply;

    using Base::for_each;

};

} // namespace lique

} // namespace trixy

#endif // LIQUE_REQUIRE_HPP
