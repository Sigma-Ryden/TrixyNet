#ifndef LIQUE_VECTOR_HPP
#define LIQUE_VECTOR_HPP

#include <cstddef> // size_t
#include <initializer_list> // initializer_list
#include <type_traits> // enable_if, is_arithmetic

namespace lique
{

template <typename Precision, typename enable = void>
class Vector;

} // namespace lique

#define LIQUE_VECTOR_TPL                                                     \
    Vector<Precision,                                                        \
        typename std::enable_if<std::is_arithmetic<Precision>::value>::type>

namespace lique
{

template <typename Precision>
class Vector<Precision, typename std::enable_if<std::is_arithmetic<Precision>::value>::type>
{
public:
    using size_type       = std::size_t;
    using reference       = Precision&;
    using const_reference = const Precision&;

protected:
    Precision* data_;
    size_type  size_;

public:
    Vector() noexcept;
    ~Vector();
    explicit Vector(size_type n);
    Vector(const Vector&);
    Vector(Vector&&) noexcept;
    Vector(const std::initializer_list<Precision>&);

    Vector& operator= (const Vector&);
    Vector& operator= (Vector&&) noexcept;

    Vector& copy(const Vector&) noexcept;
    Vector& copy(const std::initializer_list<Precision>&) noexcept;

    size_type size() const noexcept;
    void resize(size_type new_size);

    reference operator() (size_type i) noexcept;
    const_reference operator() (size_type i) const noexcept;

    Vector& fill(Precision (*generator)()) noexcept;
    Vector& fill(Precision value) noexcept;

    Vector apply(Precision (*function)(Precision)) const;
    Vector& apply(Precision (*function)(Precision)) noexcept;
    Vector& apply(Precision (*function)(Precision), const Vector&) noexcept;

    Precision dot(const Vector&) const;

    Vector& add(const Vector&) noexcept;
    Vector& sub(const Vector&) noexcept;

    Vector multiply(const Vector&) const;
    Vector& multiply(const Vector&) noexcept;
    Vector& multiply(const Vector&, const Vector&) noexcept;

    Vector join(Precision value) const;
    Vector& join(Precision value) noexcept;
    Vector& join(Precision value, const Vector&) noexcept;

    Precision* data() noexcept;
    const Precision* data() const noexcept;

    Vector operator+ (const Vector&) const;
    Vector operator- (const Vector&) const;
};

template <typename Precision>
inline LIQUE_VECTOR_TPL::Vector() noexcept : data_(nullptr), size_(0)
{
}

template <typename Precision>
inline LIQUE_VECTOR_TPL::~Vector()
{
    delete[] data_;
}

template <typename Precision>
inline LIQUE_VECTOR_TPL::Vector(std::size_t n)
    : data_(new Precision[n]), size_(n)
{
}

template <typename Precision>
LIQUE_VECTOR_TPL::Vector(const Vector& vector)
    : data_(new Precision[vector.size_]), size_(vector.size_)
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = vector.data_[i];
}

template <typename Precision>
inline LIQUE_VECTOR_TPL::Vector(Vector&& vector) noexcept
    : data_(vector.data_), size_(vector.size_)
{
    vector.data_ = nullptr;
}

template <typename Precision>
LIQUE_VECTOR_TPL::Vector(const std::initializer_list<Precision>& init)
    : data_(new Precision[init.size()]), size_(init.size())
{
    size_type i = 0;
    for(const auto& arg: init)
    {
        data_[i] = arg;
        ++i;
    }
}

template <typename Precision>
LIQUE_VECTOR_TPL& LIQUE_VECTOR_TPL::operator= (const Vector& vector)
{
    if(this == &vector)
        return *this;

    delete[] data_;

    size_ = vector.size_;
    data_ = new Precision[size_];

    for(size_type i = 0; i < size_; ++i)
        data_[i] = vector.data_[i];

    return *this;
}

template <typename Precision>
LIQUE_VECTOR_TPL& LIQUE_VECTOR_TPL::operator= (Vector&& vector) noexcept
{
    if(this == &vector)
        return *this;

    delete[] data_;

    size_ = vector.size_;
    data_ = vector.data_;

    vector.data_ = nullptr;

    return *this;
}

template <typename Precision>
LIQUE_VECTOR_TPL& LIQUE_VECTOR_TPL::copy(const Vector& vector) noexcept
{
    if(this == &vector)
        return *this;

    for(size_type i = 0; i < size_; ++i)
        data_[i] = vector.data_[i];

    return *this;
}

template <typename Precision>
LIQUE_VECTOR_TPL& LIQUE_VECTOR_TPL::copy(const std::initializer_list<Precision>& data) noexcept
{
    auto it = data.begin();

    for(size_type i = 0; i < size_; ++i, ++it)
        data_[i] = *it;

    return *this;
}

