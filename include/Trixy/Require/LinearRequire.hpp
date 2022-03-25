#ifndef LINEAR_REQUIRE_HPP
#define LINEAR_REQUIRE_HPP

namespace trixy
{

template <class Linear>
struct LinearRequire : protected Linear
{
public:
    using type = Linear;

protected:
    using require = Linear;

protected:
    using typename require::size_type;
    using typename require::precision_type;

protected:
    using require::first;
    using require::last;

    using require::dot;
    using require::tensordot;

    using require::add;
    using require::sub;
    using require::mul;
    using require::join;

    using require::apply;

    using require::for_each;
};

} // namespace trixy

#endif // LINEAR_REQUIRE_HPP
