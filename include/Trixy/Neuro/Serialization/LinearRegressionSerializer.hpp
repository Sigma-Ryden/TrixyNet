#ifndef LINEAR_REGRESSION_SERIALIZER_HPP
#define LINEAR_REGRESSION_SERIALIZER_HPP

#include <fstream> // ifstream, ofstream

#include "Trixy/Neuro/Serialization/BaseSerializer.hpp"
#include "Trixy/Neuro/Detail/TrixyNetMeta.hpp"

#include "Trixy/Neuro/Detail/MacroScope.hpp"

namespace trixy
{

TRIXY_SERIALIZER_TPL_DECLARATION
class TRIXY_SERIALIZER_TPL(meta::is_linear_regression)
{
public:
    using Vector         = typename Serializable::Vector;

    using precision_type = typename Serializable::precision_type;
    using size_type      = typename Serializable::size_type;

private:
    Vector W;            ///< Inner weight
    size_type N;         ///< Size of weight vector (same as sample size + 1)

public:
    Serializer() = default;

    void prepare(const Serializable& reg);

    void serialize(std::ofstream& out) const;
    void deserialize(std::ifstream& in);

    const Vector& getWeight() const noexcept { return W; };
    size_type getSize() const noexcept { return N; };
};

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_linear_regression)::prepare(const Serializable& reg)
{
    W = reg.getInnerWeight();
    N = reg.getInnerSize();
}

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_linear_regression)::serialize(std::ofstream& out) const
{
    out.write(CONST_BYTE_CAST(&N), sizeof(size_type));

    for(size_type i = 0; i < W.size(); ++i)
        out.write(CONST_BYTE_CAST(&W(i)), sizeof(precision_type));
}

TRIXY_SERIALIZER_TPL_DECLARATION
void TRIXY_SERIALIZER_TPL(meta::is_linear_regression)::deserialize(std::ifstream& in)
{
    in.read(BYTE_CAST(&N), sizeof(size_type));

    W.resize(N + 1);

    for(size_type i = 0; i < W.size(); ++i)
        in.read(BYTE_CAST(&W(i)), sizeof(precision_type));
}

} // namespace trixy

#include "Trixy/Neuro/Detail/MacroUnscope.hpp"

#endif // LINEAR_REGRESSION_SERIALIZER_HPP
