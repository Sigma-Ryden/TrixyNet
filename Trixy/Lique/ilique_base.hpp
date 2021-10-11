#ifndef ILIQUE_BASE_HPP
#define ILIQUE_BASE_HPP

namespace ilique
{

template <template <typename T> class Tensor, typename Type>
class ILiqueBase
{
protected:
    virtual ~ILiqueBase() {}

public:
    virtual Tensor<Type>& fill(Type value) = 0;
    virtual Tensor<Type>& fill(Type (*generator)()) = 0;

    virtual Tensor<Type> apply(Type (*function)(Type)) const = 0;
    virtual Tensor<Type>& modify(Type (*function)(Type)) = 0;

    virtual Tensor<Type> multiply(const Tensor<Type>&) const = 0;
    virtual Tensor<Type> join(Type value) const = 0;

    virtual Tensor<Type> operator+ (const Tensor<Type>&) const = 0;
    virtual Tensor<Type> operator- (const Tensor<Type>&) const = 0;
    virtual Tensor<Type>& operator+= (const Tensor<Type>&) = 0;
    virtual Tensor<Type>& operator-= (const Tensor<Type>&) = 0;
};

} // namespace ilique

#endif // ILIQUE_BASE_HPP
