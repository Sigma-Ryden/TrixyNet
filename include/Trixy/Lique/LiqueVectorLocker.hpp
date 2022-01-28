#ifndef LIQUE_VECTOR_LOCKER_HPP
#define LIQUE_VECTOR_LOCKER_HPP

#include <utility> // move
#include <initializer_list> // initializer_list

#include "LiqueBaseTensor.hpp"
#include "LiqueBaseLocker.hpp"

#include "Detail/LiqueMeta.hpp"

#include "Detail/MacroScope.hpp"

namespace lique
{

LIQUE_LOCKER_TPL_DECLARATION
class LIQUE_LOCKER_TPL(meta::is_vector) : protected Lockable
{
public:
    using size_type      = typename Lockable::size_type;
    using precision_type = typename Lockable::precision_type;

    using pointer        = typename Lockable::pointer;
    using const_pointer  = typename Lockable::const_pointer;

    using Generator      = typename Lockable::Generator;
    using Function       = typename Lockable::Function;

public:
    Locker() : Lockable() {}
    ~Locker() {}

    explicit Locker(size_type size) : Lockable(size) {}
    Locker(size_type size, precision_type fill_value) : Lockable(size, fill_value) {}
    Locker(size_type size, const precision_type* ptr) : Lockable(size, ptr) {}

    Locker(const Locker& tensor) : Lockable(tensor) {}
    Locker(Locker&& tensor) noexcept : Lockable(std::move(tensor)) {}

    Locker(const Lockable& tensor) : Lockable(tensor) {}
    Locker(Lockable&& tensor) noexcept : Lockable(std::move(tensor)) {}

    Locker(std::initializer_list<precision_type> list) : Lockable(list) {}

    Locker& operator= (const Locker& vector) = delete;
    Locker& operator= (Locker&& vector) = delete;

    const Lockable& base() const { return static_cast<const Lockable&>(*this); }

public:
    using Lockable::operator();

    using Lockable::copy;
    using Lockable::size;

    using Lockable::fill;
    using Lockable::apply;

    using Lockable::dot;
    using Lockable::add;
    using Lockable::sub;
    using Lockable::join;

    using Lockable::data;
};

} // namespace lique

#include "Detail/MacroUnscope.hpp"

#endif // LIQUE_VECTOR_LOCKER_HPP
