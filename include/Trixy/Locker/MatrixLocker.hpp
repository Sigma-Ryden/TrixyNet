#ifndef MATRIX_LOCKER_HPP
#define MATRIX_LOCKER_HPP

#include <utility> // move, forward

#include "BaseLocker.hpp"
#include "Trixy/Detail/TrixyMeta.hpp"

#include "Trixy/Detail/MacroScope.hpp"

namespace trixy
{

template <class Matrix>
using MatrixLocker = Locker<Matrix, LockerType::matrix>;

template <class Matrix>
class Locker<Matrix, LockerType::matrix> : protected Matrix
{
protected:
    using require        = Matrix;

public:
    using type           = typename Matrix::type;

    using size_type      = typename Matrix::size_type;
    using precision_type = typename Matrix::precision_type;

    using pointer        = typename Matrix::pointer;
    using const_pointer  = typename Matrix::const_pointer;

    using Shape          = typename Matrix::Shape;

public:
    // We MUST define explicit copy and move constructors
    // to prevent EATING args by constructor with perfect forwarding
    template <typename... Args,
        typename = TRIXY_ENABLE(meta::is_not_base_of<meta::decay_t<Args>, Locker>...),
        typename = TRIXY_ENABLE(std::is_constructible<Matrix, Args...>)>
    explicit Locker(Args&&... args) : Matrix(std::forward<Args>(args)...) {}

    // operator= for copy and move Locker object will not implicit generate
    Locker(const Locker& matrix) : Matrix(matrix) {}
    Locker(Locker&& matrix) noexcept : Matrix(std::move(matrix)) {}

    Locker(const Matrix& matrix) : Matrix(matrix) {}
    Locker(Matrix&& matrix) noexcept : Matrix(std::move(matrix)) {}

    ~Locker() = default;

    const Matrix& base() const noexcept
    { return static_cast<const Matrix&>(*this); }

public:
    using require::operator();

    using require::copy;
    using require::size;
    using require::shape;

    using require::fill;
    using require::apply;

    using require::dot;

    using require::add;
    using require::sub;
    using require::join;

    using require::transpose;
    using require::inverse;

    using require::data;
};

} // namespace trixy

#include "Trixy/Detail/MacroUnscope.hpp"

#endif // MATRIX_LOCKER_HPP
