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
              class SreamWrapper = sf::wrapper::ofile_stream_t<OutStream>>
    static void serialize(OutStream& out, Serializable& serializable)
    {
        std::vector<unsigned char> storage;
        {
            auto archive = sf::oarchive(storage);
            archive & serializable;
        }
        {
            auto archive = sf::oarchive<SreamWrapper>(out);
            archive & storage;
        }
    }

    template <class InStream,
              class SreamWrapper = sf::wrapper::ifile_stream_t<InStream>>
    static void deserialize(InStream& in, Serializable& serializable)
    {
        std::vector<unsigned char> storage;
        {
            auto archive = sf::iarchive<SreamWrapper>(in);
            archive & storage;
        }
        {
            auto archive = sf::iarchive(storage);
            archive & serializable;
        }
    }
};

} // namespace trixy

#endif // TRIXY_SERIALIZER_CORE_HPP
