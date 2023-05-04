#ifndef TRIXY_SERIALIZER_CORE_HPP
#define TRIXY_SERIALIZER_CORE_HPP

#include <Trixy/Serializer/Core.hpp>

#include <Trixy/Neuro/Detail/MacroScope.hpp>
#include <Trixy/Detail/MetaMacro.hpp>

namespace trixy
{

TRIXY_SERIALIZER_TEMPLATE()
class Serializer
{
public:
    template <class OutStream,
              class SreamWrapper = sf::wrapper::OFileStream<OutStream>>
    static void serialize(OutStream& out, Serializable& serializable)
    {
        auto archive = sf::oarchive<SreamWrapper>(out);
        archive & serializable;
    }

    template <class InStream,
              class SreamWrapper = sf::wrapper::IFileStream<InStream>>
    static void deserialize(InStream& in, Serializable& serializable)
    {
        auto archive = sf::iarchive<SreamWrapper>(in);
        archive & serializable;
    }
};

} // namespace trixy

#endif // TRIXY_SERIALIZER_CORE_HPP