template <typename Precision>
inline std::size_t LIQUE_VECTOR_TPL::size() const noexcept
{
    return size_;
}

template <typename Precision>
void LIQUE_VECTOR_TPL::resize(std::size_t new_size)
{
    delete[] data_;

    size_ = new_size;
    data_ = new Precision[size_];
}

template <typename Precision>
inline Precision& LIQUE_VECTOR_TPL::operator() (std::size_t i) noexcept
{
    return data_[i];
}

template <typename Precision>
inline const Precision& LIQUE_VECTOR_TPL::operator() (std::size_t i) const noexcept
{
    return data_[i];
}

template <typename Precision>
LIQUE_VECTOR_TPL& LIQUE_VECTOR_TPL::fill(Precision (*generator)()) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = generator();

    return *this;
}

template <typename Precision>
LIQUE_VECTOR_TPL& LIQUE_VECTOR_TPL::fill(Precision value) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = value;

    return *this;
}

template <typename Precision>
LIQUE_VECTOR_TPL LIQUE_VECTOR_TPL::apply(Precision (*function)(Precision)) const
{
    Vector new_vector(size_);

    for(size_type i = 0; i < size_; ++i)
        new_vector.data_[i] = function(data_[i]);

    return new_vector;
}

template <typename Precision>
LIQUE_VECTOR_TPL& LIQUE_VECTOR_TPL::apply(Precision (*function)(Precision)) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = function(data_[i]);

    return *this;
}

template <typename Precision>
LIQUE_VECTOR_TPL& LIQUE_VECTOR_TPL::apply(Precision (*function)(Precision), const Vector& vector) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = function(vector.data_[i]);

    return *this;
}

template <typename Precision>
Precision LIQUE_VECTOR_TPL::dot(const Vector& vector) const
{
    double result = 0.0;

    for(size_type i = 0; i < size_; ++i)
        result += data_[i] * vector.data_[i];

    return result;
}

template <typename Precision>
LIQUE_VECTOR_TPL& LIQUE_VECTOR_TPL::add(const Vector& vector) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] += vector.data_[i];

    return *this;
}

template <typename Precision>
LIQUE_VECTOR_TPL& LIQUE_VECTOR_TPL::sub(const Vector& vector) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] -= vector.data_[i];

    return *this;
}

template <typename Precision>
LIQUE_VECTOR_TPL LIQUE_VECTOR_TPL::multiply(const Vector& vector) const
{
    Vector new_vector(size_);

    for(size_type i = 0; i < size_; ++i)
        new_vector.data_[i] = data_[i] * vector.data_[i];

    return new_vector;
}

template <typename Precision>
LIQUE_VECTOR_TPL& LIQUE_VECTOR_TPL::multiply(const Vector& vector) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] *= vector.data_[i];

    return *this;
}

template <typename Precision>
LIQUE_VECTOR_TPL& LIQUE_VECTOR_TPL::multiply(const Vector& lsh, const Vector& rsh) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = lsh.data_[i] * rsh.data_[i];

    return *this;
}

template <typename Precision>
LIQUE_VECTOR_TPL LIQUE_VECTOR_TPL::join(Precision value) const
{
    Vector new_vector(size_);

    for(size_type i = 0; i < size_; ++i)
        new_vector.data_[i] = value * data_[i];

    return new_vector;
}

template <typename Precision>
LIQUE_VECTOR_TPL& LIQUE_VECTOR_TPL::join(Precision value) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] *= value;

    return *this;
}

template <typename Precision>
LIQUE_VECTOR_TPL& LIQUE_VECTOR_TPL::join(Precision value, const Vector& vector) noexcept
{
    for(size_type i = 0; i < size_; ++i)
        data_[i] = value * vector.data_[i];

    return *this;
}

template <typename Precision>
inline Precision* LIQUE_VECTOR_TPL::data() noexcept
{
    return data_;
}

template <typename Precision>
inline const Precision* LIQUE_VECTOR_TPL::data() const noexcept
{
    return data_;
}

template <typename Precision>
LIQUE_VECTOR_TPL LIQUE_VECTOR_TPL::operator+ (const Vector& vector) const
{
    Vector new_vector(size_);

    for(size_type i = 0; i < size_; ++i)
        new_vector.data_[i] = data_[i] + vector.data_[i];

    return new_vector;
}

template <typename Precision>
LIQUE_VECTOR_TPL LIQUE_VECTOR_TPL::operator- (const Vector& vector) const
{
    Vector new_vector(size_);

    for(size_type i = 0; i < size_; ++i)
        new_vector.data_[i] = data_[i] - vector.data_[i];

    return new_vector;
}

} // namespace lique

// clean up
#undef LIQUE_VECTOR_TPL

#endif // LIQUE_VECTOR_HPP
