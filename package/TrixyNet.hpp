#ifndef TRIXY_NET_HPP
#define TRIXY_NET_HPP

#include <cstddef> // size_t
#include <cstdint>
// size_t, int8_t, int16_t, int32_t, int64_t
// uint8_t, uint16_t, uint32_t, uint64_t

// This file contains all internal type definitions
// You MUST NOT include here any files

namespace trixy
{

struct TrixyNetType
{
    struct Unified {};
};

struct RegressionType
{
    struct Linear {};
    struct Polynomial {};
};

struct LayerMode
{
    struct Raw {};
    struct Train {};
};

struct LayerType
{
    struct FullyConnected {};
    struct Convolutional {};
    struct MaxPooling {};
};

struct RangeType
{
    struct View {};
    struct Unified {};
};

namespace lique
{

struct TensorType
{
    struct base {};

    struct vector {};
    struct matrix {};
    struct tensor {};
};

struct TensorMode
{
    struct view {};
    struct own {};
};

} // namespace lique

namespace memory
{

struct LockerType
{
    struct container {};
    struct vector {};
    struct matrix {};
    struct tensor {};
};

} // namespace memory

namespace guard
{

struct RequireType
{
    struct precision {};

    struct vector {};
    struct matrix {};
    struct tensor {};

    struct linear {};

    struct container {};
};

} // namespace guard

} // namespace trixy

#include <initializer_list> // initializer_list
#include <new> // operator new[], operator delete[]
#include <utility> // forward

#define SF_GARBAGE_CHECK_DISABLE

namespace sf
{

namespace core
{

#ifndef SF_TYPE_PORTABLE_DISABLE

static_assert(sizeof(char) == 1, "Require character size.");

static_assert(sizeof(float) == 4, "Require floating point number size.");
static_assert(sizeof(double) == 8, "Require double precision floation point number size.");

static_assert(sizeof(int) == 4, "Require integer number size.");

#endif // SF_TYPE_PORTABLE_DISABLE

} // namespace core

} // namespace sf

#include <type_traits>
// is_enum, is_arithmetic, is_array, is_pointer,
// enable_if, is_same, true_type, false_type

#if __cplusplus >= 201703L
#include <any> // any
#endif // if

#include <memory> // shared_ptr
#include <array> // array

#include <tuple> // tuple_element

#define SFREQUIRE(...) ::sf::meta::require<(bool)(__VA_ARGS__)> = 0
#define SFWHEN(...) ::sf::meta::when<(bool)(__VA_ARGS__)>
#define SFVOID(...) ::sf::meta::to_void<decltype(__VA_ARGS__)>

namespace sf
{

namespace meta
{

template <typename... Tn> constexpr bool to_false() noexcept { return false; }

template <typename T, std::size_t I = 0>
auto declval() noexcept -> decltype(std::declval<T>()) { return std::declval<T>(); }

template <bool condition, typename T = void>
using when = typename std::enable_if<condition, T>::type;

template <bool condition>
using require = when<condition, int>;

template <std::size_t I>
using dispatch = std::integral_constant<std::size_t, I>;

template <bool condition>
using boolean = std::integral_constant<bool, condition>;

template <bool condition, typename if_true, typename if_false>
using conditional = typename std::conditional<condition, if_true, if_false>::type;

template <typename T>
using decay = typename std::decay<T>::type;

template <class...> struct all : std::true_type {};
template <class B1> struct all<B1> : B1 {};
template <class B1, class... Bn>
struct all<B1, Bn...> : conditional<bool(B1::value), all<Bn...>, B1> {};

template <class...> struct one : std::false_type {};
template <class B1> struct one<B1> : B1 {};
template <class B1, class... Bn>
struct one<B1, Bn...> : conditional<bool(B1::value), B1, one<Bn...>> {};

template <class B> struct negation : boolean<not bool(B::value)> {};

template <typename T, typename... Tn> struct is_same : all<std::is_same<T, Tn>...> {};

template <typename... Args>
using to_void = void;

namespace detail
{

template <typename T, std::size_t N>
struct remove_pointer_implementation
{
    using type = T;
};

template <typename T>
struct remove_pointer_implementation<T*, 1>
{
    using type = T;
};

template <typename T, std::size_t N>
struct remove_pointer_implementation<T*, N>
{
    using type = typename remove_pointer_implementation<T, N - 1>::type;
};

} // namespace detail

template <typename T, std::size_t N = 1>
using remove_pointer = typename detail::remove_pointer_implementation<T, N>::type;

namespace detail
{

template <typename T, typename = void> struct dereference_implementation { using type = T; };

template <typename T> struct dereference_implementation<T*> { using type = T; };
template <typename T> struct dereference_implementation<std::weak_ptr<T>> { using type = T; };
template <typename T> struct dereference_implementation<std::shared_ptr<T>> { using type = T; };
template <typename T> struct dereference_implementation<std::unique_ptr<T>> { using type = T; };

template <typename T> struct dereference_implementation<T, SFVOID(*std::declval<T>())>
    : std::remove_reference<decltype(*std::declval<T>())> {};

} // namespace detail

template <typename T>
using dereference = typename detail::dereference_implementation<T>::type;

namespace detail
{

template <typename T, std::size_t N>
struct pointer_implementation
{
    using type = typename pointer_implementation<T, N - 1>::type*;
};

template <typename T>
struct pointer_implementation<T, 0>
{
    using type = T;
};

} // namespace detail

template <typename T, std::size_t N = 1>
using pointer = typename detail::pointer_implementation<T, N>::type;

 // limited by template depth
template <std::size_t... I> struct index_sequence
{
    static constexpr std::size_t size() noexcept { return sizeof...(I); }
};

namespace detail
{

template <std::size_t I, std::size_t... In>
struct index_sequence_helper : index_sequence_helper<I - 1, I - 1, In...> {};

template <std::size_t... In>
struct index_sequence_helper<0, In...>
{
    using type = index_sequence<In...>;
};

} // namespace detail

template <std::size_t N>
using make_index_sequence = typename detail::index_sequence_helper<N>::type;

template <typename... Tn>
struct type_array
{
    template <std::size_t I>
    using type = typename std::tuple_element<I, std::tuple<Tn...>>::type;
};

// meta
template <typename T, typename enable = void>
struct is_complete : std::false_type {};

template <typename T>
struct is_complete<T, SFVOID(sizeof(T))> : std::true_type {};

template <typename From, typename To, typename enable = void>
struct can_static_cast : std::false_type {};

template <typename From, typename To>
struct can_static_cast<From, To,
    SFVOID( static_cast<To*>(std::declval<From*>()) )> : std::true_type {};

template <typename T> constexpr std::size_t pointer_count() noexcept
{
    return std::is_pointer<T>::value
         ? 1 + pointer_count<remove_pointer<T>>()
         : 0;
}

struct shared_type {};
struct raw_type {};

struct dummy_type
{
#if __cplusplus >= 201703L
    template <typename T, SFREQUIRE(not std::is_same<T, std::any>::value)> operator T();
#else
    template <typename T> operator T();
#endif // if
};

#if __cplusplus >= 201703L
namespace detail
{

template <class C, typename S = index_sequence<>, typename overload = void>
struct aggregate_size_implementation : S {};

template <class C, std::size_t... I>
struct aggregate_size_implementation<C, index_sequence<I...>,
    SFVOID(C{ declval<dummy_type>(), declval<dummy_type, I>()... })>
    : aggregate_size_implementation<C, index_sequence<I..., sizeof...(I)>> {};

} // namespace detail

template <class T, bool condition = std::is_aggregate<T>::value>
struct aggregate_size
{
    static constexpr auto value = detail::aggregate_size_implementation<T>::size();
};

template <class T>
struct aggregate_size<T, false>
{
    static constexpr auto value = 0;
};

#endif // if

namespace detail
{

template <class T, typename enable = void>
struct object_value_type
{
    using type = dummy_type;
};

template <class T>
struct object_value_type<T, to_void<typename T::value_type>>
{
    using type = typename T::value_type;
};

template <typename T>
struct array_value_type
{
    using type = dummy_type;
};

template <typename T>
struct array_value_type<T[]>
{
    using type = T;
};

template <typename T, std::size_t N>
struct array_value_type<T[N]>
{
    using type = T;
};

template <typename T, typename enable = void>
struct value_type_implementation
{
    using type = dummy_type;
};

template <typename T>
struct value_type_implementation<T, when<std::is_class<T>::value>>
{
    using type = typename object_value_type<T>::type;
};

template <typename T>
struct value_type_implementation<T, when<std::is_array<T>::value>>
{
    using type = typename array_value_type<T>::type;
};

} // namespace detail

template <typename T>
using value_type = typename detail::value_type_implementation<T>::type;

namespace detail
{

template <std::size_t I, typename... Bn> struct with_implementation : dispatch<I> {};

template <std::size_t I, typename B, typename... Bn> struct with_implementation<I, B, Bn...>
    : conditional<bool(B::value), with_implementation<I>, with_implementation<I + 1, Bn...>> {};

} // namespace detail

template <typename... Bn> struct with : detail::with_implementation<0, Bn...> {};

template <typename From, typename To> struct is_cast_allowed
    : one<can_static_cast<From, To>, std::is_convertible<From, To>> {};

namespace detail
{

template <typename> struct is_character_implementation : std::false_type {};

template <> struct is_character_implementation<char> : std::true_type {};
template <> struct is_character_implementation<signed char> : std::true_type {};
template <> struct is_character_implementation<unsigned char> : std::true_type {};

template <> struct is_character_implementation<wchar_t> : std::true_type {};
template <> struct is_character_implementation<char16_t> : std::true_type {};
template <> struct is_character_implementation<char32_t> : std::true_type {};

} // namespace detail

template <typename T>
struct is_character : detail::is_character_implementation<typename std::remove_cv<T>::type> {};

template <class T> struct is_compressible : std::is_arithmetic<value_type<T>> {};

template <class Derived, class Base, class... Base_n> struct is_derived_of
    : all<std::is_base_of<Base, Derived>,
          std::is_base_of<Base_n, Derived>...> {};

template <typename T> struct is_void : std::is_same<T, void> {};

template <typename> struct is_std_shared_ptr : std::false_type {};
template <typename T>
struct is_std_shared_ptr<std::shared_ptr<T>> : std::true_type {};

template <typename> struct is_std_array : std::false_type {};
template <typename T, std::size_t N>
struct is_std_array<std::array<T, N>> : std::true_type {};

template <typename T> struct is_shared_pointer : is_std_shared_ptr<T> {};
template <typename T> struct is_raw_pointer : std::is_pointer<T> {};

template <typename T> struct is_pointer : one<is_shared_pointer<T>, is_raw_pointer<T>> {};

template <typename T> struct is_pointer_to_polymorphic
    : all<is_pointer<T>, std::is_polymorphic<dereference<T>>> {};

template <typename T> struct is_void_pointer : all<is_pointer<T>, is_void<dereference<T>>> {};
template <typename T> struct is_null_pointer : std::is_same<T, std::nullptr_t> {};

template <typename> struct is_function_pointer : std::false_type {};
template <typename Ret, typename... Args>
struct is_function_pointer<Ret (*)(Args...)> : std::true_type {};

template <typename T> struct is_pointer_to_standard_layout :
    all<is_pointer<T>,
        negation<is_void_pointer<T>>,
        negation<is_pointer_to_polymorphic<T>>,
        negation<is_function_pointer<T>>,
        negation<is_null_pointer<T>>,
        negation<std::is_member_pointer<T>>> {};

template <typename T> struct is_serializable_pointer
    : one<is_pointer_to_standard_layout<T>, is_pointer_to_polymorphic<T>> {};

template <typename T> struct is_serializable_raw_pointer
    : all<is_raw_pointer<T>, is_serializable_pointer<T>> {};

template <typename T> struct is_serializable_shared_pointer
    : all<is_shared_pointer<T>, is_serializable_pointer<T>> {};

#if __cplusplus >= 201703L
template <typename T> struct is_aggregate
    : all<std::is_aggregate<T>, negation<is_std_array<T>>, negation<std::is_array<T>>> {};
#endif // if

template <typename T> struct is_unsupported :
    one<is_void_pointer<T>,
        is_function_pointer<T>,
        is_null_pointer<T>,
        std::is_function<T>,
        std::is_member_function_pointer<T>,
        std::is_member_object_pointer<T>,
        std::is_reference<T>> {};

} // namespace meta

} // namespace sf

#define CONDITIONAL_TYPE_REGISTRY(...)                                                                  \
    namespace sf { namespace core {                                                                     \
        template <typename T> struct TypeRegistry<T, SFWHEN(__VA_ARGS__)> : std::true_type {};          \
    }}

// you should use TYPE_REGISTRY before using EXTERN_SERIALIZATION e.t.
#define TYPE_REGISTRY(...)                                                                              \
    namespace sf { namespace core {                                                                     \
        template <> struct TypeRegistry<__VA_ARGS__> : std::true_type {};                               \
    }}

namespace sf
{

namespace core
{

template <typename T, typename enable = void>
struct TypeRegistry : std::false_type {};

} // namespace core

namespace meta
{

template <typename T> struct is_registered : core::TypeRegistry<T> {};

// use this function only for extern type registry check
template <typename T> struct is_registered_extern
#ifdef SF_TYPE_REGISTRY_DISABLE
    : std::true_type {};
#else
    : is_registered<T> {};
#endif // SF_TYPE_REGISTRY_DISABLE

template <typename T> struct is_serializable : all<negation<is_unsupported<T>>, is_registered<T>> {};

} // namespace meta

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_unsupported<T>::value)

namespace sf
{

namespace core
{

class IOArchive;

struct IArchiveType {};
struct OArchiveType {};

} // namespace core

namespace meta
{

template <class T> struct is_iarchive : std::is_base_of<core::IArchiveType, T> {};
template <class T> struct is_oarchive : std::is_base_of<core::OArchiveType, T> {};

template <class T> struct is_ioarchive : one<is_iarchive<T>, is_oarchive<T>> {};

template <class T> struct is_archive : std::is_base_of<core::IOArchive, T> {};

} // namespace meta

} // namespace sf

namespace sf
{

namespace let
{

using i8 = std::int8_t;
using u8 = std::uint8_t;

using i32 = std::int32_t;
using u32 = std::uint32_t;

using i64 = std::int64_t;
using u64 = std::uint64_t;

} // namespace let

} // namespace sf

#ifndef SF_ARCHIVE_TRAIT_MAX_KEY_SIZE
    #define SF_ARCHIVE_TRAIT_MAX_KEY_SIZE 4
#endif // SF_ARCHIVE_MAX_TRAIT_KEY

#define SERIALIZATION_ARCHIVE(...)                                                                      \
    virtual key_type trait() const noexcept override {                                                  \
        return ::sf::core::ArchiveTraitKey<__VA_ARGS__>::key;                                           \
    }

namespace sf
{

namespace core
{

struct ArchiveTrait
{
    using key_type = let::u8;

    static constexpr auto base_key = key_type(-1);
    static constexpr auto max_key = key_type(SF_ARCHIVE_TRAIT_MAX_KEY_SIZE);
};

template <class Archive> struct ArchiveTraitKey
{
    static constexpr auto key = ArchiveTrait::base_key;
};

class IOArchive
{
public:
    using key_type = ArchiveTrait::key_type;

protected:
    virtual ~IOArchive() = default;

public:
    virtual key_type trait() const noexcept
    {
        return ArchiveTraitKey<IOArchive>::key;
    }
};

} // namespace core

} // namespace sf

#include <typeinfo> // type_info

#ifndef SF_STATIC_HASH_KEY_TYPE
    #define SF_STATIC_HASH_KEY_TYPE ::sf::let::u64
#endif // SF_STATIC_HASH_KEY_TYPE

#ifndef SF_STATIC_HASH
    #define SF_STATIC_HASH(string) ::sf::static_hash<SF_STATIC_HASH_KEY_TYPE>((string))
#endif // SF_STATIC_HASH

#ifndef SF_TYPE_HASH
    #define SF_TYPE_HASH(type_info) ::sf::type_hash(type_info)
#endif // SF_TYPE_HASH

namespace sf
{

namespace detail
{

enum class Word { x32, x64 }; // word size: x* - number of bits

template <Word word> struct word_type_implementation;

template <> struct word_type_implementation<Word::x32> { using type = let::u32; };
template <> struct word_type_implementation<Word::x64> { using type = let::u64; };

template <Word word>
using WordType = typename detail::word_type_implementation<word>::type;

template <typename T> struct WordTrait { static constexpr auto value = Word::x64; };

template <> struct WordTrait<let::u32> { static constexpr auto value = Word::x32; };
template <> struct WordTrait<let::u64> { static constexpr auto value = Word::x64; };

template <typename HashType, HashType FnvPrime, HashType OffsetBasis>
HashType fnv_1a(const char* text)
{
    auto hash = OffsetBasis;
    while (*text != '\0')
    {
        hash ^= *text;
        hash *= FnvPrime;

        ++text;
    }

    return hash;
}

template <typename HashType, HashType FnvPrime, HashType OffsetBasis>
constexpr HashType static_fnv_1a(const char* text, HashType hash = OffsetBasis) noexcept
{
    return (*text == '\0')
           ? hash
           : static_fnv_1a<HashType, FnvPrime, OffsetBasis>(text + 1, (hash ^ (*text)) * FnvPrime);
}

template <detail::Word word>
struct Hash;

template <>
struct Hash<detail::Word::x32>
{
private:
    // For 32 bit machines:
    static constexpr let::u32 fnv_prime        = 16777619ull;
    static constexpr let::u32 fnv_offset_basis = 2166136261ull;

public:
    static let::u32 run(const char* text)
    {
        return detail::fnv_1a<let::u32, fnv_prime, fnv_offset_basis>(text);
    }

    static constexpr let::u32 static_run(const char* text) noexcept
    {
        return detail::static_fnv_1a<let::u32, fnv_prime, fnv_offset_basis>(text);
    }
};

template <>
struct Hash<detail::Word::x64>
{
private:
    // For 64 bit machines:
    static constexpr let::u64 fnv_prime        = 1099511628211ull;
    static constexpr let::u64 fnv_offset_basis = 14695981039346656037ull;

public:
    static let::u64 run(const char* text)
    {
        return detail::fnv_1a<let::u64, fnv_prime, fnv_offset_basis>(text);
    }

    static constexpr let::u64 static_run(const char* text) noexcept
    {
        return detail::static_fnv_1a<let::u64, fnv_prime, fnv_offset_basis>(text);
    }
};

} // namespace detail

template <typename key_type = let::u64>
inline key_type hash(const char* text)
{
    using detail::Hash;
    using detail::WordTrait;

    return Hash<detail::WordTrait<key_type>::value>::run(text);
}

template <typename key_type = let::u64>
constexpr key_type static_hash(const char* text) noexcept
{
    using detail::Hash;
    using detail::WordTrait;

    return Hash<detail::WordTrait<key_type>::value>::static_run(text);
}

inline std::size_t type_hash(const std::type_info& type) noexcept
{
    // not portable implementation - will be changed
    return type.hash_code();
}

namespace detail
{

template <typename HashType, typename T>
inline void hash_combine(HashType& seed, const T& object) noexcept
{
    auto hash = std::hash<T>{}(object) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    seed ^= static_cast<HashType>(hash);
}

} // namespace detail

} // namepace sf

#define EXPORT_INSTANTIABLE_KEY(unique_name, ...)                                                       \
    namespace sf { namespace core {                                                                     \
        template <> struct InstantiableTraitKey<__VA_ARGS__> {                                          \
            static constexpr auto key = SF_STATIC_HASH(unique_name);                                    \
        };                                                                                              \
    }}

#define EXPORT_INSTANTIABLE(...)                                                                        \
    EXPORT_INSTANTIABLE_KEY(#__VA_ARGS__, __VA_ARGS__)

namespace sf
{

namespace core
{

struct InstantiableTrait
{
    using key_type = SF_STATIC_HASH_KEY_TYPE;
    
    static constexpr auto base_key = key_type(-1);
};

template <class T>
struct InstantiableTraitKey
{
    static constexpr auto key = InstantiableTrait::base_key;
};

} // namespace core

} // namespace sf

#define SERIALIZATION(mode, ...)                                                                        \
    template <>                                                                                         \
    struct Serialization::mode<__VA_ARGS__> {                                                           \
        template <class Archive> mode(Archive&, __VA_ARGS__&);                                          \
    };                                                                                                  \
    template <class Archive>                                                                            \
    Serialization::mode<__VA_ARGS__>::mode(Archive& archive, __VA_ARGS__& self)

#define CONDITIONAL_SERIALIZATION(mode, ...)                                                            \
    template <class T>                                                                                  \
    struct Serialization::mode<T, SFWHEN(__VA_ARGS__)> {                                                \
        template <class Archive> mode(Archive&, T&);                                                    \
    };                                                                                                  \
    template <class T> template <class Archive>                                                         \
    Serialization::mode<T, SFWHEN(__VA_ARGS__)>::mode(Archive& archive, T& self)

// Allow to hide implementationementation to translation unit, and declare interface in header
#define SERIALIZATION_INTERFACE(mode, ...)                                                              \
    template <>                                                                                         \
    struct Serialization::mode<__VA_ARGS__> {                                                           \
        mode(::sf::core::IOArchive&, __VA_ARGS__&);                                                     \
    };

#define SERIALIZATION_IMPLEMENTATION(mode, ...)                                                         \
    Serialization::mode<__VA_ARGS__>::mode(::sf::core::IOArchive& archive, __VA_ARGS__& self)

// should be in global namespace
class Serialization
{
public:
    template <class T, typename enable = void> struct SaveLoad;
    template <class T, typename enable = void> struct Save;
    template <class T, typename enable = void> struct Load;

public:
    template <class T> struct is_save_class : sf::meta::is_complete<Save<T>> {};
    template <class T> struct is_load_class : sf::meta::is_complete<Load<T>> {};
    template <class T> struct is_saveload_class : sf::meta::is_complete<SaveLoad<T>> {};

public:
    template <class T> struct has_save_mode : sf::meta::one<is_save_class<T>, is_saveload_class<T>> {};
    template <class T> struct has_load_mode : sf::meta::one<is_load_class<T>, is_saveload_class<T>> {};

public:
    template <class Archive, class T> static void call(Archive& archive, T& self)
    {
        throw "The 'T' type cannot be saved/loaded."; // default implementation
    }

private:
    template <class T>
    struct SaveModeMeta
    {
        static constexpr auto index = sf::meta::with<is_save_class<T>, is_saveload_class<T>>::value;

        using mode_array = sf::meta::type_array<Save<T>, SaveLoad<T>, Serialization>;
        using mode = typename mode_array::template type<index>;
    };

    template <class T>
    struct LoadModeMeta
    {
        static constexpr auto index = sf::meta::with<is_load_class<T>, is_saveload_class<T>>::value;

        using mode_array = sf::meta::type_array<Load<T>, SaveLoad<T>, Serialization>;
        using mode = typename mode_array::template type<index>;
    };

public:
    template <class T> using SaveMode = typename SaveModeMeta<T>::mode;
    template <class T> using LoadMode = typename LoadModeMeta<T>::mode;

public:
    template <class T, typename = void> struct has_static_trait : std::false_type {};
    template <class T> struct has_static_trait<T, SFVOID(&T::__static_trait)> : std::true_type {};

    template <class T, typename = void> struct has_trait : std::false_type {};
    template <class T> struct has_trait<T, SFVOID(&T::__trait)> : std::true_type {};

public:
    template <class T> struct has_inner_trait
    {
        static constexpr bool value = has_static_trait<T>::value and has_trait<T>::value; // delay access
    };

private:
    template <typename From, typename To, typename = void> struct can_static_cast : std::false_type {};
    template <typename From, typename To>
    struct can_static_cast<From, To, SFVOID(static_cast<To>(std::declval<From>()))> : std::true_type {};

    template <typename From, typename To, typename = void> struct can_cast : std::false_type {};
    template <typename From, typename To>
    struct can_cast<From, To, SFVOID(std::declval<void(&)(To)>()(std::declval<From>()))> : std::true_type {};

    template <typename T, typename = void> struct is_returnable : std::false_type {};
    template <typename T>
    struct is_returnable<T, SFVOID(static_cast<T(*)()>(nullptr))> : std::true_type {};

public:
    template <class From, class To> struct is_cast_allowed
        : sf::meta::one<sf::meta::all<is_returnable<To>, can_cast<From, To>>,
                        sf::meta::is_same<void, From, To>> {};

    template <class From, class To> struct is_pointer_cast_allowed
        : sf::meta::one<is_cast_allowed<From*, To*>, sf::meta::is_void<From>> {};

public:
    template <class Base, class Derived> struct is_virtual_base_of
        : sf::meta::all<std::is_base_of<Base, Derived>,
                        sf::meta::negation<can_static_cast<Base*, Derived*>>> {};

public:
    using IOArchive = sf::core::IOArchive;
    using InstantiableTrait = sf::core::InstantiableTrait;

public:
    template <typename Archive, class T>
    static void save(Archive& archive, T& data)
    {
        SaveMode<T>(archive, data);
    }

    template <typename Archive, class T>
    static void load(Archive& archive, T& data)
    {
        LoadMode<T>(archive, data);
    }

    template <typename Base, class Archive, class Derived,
              SFREQUIRE(sf::meta::all<sf::meta::is_ioarchive<Archive>,
                                      std::is_base_of<Base, Derived>>::value)>
    static void serialize_base(Archive& archive, Derived& object)
    {
        archive & static_cast<Base&>(object);
    }

    template <class T, SFREQUIRE(not has_inner_trait<T>::value)>
    static InstantiableTrait::key_type trait(T& object)
    {
    #ifdef SF_EXTERN_RUNTIME_TRAIT
        return SF_EXTERN_RUNTIME_TRAIT(object);
    #else
        return SF_TYPE_HASH(typeid(object));
    #endif // SF_EXTERN_RUNTIME_TRAIT
    }

    template <class T, SFREQUIRE(has_inner_trait<T>::value)>
    static InstantiableTrait::key_type trait(T& object) noexcept
    {
        return object.__trait();
    }

    template <class T, SFREQUIRE(not has_inner_trait<T>::value)>
    static InstantiableTrait::key_type static_trait() noexcept
    {
    #ifdef SF_EXTERN_TRAIT
        return SF_EXTERN_TRAIT(T);
    #else
        return SF_TYPE_HASH(typeid(T));
    #endif // SF_EXTERN_TRAIT
    }

    template <class T, SFREQUIRE(has_inner_trait<T>::value)>
    static constexpr InstantiableTrait::key_type static_trait() noexcept
    {
        return T::__static_trait();
    }

    template <class T, SFREQUIRE(not has_inner_trait<T>::value)>
    static InstantiableTrait::key_type trait() noexcept
    {
        constexpr auto trait_key = sf::core::InstantiableTraitKey<T>::key;

        static_assert(trait_key == InstantiableTrait::base_key,
            "Export instantiable trait is not allowed using typeid.");

        return static_trait<T>();
    }

    template <class T, SFREQUIRE(has_inner_trait<T>::value)>
#ifdef SF_EXPORT_INSTANTIABLE_DISABLE
    static constexpr InstantiableTraitBase::key_type trait() noexcept
#else
    static InstantiableTrait::key_type trait() noexcept
#endif // SF_EXPORT_INSTANTIABLE_DISABLE
    {
        constexpr auto trait_key = sf::core::InstantiableTraitKey<T>::key;

        return trait_key == InstantiableTrait::base_key
             ? static_trait<T>()
             : trait_key;
    }
};

#include <unordered_map> // unordered_map

// You can include given file to other dir level

namespace sf
{

namespace meta
{

template <typename T> struct is_memory_shared : std::is_same<T, shared_type> {};
template <typename T> struct is_memory_raw : std::is_same<T, raw_type> {};

template <typename T> struct is_memory : one<is_memory_shared<T>, is_memory_raw<T>> {};

} // namespace meta

class Memory
{
public:
    using Shared = meta::shared_type;
    using Raw = meta::raw_type;

    template <typename T>
    using shared_ptr = std::shared_ptr<T>;

    template <typename T>
    using raw_ptr = T*;

public:
    template <typename T>
    struct ptr_trait
    {
        using item = std::nullptr_t;
    };

    template <typename T>
    struct ptr_trait<std::shared_ptr<T>>
    {
        using trait    = Shared;

        template <typename U>
        using wrapper  = shared_ptr<U>;

        using type     = std::shared_ptr<T>;
        using item     = T;

        using void_ptr = std::shared_ptr<void>;
    };

    template <typename T>
    struct ptr_trait<T*>
    {
        using trait    = Raw;

        template <typename U>
        using wrapper  = raw_ptr<U>;

        using type     = T*;
        using item     = T;

        using void_ptr = void*;
    };

    template <typename T>
    struct ptr_trait<std::weak_ptr<T>>
    {
        using type     = std::weak_ptr<T>;
        using item     = T;
    };

    template <typename T>
    struct ptr_trait<std::unique_ptr<T>>
    {
        using type     = std::unique_ptr<T>;
        using item     = T;
    };

public:
    template <typename T>
    using void_ptr = typename ptr_trait<T>::void_ptr;

public:
    template <typename T>
    struct Factory
    {
        static std::shared_ptr<T> shared()
        {
            return std::make_shared<T>();
        }

        static T* raw()
        {
            return new T{};
        }
    };

private:
    template <class From, class To> struct is_pointer_cast_allowed
        : ::Serialization::is_pointer_cast_allowed<From, To> {};

public:
    template <typename To, typename T,
              SFREQUIRE(meta::is_shared_pointer<T>::value)>
    static shared_ptr<To> dynamic_pointer_cast(const T& pointer)
    {
        auto address = dynamic_pointer_cast<To>(pointer.get());
        return address == nullptr ? shared_ptr<To>() : shared_ptr<To>(pointer, address);
    }

    template <typename To, typename T,
              SFREQUIRE(meta::is_raw_pointer<T>::value)>
    static raw_ptr<To> dynamic_pointer_cast(const T& pointer)
    {
        return dynamic_cast<raw_ptr<To>>(pointer);
    }

    template <typename To, typename T,
              typename Trait = ptr_trait<T>,
              SFREQUIRE(meta::one<meta::is_null_pointer<T>,
                                  meta::all<meta::is_pointer<T>,
                                            meta::negation<is_pointer_cast_allowed<typename Trait::item, To>>>>::value)>
    static typename Trait::template wrapper<To> static_pointer_cast(const T& pointer) noexcept
    {
        return nullptr;
    }

    template <typename To, typename T,
              SFREQUIRE(meta::all<meta::is_shared_pointer<T>,
                                  is_pointer_cast_allowed<typename ptr_trait<T>::item, To>>::value)>
    static shared_ptr<To> static_pointer_cast(const T& pointer) noexcept
    {
        auto address = static_pointer_cast<To>(pointer.get());
        return shared_ptr<To>(pointer, address);
    }

    template <typename To, typename T,
              SFREQUIRE(meta::all<meta::is_raw_pointer<T>,
                                  is_pointer_cast_allowed<typename ptr_trait<T>::item, To>>::value)>
    static raw_ptr<To> static_pointer_cast(const T& pointer) noexcept
    {
        return static_cast<raw_ptr<To>>(pointer);
    }

    template <typename To, typename From, typename T,
              typename Trait = ptr_trait<T>,
              SFREQUIRE(meta::all<meta::is_pointer<T>,
                                  meta::negation<is_pointer_cast_allowed<From, To>>>::value)>
    static typename Trait::template wrapper<To> static_pointer_cast(const T& pointer) noexcept
    {
        return nullptr;
    }

    template <typename To, typename From, typename T,
              typename Trait = ptr_trait<T>,
              SFREQUIRE(meta::all<meta::is_pointer<T>,
                                  is_pointer_cast_allowed<typename Trait::item, From>,
                                  is_pointer_cast_allowed<From, To>>::value)>
    static typename Trait::template wrapper<To> static_pointer_cast(const T& pointer) noexcept
    {
        return static_pointer_cast<To>(static_pointer_cast<From>(pointer));
    }

public:
    template <typename T,
              SFREQUIRE(meta::all<meta::is_pointer<T>,
                                  meta::negation<meta::is_pointer_to_polymorphic<T>>>::value)>
    static void_ptr<T> pure(const T& pointer) noexcept
    {
        return static_pointer_cast<void>(pointer);
    }

    template <typename T,
              SFREQUIRE(meta::all<meta::is_pointer<T>,
                                  meta::is_pointer_to_polymorphic<T>>::value)>
    static void_ptr<T> pure(const T& pointer_to_polymorphic)
    {
        return dynamic_pointer_cast<void>(pointer_to_polymorphic);
    }

    static raw_ptr<void> pure(std::nullptr_t pointer) noexcept { return nullptr; }

    template <typename dT, typename T,
              SFREQUIRE(meta::is_pointer<T>::value)>
    static void assign(T& pointer, const void_ptr<T>& address) noexcept
    {
        pointer = static_pointer_cast<dT>(address);
    }

public:
    template <typename To, typename From = To, typename TraitType,
              SFREQUIRE(meta::all<meta::is_memory<TraitType>,
                                  meta::one<meta::negation<is_pointer_cast_allowed<From, To>>,
                                            std::is_abstract<From>>>::value)>
    static std::nullptr_t allocate() noexcept
    {
        return nullptr;
    }

    template <typename To, typename From = To, typename TraitType,
              SFREQUIRE(meta::all<meta::negation<std::is_abstract<From>>,
                                  meta::is_memory_shared<TraitType>,
                                  is_pointer_cast_allowed<From, To>>::value)>
    static shared_ptr<To> allocate()
    {
        auto instance = Factory<From>::shared();
        return static_pointer_cast<To>(instance);
    }

    template <typename To, typename From = To, typename TraitType,
              SFREQUIRE(meta::all<meta::negation<std::is_abstract<From>>,
                                  meta::is_memory_raw<TraitType>,
                                  is_pointer_cast_allowed<From, To>>::value)>
    static raw_ptr<To> allocate()
    {
        auto instance = Factory<From>::raw();
        return static_pointer_cast<To>(instance);
    }

    template <typename To, typename From = To>
    static shared_ptr<To> allocate_shared()
    {
        return allocate<To, From, Shared>();
    }

    template <typename To, typename From = To>
    static raw_ptr<To> allocate_raw()
    {
        return allocate<To, From, Raw>();
    }

    template <typename To, typename From = To, typename T,
              SFREQUIRE(meta::is_pointer<T>::value)>
    static void allocate(T& pointer)
    {
        pointer = allocate<To, From, typename ptr_trait<T>::trait>();
    }

public:
    template <typename T, typename dT = typename ptr_trait<T>::item,
              SFREQUIRE(meta::is_raw_pointer<T>::value)>
    static raw_ptr<dT> raw(const T& pointer) { return pointer; }

    template <typename T, typename dT = typename ptr_trait<T>::item,
              SFREQUIRE(meta::is_shared_pointer<T>::value)>
    static raw_ptr<dT> raw(const T& pointer) { return pointer.get(); }

public:
    template <typename ByteType = char, typename T>
    static const ByteType* const_byte_cast(T* data) noexcept
    {
        return reinterpret_cast<const ByteType*>(data);
    }

    template <typename ByteType = char, typename T>
    static ByteType* byte_cast(T* data) noexcept
    {
        return reinterpret_cast<ByteType*>(data);
    }
};

} // namespace sf

#define EXPORT_SERIALIZATION_ARCHIVE(archive_key, archive_type, ...)                                    \
    namespace sf { namespace core {                                                                     \
        template <> struct ArchiveTraitKey<__VA_ARGS__> {                                               \
            static constexpr IOArchive::key_type key = archive_key;                                     \
        };                                                                                              \
        template <> struct archive_type##ArchiveTrait<ArchiveTraitKey<__VA_ARGS__>::key> {              \
            using type = __VA_ARGS__;                                                                   \
        };                                                                                              \
    }}

namespace sf
{

namespace core
{

template <IOArchive::key_type I> struct IArchiveTrait { using type = IOArchive; };
template <IOArchive::key_type I> struct OArchiveTrait { using type = IOArchive; };

} // namespace core

} // namespace sf

namespace sf
{

namespace core
{

class PolymorphicArchive
{
public:
    using Archive  = IOArchive;
    using key_type = IOArchive::key_type;

    static constexpr key_type max_key = ArchiveTrait::max_key;

public:
    template <class T> static void save(Archive& archive, T& data)
    {
        call<OArchiveTrait>(archive, data);
    }

    template <class T> static void load(Archive& archive, T& data)
    {
        call<IArchiveTrait>(archive, data);
    }

private:
    template <class Archive> struct is_valid_archive
        : meta::boolean<ArchiveTraitKey<Archive>::key != ArchiveTrait::base_key> {};

private:
    template <template <key_type> class ArchiveTrait,
              key_type Key, class T, SFREQUIRE(Key == max_key)>
    static void call(Archive& archive, T& data)
    {
        throw "The read/write archive has invalid type key.";
    }

    template <template <key_type> class ArchiveTrait,
              key_type Key = 0, class T, SFREQUIRE(Key < max_key)>
    static void call(Archive& archive, T& data)
    {
        using DerivedArchive = typename ArchiveTrait<Key>::type;

        if (ArchiveTraitKey<DerivedArchive>::key == archive.trait())
            return try_call<DerivedArchive>(archive, data);

        call<ArchiveTrait, Key + 1>(archive, data);
    }

    template <class DerivedArchive, class T,
              SFREQUIRE(not is_valid_archive<DerivedArchive>::value)>
    static void try_call(Archive& archive, T& data)
    {
        throw "The read/write archive was not registered.";
    }

    template <class DerivedArchive, class T,
              SFREQUIRE(is_valid_archive<DerivedArchive>::value)>
    static void try_call(Archive& archive, T& data)
    {
        auto derived_archive = dynamic_cast<DerivedArchive*>(&archive);

    #ifdef SF_DEBUG
        if (derived_archive == nullptr)
            throw "The read/write archive was registered incorrect.";
    #endif // SF_DEBUG

        proccess(*derived_archive, data);
    }

    template <class DerivedArchive, class T,
              SFREQUIRE(meta::all<meta::is_oarchive<DerivedArchive>,
                                  ::Serialization::has_save_mode<T>>::value)>
    static void proccess(DerivedArchive& archive, T& object)
    {
        ::Serialization::save(archive, object);
    }

    template <class DerivedArchive, class T,
              SFREQUIRE(meta::all<meta::is_iarchive<DerivedArchive>,
                                  ::Serialization::has_load_mode<T>>::value)>
    static void proccess(DerivedArchive& archive, T& object)
    {
        ::Serialization::load(archive, object);
    }

    template <class DerivedArchive, class T,
              SFREQUIRE(meta::all<meta::is_ioarchive<DerivedArchive>,
                                  meta::negation<::Serialization::has_save_mode<T>>,
                                  meta::negation<::Serialization::has_load_mode<T>>>::value)>
    static void proccess(DerivedArchive& archive, T& data)
    {
        process_data(archive, data);
    }

    template <class DerivedArchive, class T,
              SFREQUIRE(meta::is_registered<T>::value)>
    static void process_data(DerivedArchive& archive, T& data)
    {
        archive & data;
    }

    template <class DerivedArchive, class T,
              SFREQUIRE(not meta::is_registered<T>::value)>
    static void process_data(DerivedArchive& archive, T& data)
    {
        throw "The 'T' type is unregistered.";
    }
};

template <class Archive, typename T,
          SFREQUIRE(meta::is_archive<Archive>::value)>
Archive& operator<< (Archive& archive, T&& data)
{
    PolymorphicArchive::save(archive, data);
    return archive;
}

template <class Archive, typename T,
          SFREQUIRE(meta::is_archive<Archive>::value)>
Archive& operator>> (Archive& archive, T&& data)
{
    PolymorphicArchive::load(archive, data);
    return archive;
}

} // namespace core

} // namespace sf

// By default library will use Instantiable type for general instancing,
// if you want to specify behaviour, just define own INSTANTIABLE_TYPE
// Note that: any defined INSTANTIABLE_TYPE must have virtual destructor
#ifndef INSTANTIABLE_TYPE
    #define INSTANTIABLE_TYPE ::sf::Instantiable
#endif // INSTANTIABLE_TYPE

namespace sf
{

struct Instantiable { virtual ~Instantiable() = default; };

} // namespace sf

// Auto instantiable type registration
#define SERIALIZATION_FIXTURE(...)                                                                      \
    private:                                                                                            \
    ::sf::dynamic::InstantiableFixture<__VA_ARGS__> __fixture;                                          \
    public:

#define SERIALIZATION_TRAIT(...)                                                                        \
    private:                                                                                            \
    using __key_type = ::sf::core::InstantiableTrait::key_type;                                         \
    static constexpr __key_type __static_trait() noexcept { return SF_STATIC_HASH(#__VA_ARGS__); }      \
    virtual __key_type __trait() const noexcept { return ::Serialization::trait<__VA_ARGS__>(); }       \
    public:

namespace sf
{

namespace dynamic
{

class InstantiableRegistry
{
public:
    using key_type          = core::InstantiableTrait::key_type;
    using instantiable_type = INSTANTIABLE_TYPE;
    using archive_type      = core::IOArchive;

private:
    template <typename ItemType>
    using InnerTable = std::unordered_map<key_type, ItemType>;

private:
    struct InstantiableProxy
    {
        instantiable_type* __instance = nullptr;

        std::shared_ptr<instantiable_type>(*__shared)() = nullptr;
        std::shared_ptr<instantiable_type>(*__cast_shared)(std::shared_ptr<void>) = nullptr;

        instantiable_type*(*__raw)() = nullptr;
        instantiable_type*(*__cast_raw)(void*) = nullptr;

        void(*__save)(archive_type&, instantiable_type*) = nullptr;
        void(*__load)(archive_type&, instantiable_type*) = nullptr;
    };

private:
    InnerTable<InstantiableProxy> registry_;

private:

    InstantiableRegistry() : registry_() {}

    ~InstantiableRegistry()
    {
        for (const auto& pair : registry_) delete pair.second.__instance;
    }

    InstantiableRegistry(const InstantiableRegistry&) = delete;
    InstantiableRegistry& operator=(const InstantiableRegistry&) = delete;

public:
    static InstantiableRegistry& instance() noexcept
    {
        static InstantiableRegistry self;
        return self;
    }

public:
    // we should use external check
    template <typename dT> struct is_instantiable : meta::is_cast_allowed<dT*, instantiable_type*> {};

public:
    template <class T, SFREQUIRE(not is_instantiable<T>::value)>
    void update(key_type key)
    {
        throw "The polymorphic 'T' type is not convertible to 'Instantiable'.";
    }

    template <class T, SFREQUIRE(is_instantiable<T>::value)>
    void update(key_type key)
    {
        if (is_registered(key)) return;

        InstantiableProxy proxy;

        proxy.__instance = Memory::allocate_raw<instantiable_type, T>();

        proxy.__shared = [] { return Memory::allocate_shared<instantiable_type, T>(); };

        proxy.__cast_shared = [](std::shared_ptr<void> address)
        {
            return Memory::static_pointer_cast<instantiable_type, T>(address);
        };

        proxy.__raw = [] { return Memory::allocate_raw<instantiable_type, T>(); };

        proxy.__cast_raw = [](void* address)
        {
            return Memory::static_pointer_cast<instantiable_type, T>(address);
        };

        proxy.__save = [](archive_type& archive, instantiable_type* instance)
        {
            archive << *Memory::dynamic_pointer_cast<T>(instance);
        };

        proxy.__load = [](archive_type& archive, instantiable_type* instance)
        {
            archive >> *Memory::dynamic_pointer_cast<T>(instance);
        };

        registry_.emplace(key, proxy);
    }

    template <typename TraitType,
              SFREQUIRE(meta::is_memory_shared<TraitType>::value)>
    std::shared_ptr<instantiable_type> clone(key_type key)
    {
        return registry(key).__shared();
    }

    template <typename TraitType,
              SFREQUIRE(meta::is_memory_raw<TraitType>::value)>
    instantiable_type* clone(key_type key)
    {
        return registry(key).__raw();
    }

    std::shared_ptr<instantiable_type> cast(std::shared_ptr<void> address, key_type key)
    {
        return registry(key).__cast_shared(address);
    }

    instantiable_type* cast(void* address, key_type key)
    {
        return registry(key).__cast_raw(address);
    }

    template <typename Pointer, typename T = sf::meta::dereference<Pointer>,
              SFREQUIRE(::Serialization::has_save_mode<T>::value)>
    void save(archive_type& archive, Pointer& pointer)
    {
        auto key = ::Serialization::trait(*pointer);
        registry(key).__save(archive, pointer);
    }

    template <typename Pointer, typename T = sf::meta::dereference<Pointer>,
              SFREQUIRE(::Serialization::has_load_mode<T>::value)>
    void load(archive_type& archive, Pointer& pointer)
    {
        auto key = ::Serialization::trait(*pointer);
        registry(key).__load(archive, pointer);
    }

public:
    bool is_registered(key_type key)
    {
        return registry_.find(key) != registry_.end();
    }

#ifndef SF_REGISTRY_ACCESS
private:
#endif // SF_REGISTRY_ACCESS
    InstantiableProxy& registry(key_type key)
    {
        // It happens if the class with the given key has not beed public inherited
        // from the instantiable class or not registered with fixture object.
        auto it = registry_.find(key);
        if (it == registry_.end())
            throw "The 'sf::dynamic::InstantiableRegistry' does not has instance with input key.";

        return it->second;
    }
};

template <class T>
class InstantiableFixture
{
private:
    static bool lock_;

public:
    InstantiableFixture() { call<T>(); }

public:
    template <typename dT = T,
              SFREQUIRE(InstantiableRegistry::is_instantiable<dT>::value)>
    static void call()
    {
        if (lock_) return;
        lock_ = true; // lock before creating clone instance to prevent recursive call

        auto& registry = InstantiableRegistry::instance();

        auto key = ::Serialization::template trait<T>();
    #ifdef SF_DEBUG
        if (registry.is_registered(key))
            throw "The 'sf::dynamic::InstantiableRegistry' must contains instance with unique key.";
    #endif // SF_DEBUG

        registry.update<T>(key);
    }

    template <typename dT = T,
              SFREQUIRE(not InstantiableRegistry::is_instantiable<dT>::value)>
    static void call() noexcept { /*pass*/ }
};

template <class T>
bool InstantiableFixture<T>::lock_ = false;

} // namespace dynamic

} // namespace sf

#if __cplusplus >= 201703L && !defined(SF_ANY_SUPPORT_DISABLE)

namespace sf
{

namespace dynamic
{

class AnyRegistry
{
public:
    using archive_type = core::IOArchive;

private:
    struct AnyProxy
    {
        // we use raw function ptr instead std::function to reach perfomance
        void(*__save)(archive_type&, std::any&) = nullptr;
        void(*__load)(archive_type&, std::any&) = nullptr;
    };

private:
    using InnerTable = std::unordered_map<let::u64, AnyProxy>;

private:
    InnerTable registry_;

private:
    AnyRegistry() : registry_() {}

    AnyRegistry(const AnyRegistry&) = delete;
    AnyRegistry& operator=(const AnyRegistry&) = delete;

public:
    static AnyRegistry& instance() noexcept
    {
        static AnyRegistry self;
        return self;
    }

    template <typename T> void update(let::u64 hash)
    {
        if (is_registered(hash)) return;

        AnyProxy proxy;

        proxy.__save = [](archive_type& archive, std::any& any)
        {
            archive << std::any_cast<T&>(any);
        };

        proxy.__load = [](archive_type& archive, std::any& any)
        {
            any.emplace<T>();
            archive >> std::any_cast<T&>(any);
        };

        registry_.emplace(hash, proxy);
    }

public:
    void save(archive_type& archive, std::any& any, let::u64 hash)
    {
        registry(hash).__save(archive, any);
    }

    void load(archive_type& archive, std::any& any, let::u64 hash)
    {
        registry(hash).__load(archive, any);
    }

public:
    bool is_registered(let::u64 hash)
    {
        return registry_.find(hash) != registry_.end();
    }

#ifndef SF_REGISTRY_ACCESS
private:
#endif // SF_REGISTRY_ACCESS
    const AnyProxy& registry(let::u64 hash)
    {
        // It happens if the type not registered with fixture object.
        auto it = registry_.find(hash);
        if (it == registry_.end())
            throw "The 'sf::AnyRegistry' must registry type with specify hash code.";

        return it->second;
    }
};

template <typename T>
class AnyFixture
{
private:
    static bool lock_;

public:
    AnyFixture() { call(); }

public:
    static void call()
    {
        if (lock_) return;
        lock_ = true; // lock before creating clone instance to prevent recursive call

        auto& registry = AnyRegistry::instance();

        auto hash = SF_TYPE_HASH(typeid(T));
    #ifdef SF_DEBUG
        if (registry.is_registered(hash))
            throw "The 'sf::dynamic::AnyRegistry' must contains unique hashes.";
    #endif // SF_DEBUG

        registry.update<T>(hash);
    }
};

template <typename T>
bool AnyFixture<T>::lock_ = false;

} // namespace dynamic

} // namespace sf

#endif // if

namespace sf
{

namespace dynamic
{

class ExternRegistry
{
public:
    using key_type = core::InstantiableTrait::key_type;

public:
    template <class Archive, typename T,
              SFREQUIRE(meta::is_pointer_to_polymorphic<T>::value)>
    static key_type save_key(Archive& archive, T& pointer)
    {
        if (pointer == nullptr)
            throw "The write pointer was not allocated.";

        auto key = ::Serialization::trait(*pointer);
        archive & key;

        return key;
    }

    template <class Archive, typename T,
              SFREQUIRE(meta::is_pointer_to_polymorphic<T>::value)>
    static key_type load_key(Archive& archive, T& pointer)
    {
    #ifndef SF_GARBAGE_CHECK_DISABLE
        if (pointer != nullptr)
            throw "The read pointer must be initialized to nullptr.";
    #endif // SF_GARBAGE_CHECK_DISABLE

        key_type key{};
        archive & key;

        return key;
    }

private:
    template <typename T> struct is_pointer_to_instantiable
        : meta::all<InstantiableRegistry::is_instantiable<meta::dereference<T>>,
                    meta::is_pointer_to_polymorphic<T>> {};

public:
    template <typename T, SFREQUIRE(is_pointer_to_instantiable<T>::value)>
    static void save(core::IOArchive& archive, T& pointer, key_type key)
    {
        if (pointer == nullptr)
            throw "The write pointer was not allocated.";

        auto raw_pointer = Memory::raw(pointer);
        InstantiableRegistry::instance().save(archive, raw_pointer);
    }

    template <typename T, SFREQUIRE(meta::is_pointer_to_polymorphic<T>::value)>
    static void load(core::IOArchive& archive, T& pointer, key_type key, Memory::void_ptr<T>& cache)
    {
        using TraitType = typename Memory::ptr_trait<T>::trait;
        using dT = meta::dereference<T>;

    #ifndef SF_GARBAGE_CHECK_DISABLE
        if (pointer != nullptr)
            throw "The read pointer must be initialized to nullptr.";
    #endif // SF_GARBAGE_CHECK_DISABLE

        auto& registry = InstantiableRegistry::instance();

        auto cloned = registry.clone<TraitType>(key);

        pointer = Memory::dynamic_pointer_cast<dT>(cloned);
        cache = Memory::pure(pointer);

        auto raw_pointer = Memory::raw(pointer);
        registry.load(archive, raw_pointer);
    }

    template <typename T, SFREQUIRE(meta::is_pointer_to_polymorphic<T>::value)>
    static void assign(T& pointer, const Memory::void_ptr<T>& address, key_type key)
    {
        using dT = meta::dereference<T>;

    #ifndef SF_GARBAGE_CHECK_DISABLE
        if (pointer != nullptr)
            throw "The read pointer must be initialized to nullptr.";
    #endif // SF_GARBAGE_CHECK_DISABLE

        auto casted = InstantiableRegistry::instance().cast(address, key);
        pointer = Memory::dynamic_pointer_cast<dT>(casted);
    }
};

} // namespace dynamic

} // namespace sf

namespace sf
{

namespace tracking
{

using Shared = meta::shared_type;
using Raw = meta::raw_type;

template <typename T>
struct track_trait;

template <typename T>
struct track_trait<Memory::shared_ptr<T>>
{
    using type = tracking::Shared;
};

template <typename T>
struct track_trait<Memory::raw_ptr<T>>
{
    using type = tracking::Raw;
};

template <typename T>
struct reverse_trait;

template <>
struct reverse_trait<Shared>
{
    using type = Raw;
};

template <>
struct reverse_trait<Raw>
{
    using type = Shared;
};

} // namespace tracking

namespace meta
{

template <typename T> struct is_track_shared : std::is_same<T, tracking::Shared> {};
template <typename T> struct is_track_raw : std::is_same<T, tracking::Raw> {};

} // namespace meta

} // namespace sf

namespace sf
{

namespace detail
{

template <typename HashType = let::u64>
struct PairHash
{
    template <typename T1, typename T2>
    HashType operator() (const std::pair<T1, T2>& pair) const noexcept
    {
        HashType seed{};

        detail::hash_combine(seed, pair.first);
        detail::hash_combine(seed, pair.second);

        return seed;
    }
};

} // namespace detail

namespace tracking
{

struct Hierarchy {};

template <typename KeyType, typename TraitType = core::InstantiableTrait::key_type>
using HierarchyTrack = std::unordered_map<std::pair<KeyType, TraitType>, bool, detail::PairHash<TraitType>>;

} // namespace tracking

namespace meta
{

template <typename T> struct is_track_hierarchy : std::is_same<T, tracking::Hierarchy> {};

} // namespace meta

} // namespace sf

#include <vector> // vector

#ifndef SF_BYTE_STREAM_RESERVE_SIZE
    #define SF_BYTE_STREAM_RESERVE_SIZE std::size_t(4096)
#endif // SF_BYTE_STREAM_RESERVE_SIZE

namespace sf
{

namespace wrapper
{

using ByteContainer = std::vector<unsigned char>;

template <typename OutStream = ByteContainer>
class OByteStream
{
protected:
    using item_type = typename OutStream::value_type;

protected:
    static_assert(sizeof(item_type) == 1, "Require byte size for 'sf::wrapper::OByteStream'.");

public:
    OutStream& storage;

public:
    OByteStream(OutStream& stream) noexcept : storage(stream)
    {
        storage.reserve(SF_BYTE_STREAM_RESERVE_SIZE); // default reserve memory
    }

    template <typename T>
    void call(const T* data, std::size_t size)
    {
        auto it = Memory::const_byte_cast<item_type>(data);
        while (size > 0)
        {
            storage.emplace_back(*it++);
            --size;
        }
    }
};

template <typename InStream = ByteContainer>
struct IByteStream
{
protected:
    using item_type = typename InStream::value_type;

protected:
    static_assert(sizeof(item_type) == 1, "Require byte size for 'sf::wrapper::IByteStream'.");

public:
    InStream& storage;
    std::size_t offset;

    IByteStream(InStream& stream) noexcept : storage(stream), offset() {}

    template <typename T>
    void call(T* data, std::size_t size)
    {
        auto it = Memory::byte_cast<item_type>(data);
        while (size > 0)
        {
            *it++ = storage[offset++];
            --size;
        }
    }
};

template <typename OutStream>
class OFileStream
{
public:
    OutStream& file;

public:
    OFileStream(OutStream& stream) noexcept : file(stream) {}

    template <typename T>
    void call(const T* data, std::size_t memory_size)
    {
        file.write(Memory::const_byte_cast(data), memory_size);
    }
};

template <typename InStream>
class IFileStream
{
public:
    InStream& file;

public:
    IFileStream(InStream& stream) noexcept : file(stream) {}

    template <typename T>
    void call(T* data, std::size_t memory_size)
    {
        file.read(Memory::byte_cast(data), memory_size);
    }
};

} // namespace wrapper

} // namespace sf

namespace sf
{

template <class StreamWrapper,
          class Registry = dynamic::ExternRegistry>
class OArchive : public core::IOArchive, public core::OArchiveType
{
    SERIALIZATION_ARCHIVE(OArchive)

public:
    using TrackingKeyType = std::uintptr_t;
    using TrackingTable = std::unordered_map<TrackingKeyType, bool>;
    using HierarchyTrackingTable = tracking::HierarchyTrack<TrackingKeyType>;

private:
    StreamWrapper archive_;

    TrackingTable track_shared_;
    TrackingTable track_raw_;

    HierarchyTrackingTable track_hierarchy_;

    Registry registry_;

public:
    template <typename OutStream> OArchive(OutStream& stream);

    auto stream() noexcept -> StreamWrapper& { return archive_; }

    template <typename TrackType,
              SFREQUIRE(meta::is_track_shared<TrackType>::value)>
    auto tracking() noexcept -> TrackingTable& { return track_shared_; }

    template <typename TrackType,
              SFREQUIRE(meta::is_track_raw<TrackType>::value)>
    auto tracking() noexcept -> TrackingTable& { return track_raw_; }

    template <typename TrackType,
              SFREQUIRE(meta::is_track_hierarchy<TrackType>::value)>
    auto tracking() noexcept -> HierarchyTrackingTable& { return track_hierarchy_; }

    auto registry() noexcept -> Registry& { return registry_; }

    template <typename T>
    auto operator<< (T&& data) -> OArchive&;

    template <typename T, typename... Tn>
    auto operator() (T& data, Tn&... data_n) -> OArchive&;

    auto operator() () noexcept -> OArchive& { return *this; }
};

// create default OArchive with wrapper::OByteStream<>
template <typename OutStream>
OArchive<wrapper::OByteStream<OutStream>> oarchive(OutStream& stream)
{
    return { stream };
}

template <template <class, typename...> class StreamWrapper,
          class Registry = dynamic::ExternRegistry,
          typename OutStream>
OArchive<StreamWrapper<OutStream>, Registry> oarchive(OutStream& stream)
{
    return { stream };
}

template <class StreamWrapper,
          class Registry = dynamic::ExternRegistry,
          typename OutStream>
OArchive<StreamWrapper, Registry> oarchive(OutStream& stream)
{
    return { stream };
}

template <class StreamWrapper, class Registry>
template <typename OutStream>
OArchive<StreamWrapper, Registry>::OArchive(OutStream& stream)
    : archive_{stream}, track_shared_(), track_raw_(), track_hierarchy_(), registry_()
{
}

template <class StreamWrapper, class Registry>
template <typename T>
auto OArchive<StreamWrapper, Registry>::operator<< (T&& data) -> OArchive&
{
    return (*this) & std::forward<T>(data);
}

template <class StreamWrapper, class Registry>
template <typename T, typename... Tn>
auto OArchive<StreamWrapper, Registry>::operator() (T& data, Tn&... data_n) -> OArchive&
{
    (*this) & data;
    return operator()(data_n...);
}

template <class Archive, typename T,
          SFREQUIRE(meta::all<meta::is_oarchive<Archive>,
                              meta::is_unsupported<T>>::value)>
Archive& operator& (Archive& archive, T& unsupported)
{
    static_assert(meta::to_false<T>(),
        "The 'T' is an unsupported type for the 'sf::OArchive'.");

    return archive;
}

template <class Archive, typename T,
          SFREQUIRE(meta::all<meta::is_oarchive<Archive>,
                              meta::negation<meta::is_registered<T>>>::value)>
Archive& operator& (Archive& archive, T& unregistered)
{
    static_assert(meta::to_false<T>(),
        "The 'T' is an unregistered type for the 'sf::OArchive'.");

    return archive;
}

} // namespace sf

namespace sf
{

template <class StreamWrapper,
          class Registry = dynamic::ExternRegistry>
class IArchive : public core::IOArchive, public core::IArchiveType
{
    SERIALIZATION_ARCHIVE(IArchive)

private:
    template <typename VoidPointer>
    struct TrackData { VoidPointer address = nullptr; };

public:
    using Shared = TrackData<Memory::shared_ptr<void>>;
    using Raw = TrackData<Memory::raw_ptr<void>>;

public:
    using TrackingKeyType = std::uintptr_t;

    template <typename TrackData>
    using TrackingTable = std::unordered_map<TrackingKeyType, TrackData>;

    using HierarchyTrackingTable = tracking::HierarchyTrack<TrackingKeyType>;

private:
    StreamWrapper archive_;

    TrackingTable<Shared> track_shared_;
    TrackingTable<Raw> track_raw_;

    HierarchyTrackingTable track_hierarchy_;

    Registry registry_;

public:
    template <typename InStream> IArchive(InStream& stream);

    auto stream() noexcept -> StreamWrapper& { return archive_; }

    template <typename TrackType,
              SFREQUIRE(meta::is_track_shared<TrackType>::value)>
    auto tracking() noexcept -> TrackingTable<Shared>& { return track_shared_; }

    template <typename TrackType,
              SFREQUIRE(meta::is_track_raw<TrackType>::value)>
    auto tracking() noexcept -> TrackingTable<Raw>& { return track_raw_; }

    template <typename TrackType,
              SFREQUIRE(meta::is_track_hierarchy<TrackType>::value)>
    auto tracking() noexcept -> HierarchyTrackingTable& { return track_hierarchy_; }

    auto registry() noexcept -> Registry& { return registry_; }

    template <typename T>
    auto operator>> (T&& data) -> IArchive&;

    template <typename T, typename... Tn>
    auto operator() (T& data, Tn&... data_n) -> IArchive&;

    auto operator() () -> IArchive& { return *this; }
};

// create default IArchive with wrapper::IByteStream<>
template <typename InStream>
IArchive<wrapper::IByteStream<InStream>> iarchive(InStream& stream)
{
    return { stream };
}

template <template <class, typename...> class StreamWrapper,
          class Registry = dynamic::ExternRegistry,
          typename InStream>
IArchive<StreamWrapper<InStream>, Registry> iarchive(InStream& stream)
{
    return { stream };
}

template <class StreamWrapper,
          class Registry = dynamic::ExternRegistry,
          typename InStream>
IArchive<StreamWrapper, Registry> iarchive(InStream& stream)
{
    return { stream };
}

template <class StreamWrapper, class Registry>
template <typename InStream>
IArchive<StreamWrapper, Registry>::IArchive(InStream& stream)
    : archive_{stream}, track_shared_(), track_raw_(), track_hierarchy_(), registry_()
{
}

template <class StreamWrapper, class Registry>
template <typename T>
auto IArchive<StreamWrapper, Registry>::operator>> (T&& data) -> IArchive&
{
    return (*this) & std::forward<T>(data);
}

template <class StreamWrapper, class Registry>
template <typename T, typename... Tn>
auto IArchive<StreamWrapper, Registry>::operator() (T& data, Tn&... data_n) -> IArchive&
{
    (*this) & data;
    return operator()(data_n...);
}

template <class Archive, typename T,
          SFREQUIRE(meta::all<meta::is_iarchive<Archive>,
                              meta::is_unsupported<T>>::value)>
Archive& operator& (Archive& archive, T& unsupported)
{
    static_assert(meta::to_false<T>(),
        "The 'T' is an unsupported type for the 'sf::IArchive'.");

    return archive;
}

template <class Archive, typename T,
          SFREQUIRE(meta::all<meta::is_iarchive<Archive>,
                              meta::negation<meta::is_registered<T>>>::value)>
Archive& operator& (Archive& archive, T& unregistered)
{
    static_assert(meta::to_false<T>(),
        "The 'T' is an unregistered type for the 'sf::IArchive'.");

    return archive;
}

} // namespace sf

#define EXTERN_CONDITIONAL_SERIALIZATION(mode, parameter, ...)                                          \
    template <class Archive, typename T,                                                                \
              SFREQUIRE(::sf::meta::all<::sf::meta::is_##mode<Archive>,                                 \
                                        ::sf::meta::is_registered_extern<T>,                            \
                                        ::sf::meta::boolean<bool(__VA_ARGS__)>>::value)>                \
    Archive& operator& (Archive& archive, T& parameter)

// require TYPE_REGISTRY before use if not def SF_TYPE_REGISTRY_DISABLE
#define EXTERN_SERIALIZATION(mode, parameter, ...)                                                      \
    template <class Archive,                                                                            \
              SFREQUIRE(::sf::meta::all<::sf::meta::is_##mode<Archive>,                                 \
                                        ::sf::meta::is_registered_extern<__VA_ARGS__>>::value)>         \
    Archive& operator& (Archive& archive, __VA_ARGS__& parameter)

namespace sf
{

namespace meta
{

template <class T> struct is_Save : is_oarchive<T> {};
template <class T> struct is_Load : is_iarchive<T> {};

template <class T> struct is_SaveLoad : is_ioarchive<T> {};

} // namespace meta

} // namespace sf

namespace sf
{

namespace apply
{

struct ApplyFunctor {};

} // namespace apply

namespace meta
{

template <typename T> struct is_apply_functor : std::is_base_of<apply::ApplyFunctor, T> {};

} // namespace meta

// inline namespace common also used in namespace library
inline namespace common
{

template <typename Archive, typename T,
          typename dT = meta::decay<T>, // T can be lvalue
          SFREQUIRE(meta::all<meta::is_archive<Archive>,
                              meta::is_registered<dT>,
                              meta::is_apply_functor<dT>>::value)>
Archive& operator& (Archive& archive, T&& apply_functor)
{
    apply_functor(archive);
    return archive;
}

} // inline namespace common

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_apply_functor<T>::value)

namespace sf
{

template <class Archive, typename T,
          SFREQUIRE(meta::is_ioarchive<Archive>::value)>
void binary(Archive& archive, T& data)
{
    archive.stream().call(std::addressof(data), sizeof(T));
}

namespace apply
{

template <typename T>
struct BinaryFunctor : ApplyFunctor
{
    T& data;

    BinaryFunctor(T& data) noexcept : data(data) {}

    template <class Archive>
    void operator() (Archive& archive) const { binary(archive, data); }
};

} // namespace apply

template <typename T> apply::BinaryFunctor<T> binary(T& object) noexcept { return { object }; }

} // namespace sf

namespace sf
{

namespace detail
{

template <class Archive, typename T, typename KeyType,
          SFREQUIRE(meta::all<meta::is_oarchive<Archive>,
                              meta::negation<meta::is_pointer_to_polymorphic<T>>>::value)>
void native_save(Archive& archive, T& pointer, KeyType track_key) noexcept { /*pass*/ }

template <class Archive, typename T, typename KeyType,
          SFREQUIRE(meta::all<meta::is_oarchive<Archive>,
                              meta::is_pointer_to_polymorphic<T>>::value)>
void native_save(Archive& archive, T& pointer, KeyType track_key)
{
    archive.registry().save_key(archive, pointer); // write class info
}

template <class Archive, typename T,
          SFREQUIRE(meta::all<meta::is_iarchive<Archive>,
                              meta::negation<meta::is_pointer_to_polymorphic<T>>>::value)>
void native_load(Archive& archive, T& pointer, Memory::void_ptr<T>& address) noexcept
{
    Memory::assign<meta::dereference<T>>(pointer, address);
}

template <class Archive, typename T,
          SFREQUIRE(meta::all<meta::is_iarchive<Archive>,
                              meta::is_pointer_to_polymorphic<T>>::value)>
void native_load(Archive& archive, T& pointer, Memory::void_ptr<T>& address)
{
    auto& registry = archive.registry();

    auto id = registry.load_key(archive, pointer);
    registry.assign(pointer, address, id);
}

} // namespace detail

} // namespace sf

namespace sf
{

template <class Archive, typename T,
          SFREQUIRE(meta::all<meta::is_oarchive<Archive>,
                              meta::is_pointer_to_standard_layout<T>>::value)>
void strict(Archive& archive, T& pointer)
{
    if (pointer == nullptr)
        throw "The write pointer must be allocated.";

    archive & (*pointer);
}

template <class Archive, typename T,
          SFREQUIRE(meta::all<meta::is_iarchive<Archive>,
                              meta::is_pointer_to_standard_layout<T>>::value)>
void strict(Archive& archive, T& pointer, Memory::void_ptr<T>& cache)
{
    using item_type = typename Memory::ptr_trait<T>::item;

#ifndef SF_GARBAGE_CHECK_DISABLE
    if (pointer != nullptr)
        throw "The read pointer must be initialized to nullptr.";
#endif // SF_GARBAGE_CHECK_DISABLE

    Memory::allocate<item_type>(pointer);
    cache = Memory::pure(pointer);

    archive & (*pointer);
}

template <class Archive, typename T,
          SFREQUIRE(meta::all<meta::is_oarchive<Archive>,
                              meta::is_pointer_to_polymorphic<T>>::value)>
void strict(Archive& archive, T& pointer)
{
    auto& registry = archive.registry();

    auto id = registry.save_key(archive, pointer);
    registry.save(archive, pointer, id);
}

template <class Archive, typename T,
          SFREQUIRE(meta::all<meta::is_iarchive<Archive>,
                              meta::is_pointer_to_polymorphic<T>>::value)>
void strict(Archive& archive, T& pointer, Memory::void_ptr<T>& cache)
{
    auto& registry = archive.registry();

    auto id = registry.load_key(archive, pointer);
    registry.load(archive, pointer, id, cache);
}

// verison without cache using
template <class Archive, typename T,
          SFREQUIRE(meta::all<meta::is_iarchive<Archive>,
                              meta::is_serializable_pointer<T>>::value)>
void strict(Archive& archive, T& pointer)
{
    Memory::void_ptr<T> cache = nullptr;
    strict(archive, pointer, cache);
}

namespace detail
{

template <class Archive, typename T,
          typename KeyType = typename Archive::TrackingKeyType,
          SFREQUIRE(meta::all<meta::is_oarchive<Archive>,
                              meta::is_serializable_pointer<T>>::value)>
KeyType refer_key(Archive& archive, T& pointer)
{
    auto pure = Memory::pure(pointer);
    auto key = reinterpret_cast<KeyType>(Memory::raw(pure));

    archive & key;
    return key;
}

template <class Archive, typename T,
          typename KeyType = typename Archive::TrackingKeyType,
          SFREQUIRE(meta::all<meta::is_iarchive<Archive>,
                              meta::is_serializable_pointer<T>>::value)>
KeyType refer_key(Archive& archive, T& pointer)
{
#ifdef SF_DEBUG
    if (pointer != nullptr)
        throw "The read pointer must be initialized to nullptr.";
#endif // SF_DEBUG

    KeyType key{};
    archive & key;

    return key;
}

} // namespace detail

namespace apply
{

template <typename T>
struct StrictFunctor : public ApplyFunctor
{
    T& data;

    StrictFunctor(T& data) noexcept : data(data) {}

    template <class Archive>
    void operator() (Archive& archive) const { strict(archive, data); }
};

} // namespace apply

template <typename T>
apply::StrictFunctor<T> strict(T& parameter) noexcept { return { parameter }; }

} // namespace sf

namespace sf
{

namespace tracking
{

template <typename TrackType, class Archive, typename KeyType,
          SFREQUIRE(meta::is_ioarchive<Archive>::value)>
bool is_track(Archive& archive, KeyType key)
{
    auto& item = archive.template tracking<TrackType>();
    return item.find(key) != item.end();
}

template <typename TrackType, class Archive, typename KeyType,
          SFREQUIRE(meta::is_ioarchive<Archive>::value)>
bool is_mixed(Archive& archive, KeyType key)
{
    using reverse_track_type = typename reverse_trait<TrackType>::type;
    return is_track<reverse_track_type>(archive, key);
}

template <class Archive, typename T,
          SFREQUIRE(meta::all<meta::is_oarchive<Archive>,
                              meta::is_pointer<T>>::value)>
void track(Archive& archive, T& pointer)
{
    using track_type = typename tracking::track_trait<T>::type;

    auto key = detail::refer_key(archive, pointer); // serialize refer info
    if (not key) return;

#ifdef SF_DEBUG
    if (is_mixed<track_type>(archive, key))
        throw "Mixed pointer tracking is not allowed.";
#endif // SF_DEBUG

    auto& is_tracking = archive.template tracking<track_type>()[key];

    if (not is_tracking)
    {
        is_tracking = true;
        strict(archive, pointer); // call the strict serialization of not tracking pointer
    }
    else
    {
        detail::native_save(archive, pointer, key);
    }
}

template <class Archive, typename T,
          SFREQUIRE(meta::all<meta::is_oarchive<Archive>,
                              meta::negation<meta::is_pointer<T>>>::value)>
void track(Archive& archive, T& data)
{
    using key_type = typename Archive::TrackingKeyType;

    auto address = Memory::pure(std::addressof(data));
    auto key = reinterpret_cast<key_type>(address);

    auto& is_tracking = archive.template tracking<tracking::Raw>()[key];

    if (is_tracking)
        throw "The write tracking data is already tracked.";

    is_tracking = true;

    archive & key;
    archive & data;
}

template <class Archive, typename T,
          SFREQUIRE(meta::all<meta::is_iarchive<Archive>,
                              meta::is_pointer<T>>::value)>
void track(Archive& archive, T& pointer)
{
    using track_type = typename tracking::track_trait<T>::type;

#ifndef SF_GARBAGE_CHECK_DISABLE
    if (pointer != nullptr)
        throw "The read track pointer must be initialized to nullptr.";
#endif // SF_GARBAGE_CHECK_DISABLE

    auto key = detail::refer_key(archive, pointer); // serialize refer info
    if (not key) return;

    auto& item = archive.template tracking<track_type>()[key];

    if (item.address == nullptr)
    {
        // call the strict serialization of not tracking pointer
        strict(archive, pointer, item.address);
    }
    else
    {
        detail::native_load(archive, pointer, item.address);
    }
}

template <class Archive, typename T,
          SFREQUIRE(meta::all<meta::is_iarchive<Archive>,
                              meta::negation<meta::is_pointer<T>>>::value)>
void track(Archive& archive, T& data)
{
    using key_type = typename Archive::TrackingKeyType;

    key_type key{};
    archive & key;

    auto& item = archive.template tracking<tracking::Raw>()[key];

    if (item.address != nullptr)
        throw  "The read tracking data is already tracked.";

    item.address = Memory::pure(std::addressof(data));

    archive & data;
}

template <class Archive, typename T,
          SFREQUIRE(meta::all<meta::is_ioarchive<T>,
                              meta::is_serializable_raw_pointer<T>>::value)>
void raw(Archive& archive, T& pointer)
{
    if (detail::refer_key(archive, pointer)) // serialize refer info
        strict(archive, pointer);
}

} // namespace tracking

namespace apply
{

template <typename T>
struct TrackFunctor : ApplyFunctor
{
    T& data;

    TrackFunctor(T& data) noexcept : data(data) {}

    template <class Archive>
    void operator() (Archive& archive) const { tracking::track(archive, data); }
};

template <typename T>
struct RawFunctor : ApplyFunctor
{
    T& data;

    RawFunctor(T& data) noexcept : data(data) {}

    template <class Archive>
    void operator() (Archive& archive) const { tracking::raw(archive, data); }
};

} // namespace apply

namespace tracking
{

template <typename T> apply::TrackFunctor<T> track(T& data) noexcept { return { data }; }
template <typename T> apply::RawFunctor<T> raw(T& data) noexcept { return { data }; }

} // namespace tracking

} // namespace sf

#include <valarray> // valarray

namespace sf
{

namespace utility
{

template <class Container>
inline const typename Container::value_type* data(const Container& c) noexcept
{
    // if begin return iterator - we should deref it and take address again
    return std::addressof(*std::begin(c));
}

template <typename T>
inline const T* data(const std::valarray<T>& c) noexcept
{
    return std::begin(c);
}

template <class T, std::size_t N>
inline const T* data(const T (&array)[N]) noexcept
{
    return array;
}

template <class Container>
inline auto size(const Container& c) noexcept -> decltype(c.size())
{
    return c.size();
}

template <class T, std::size_t N>
constexpr std::size_t size(const T (&array)[N]) noexcept
{
    return N;
}

template <typename CharType,
          SFREQUIRE(meta::is_character<CharType>::value)>
std::size_t size(const CharType* str) noexcept
{
    std::size_t count{};
    while (*str++ != CharType{}) ++count;

    return count;
}

} // namespace utility

} // namespace sf

namespace sf
{

namespace compress
{

// always require compressible type for fast compression
template <class Archive, typename T,
          SFREQUIRE(meta::all<meta::is_ioarchive<Archive>,
                              meta::is_compressible<T>>::value)>
void fast(Archive& archive, T& object)
{
    using item_type = meta::value_type<T>;

    archive.stream().call
    (
        const_cast<item_type*>(utility::data(object)),
        utility::size(object) * sizeof(item_type)
    );
}

template <class Archive, typename T,
          SFREQUIRE(meta::is_ioarchive<Archive>::value)>
void slow(Archive& archive, T& object)
{
    for (auto&& item : object)
        archive & item;
}

template <class Archive, typename T,
          SFREQUIRE(meta::all<meta::is_ioarchive<Archive>,
                              meta::is_compressible<T>>::value)>
void zip(Archive& archive, T& object)
{
    fast(archive, object);
}

template <class Archive, typename T,
          SFREQUIRE(meta::all<meta::is_ioarchive<Archive>,
                              meta::negation<meta::is_compressible<T>>>::value)>
void zip(Archive& archive, T& object)
{
    slow(archive, object);
}

} // namespace compress

} // namespace sf

namespace sf
{

// inline namespace common also used in namespace library
inline namespace common
{

EXTERN_CONDITIONAL_SERIALIZATION(Save, object, ::Serialization::has_save_mode<T>::value)
{
    ::Serialization::save(archive, object);
    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(Load, object, ::Serialization::has_load_mode<T>::value)
{
    ::Serialization::load(archive, object);
    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(SaveLoad, number, std::is_arithmetic<T>::value)
{
    binary(archive, number);
    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(Save, enumerator, std::is_enum<T>::value)
{
    using underlying_type = typename std::underlying_type<T>::type;
    auto value = static_cast<underlying_type>(enumerator);

    return archive & value;
}

EXTERN_CONDITIONAL_SERIALIZATION(Load, enumerator, std::is_enum<T>::value)
{
    using underlying_type = typename std::underlying_type<T>::type;

    underlying_type buff{};
    archive & buff;

    enumerator = static_cast<T>(buff);

    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(SaveLoad, array, std::is_array<T>::value)
{
    compress::zip(archive, array);
    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(SaveLoad, pointer, meta::is_serializable_raw_pointer<T>::value)
{
#ifdef SF_PTRTRACK_DISABLE
    tracking::raw(archive, pointer);
#else
    tracking::track(archive, pointer);
#endif // SF_PTRTRACK_DISABLE

    return archive;
}

} // inline namespace common

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::all<::Serialization::has_save_mode<T>, ::Serialization::has_load_mode<T>>::value)

CONDITIONAL_TYPE_REGISTRY(std::is_arithmetic<T>::value)
CONDITIONAL_TYPE_REGISTRY(std::is_enum<T>::value)
CONDITIONAL_TYPE_REGISTRY(std::is_array<T>::value)
CONDITIONAL_TYPE_REGISTRY(meta::is_serializable_raw_pointer<T>::value)

#if __cplusplus >= 201703L

#define _SF_CONCAT_IMPL(a, b) a##b

// concatenation of two macro arguments
#define SFCONCAT(a, b) _SF_CONCAT_IMPL(a, b)

// return first argument from two
#define SFFIRST_ARGUMENT(first, ...) first

#define _SFVA_ARGS_SIZE_IMPL(                                                                           \
     _1,  _2,  _3,  _4,  _5,  _6,  _7,  _8,  _9, _10, _11, _12, _13, _14, _15, _16,                     \
    _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32,                     \
    _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48,                     \
    _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, N, ...) N

#define _REVERSE_INTEGER_SEQUENCE                                                                       \
    63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48,                                     \
    47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32,                                     \
    31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16,                                     \
    15, 14, 13, 12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0

#define _SFVA_ARGS_SIZE(...) _SFVA_ARGS_SIZE_IMPL(__VA_ARGS__)

// return __VA_ARGS__ arguments count, for empty __VA_ARGS__ return 1
#define SFVA_ARGS_SIZE(...) _SFVA_ARGS_SIZE(__VA_ARGS__, _REVERSE_INTEGER_SEQUENCE)

// generate repeat sequance macro(1) macro(2) ... macro(count)
#define SFREPEAT(macro, count) SFCONCAT(_REPEAT_, count)(macro)

#define _REPEAT_0(macro)

#define _REPEAT_1(macro) _REPEAT_0(macro) macro(1)
#define _REPEAT_2(macro) _REPEAT_1(macro) macro(2)
#define _REPEAT_3(macro) _REPEAT_2(macro) macro(3)
#define _REPEAT_4(macro) _REPEAT_3(macro) macro(4)
#define _REPEAT_5(macro) _REPEAT_4(macro) macro(5)
#define _REPEAT_6(macro) _REPEAT_5(macro) macro(6)
#define _REPEAT_7(macro) _REPEAT_6(macro) macro(7)
#define _REPEAT_8(macro) _REPEAT_7(macro) macro(8)

#define _REPEAT_9(macro) _REPEAT_8(macro) macro(9)
#define _REPEAT_10(macro) _REPEAT_9(macro) macro(10)
#define _REPEAT_11(macro) _REPEAT_10(macro) macro(11)
#define _REPEAT_12(macro) _REPEAT_11(macro) macro(12)
#define _REPEAT_13(macro) _REPEAT_12(macro) macro(13)
#define _REPEAT_14(macro) _REPEAT_13(macro) macro(14)
#define _REPEAT_15(macro) _REPEAT_14(macro) macro(15)
#define _REPEAT_16(macro) _REPEAT_15(macro) macro(16)

#define _REPEAT_17(macro) _REPEAT_16(macro) macro(17)
#define _REPEAT_18(macro) _REPEAT_17(macro) macro(18)
#define _REPEAT_19(macro) _REPEAT_18(macro) macro(19)
#define _REPEAT_20(macro) _REPEAT_19(macro) macro(20)
#define _REPEAT_21(macro) _REPEAT_20(macro) macro(21)
#define _REPEAT_22(macro) _REPEAT_21(macro) macro(22)
#define _REPEAT_23(macro) _REPEAT_22(macro) macro(23)
#define _REPEAT_24(macro) _REPEAT_23(macro) macro(24)

#define _REPEAT_25(macro) _REPEAT_24(macro) macro(25)
#define _REPEAT_26(macro) _REPEAT_25(macro) macro(26)
#define _REPEAT_27(macro) _REPEAT_26(macro) macro(27)
#define _REPEAT_28(macro) _REPEAT_27(macro) macro(28)
#define _REPEAT_29(macro) _REPEAT_28(macro) macro(29)
#define _REPEAT_30(macro) _REPEAT_29(macro) macro(30)
#define _REPEAT_31(macro) _REPEAT_30(macro) macro(31)
#define _REPEAT_32(macro) _REPEAT_31(macro) macro(32)

#define _REPEAT_33(macro) _REPEAT_32(macro) macro(33)
#define _REPEAT_34(macro) _REPEAT_33(macro) macro(34)
#define _REPEAT_35(macro) _REPEAT_34(macro) macro(35)
#define _REPEAT_36(macro) _REPEAT_35(macro) macro(36)
#define _REPEAT_37(macro) _REPEAT_36(macro) macro(37)
#define _REPEAT_38(macro) _REPEAT_37(macro) macro(38)
#define _REPEAT_39(macro) _REPEAT_38(macro) macro(39)
#define _REPEAT_40(macro) _REPEAT_39(macro) macro(40)

#define _REPEAT_41(macro) _REPEAT_40(macro) macro(41)
#define _REPEAT_42(macro) _REPEAT_41(macro) macro(42)
#define _REPEAT_43(macro) _REPEAT_42(macro) macro(43)
#define _REPEAT_44(macro) _REPEAT_43(macro) macro(44)
#define _REPEAT_45(macro) _REPEAT_44(macro) macro(45)
#define _REPEAT_46(macro) _REPEAT_45(macro) macro(46)
#define _REPEAT_47(macro) _REPEAT_46(macro) macro(47)
#define _REPEAT_48(macro) _REPEAT_47(macro) macro(48)

#define _REPEAT_49(macro) _REPEAT_48(macro) macro(49)
#define _REPEAT_50(macro) _REPEAT_49(macro) macro(50)
#define _REPEAT_51(macro) _REPEAT_50(macro) macro(51)
#define _REPEAT_52(macro) _REPEAT_51(macro) macro(52)
#define _REPEAT_53(macro) _REPEAT_52(macro) macro(53)
#define _REPEAT_54(macro) _REPEAT_53(macro) macro(54)
#define _REPEAT_55(macro) _REPEAT_54(macro) macro(55)
#define _REPEAT_56(macro) _REPEAT_55(macro) macro(56)

#define _REPEAT_57(macro) _REPEAT_56(macro) macro(57)
#define _REPEAT_58(macro) _REPEAT_57(macro) macro(58)
#define _REPEAT_59(macro) _REPEAT_58(macro) macro(59)
#define _REPEAT_60(macro) _REPEAT_59(macro) macro(60)
#define _REPEAT_61(macro) _REPEAT_60(macro) macro(61)
#define _REPEAT_62(macro) _REPEAT_61(macro) macro(62)
#define _REPEAT_63(macro) _REPEAT_62(macro) macro(63)
#define _REPEAT_64(macro) _REPEAT_63(macro) macro(64)
// and etc.

// generate placeholder sequance _0, _1, _2, ..., _count
#define SFPLACEHOLDERS(count) SFCONCAT(_PLACEHOLDER_, count)()

#define _PLACEHOLDER_1() _0
#define _PLACEHOLDER_2() _PLACEHOLDER_1(), _1
#define _PLACEHOLDER_3() _PLACEHOLDER_2(), _2
#define _PLACEHOLDER_4() _PLACEHOLDER_3(), _3
#define _PLACEHOLDER_5() _PLACEHOLDER_4(), _4
#define _PLACEHOLDER_6() _PLACEHOLDER_5(), _5
#define _PLACEHOLDER_7() _PLACEHOLDER_6(), _6
#define _PLACEHOLDER_8() _PLACEHOLDER_7(), _7

#define _PLACEHOLDER_9() _PLACEHOLDER_8(), _8
#define _PLACEHOLDER_10() _PLACEHOLDER_9(), _9
#define _PLACEHOLDER_11() _PLACEHOLDER_10(), _10
#define _PLACEHOLDER_12() _PLACEHOLDER_11(), _11
#define _PLACEHOLDER_13() _PLACEHOLDER_12(), _12
#define _PLACEHOLDER_14() _PLACEHOLDER_13(), _13
#define _PLACEHOLDER_15() _PLACEHOLDER_14(), _14
#define _PLACEHOLDER_16() _PLACEHOLDER_15(), _15

#define _PLACEHOLDER_17() _PLACEHOLDER_16(), _16
#define _PLACEHOLDER_18() _PLACEHOLDER_17(), _17
#define _PLACEHOLDER_19() _PLACEHOLDER_18(), _18
#define _PLACEHOLDER_20() _PLACEHOLDER_19(), _19
#define _PLACEHOLDER_21() _PLACEHOLDER_20(), _20
#define _PLACEHOLDER_22() _PLACEHOLDER_21(), _21
#define _PLACEHOLDER_23() _PLACEHOLDER_22(), _22
#define _PLACEHOLDER_24() _PLACEHOLDER_23(), _23

#define _PLACEHOLDER_25() _PLACEHOLDER_24(), _24
#define _PLACEHOLDER_26() _PLACEHOLDER_25(), _25
#define _PLACEHOLDER_27() _PLACEHOLDER_26(), _26
#define _PLACEHOLDER_28() _PLACEHOLDER_27(), _27
#define _PLACEHOLDER_29() _PLACEHOLDER_28(), _28
#define _PLACEHOLDER_30() _PLACEHOLDER_29(), _29
#define _PLACEHOLDER_31() _PLACEHOLDER_30(), _30
#define _PLACEHOLDER_32() _PLACEHOLDER_31(), _31

#define _PLACEHOLDER_33() _PLACEHOLDER_32(), _32
#define _PLACEHOLDER_34() _PLACEHOLDER_33(), _33
#define _PLACEHOLDER_35() _PLACEHOLDER_34(), _34
#define _PLACEHOLDER_36() _PLACEHOLDER_35(), _35
#define _PLACEHOLDER_37() _PLACEHOLDER_36(), _36
#define _PLACEHOLDER_38() _PLACEHOLDER_37(), _37
#define _PLACEHOLDER_39() _PLACEHOLDER_38(), _38
#define _PLACEHOLDER_40() _PLACEHOLDER_39(), _39

#define _PLACEHOLDER_41() _PLACEHOLDER_40(), _40
#define _PLACEHOLDER_42() _PLACEHOLDER_41(), _41
#define _PLACEHOLDER_43() _PLACEHOLDER_42(), _42
#define _PLACEHOLDER_44() _PLACEHOLDER_43(), _43
#define _PLACEHOLDER_45() _PLACEHOLDER_44(), _44
#define _PLACEHOLDER_46() _PLACEHOLDER_45(), _45
#define _PLACEHOLDER_47() _PLACEHOLDER_46(), _46
#define _PLACEHOLDER_48() _PLACEHOLDER_47(), _47

#define _PLACEHOLDER_49() _PLACEHOLDER_48(), _48
#define _PLACEHOLDER_50() _PLACEHOLDER_49(), _49
#define _PLACEHOLDER_51() _PLACEHOLDER_50(), _50
#define _PLACEHOLDER_52() _PLACEHOLDER_51(), _51
#define _PLACEHOLDER_53() _PLACEHOLDER_52(), _52
#define _PLACEHOLDER_54() _PLACEHOLDER_53(), _53
#define _PLACEHOLDER_55() _PLACEHOLDER_54(), _54
#define _PLACEHOLDER_56() _PLACEHOLDER_55(), _55

#define _PLACEHOLDER_57() _PLACEHOLDER_56(), _56
#define _PLACEHOLDER_58() _PLACEHOLDER_57(), _57
#define _PLACEHOLDER_59() _PLACEHOLDER_58(), _58
#define _PLACEHOLDER_60() _PLACEHOLDER_59(), _59
#define _PLACEHOLDER_61() _PLACEHOLDER_60(), _60
#define _PLACEHOLDER_62() _PLACEHOLDER_61(), _61
#define _PLACEHOLDER_63() _PLACEHOLDER_62(), _62
#define _PLACEHOLDER_64() _PLACEHOLDER_63(), _63
// and etc.

#define _SF_AGGREGATE_IMPLEMENTATION_GENERIC(count)                                                     \
    template <class Archive, typename T>                                                                \
    void aggregate_implementation(Archive& archive, T& object, meta::dispatch<count>) {                 \
        auto& [SFPLACEHOLDERS(count)] = object;                                                         \
        archive(SFPLACEHOLDERS(count));                                                                 \
    }

namespace sf
{

namespace meta
{

template <typename T> struct is_serializable_aggregate
    : all<is_aggregate<T>,
          negation<std::is_union<T>>,
          negation<::Serialization::has_save_mode<T>>,
          negation<::Serialization::has_save_mode<T>>> {};

} // namespace meta

namespace detail
{

template <class Archive, typename T>
void aggregate_implementation(Archive& archive, T& object, meta::dispatch<0>) noexcept { /*pass*/ }

SFREPEAT(_SF_AGGREGATE_IMPLEMENTATION_GENERIC, 64)

} // namespace detail

template <class Archive, typename T,
          SFREQUIRE(meta::all<meta::is_ioarchive<Archive>,
                              meta::is_aggregate<T>>::value)>
void aggregate(Archive& archive, T& object)
{
    constexpr auto size = meta::aggregate_size<T>::value;
    detail::aggregate_implementation(archive, object, meta::dispatch<size>{});
}

inline namespace common
{

EXTERN_CONDITIONAL_SERIALIZATION(SaveLoad, object, meta::is_serializable_aggregate<T>::value)
{
    aggregate(archive, object);
    return archive;
}

} // inline namespace common

namespace apply
{

template <typename T>
struct AggregateFunctor : ApplyFunctor
{
    T& object;

    AggregateFunctor(T& object) noexcept : object(object) {}

    template <class Archive>
    void operator() (Archive& archive) const { aggregate(archive, object); }
};

} // namespace apply

template <typename T> apply::AggregateFunctor<T> aggregate(T& object) noexcept { return { object }; }

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_serializable_aggregate<T>::value)

// clean up
#undef _SF_AGGREGATE_IMPLEMENTATION_GENERIC

#endif // if

namespace sf
{

namespace meta
{

template <typename T> struct is_serializable_union
    : all<std::is_union<T>,
          negation<::Serialization::has_save_mode<T>>,
          negation<::Serialization::has_save_mode<T>>> {};

} // namespace meta

EXTERN_CONDITIONAL_SERIALIZATION(SaveLoad, data, meta::is_serializable_union<T>::value)
{
    binary(archive, data);
    return archive;
}

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_serializable_union<T>::value)

namespace sf
{

template <class Base, class Archive, class Derived,
          SFREQUIRE(meta::all<meta::is_ioarchive<Archive>,
                              std::is_base_of<Base, Derived>>::value)>
void base(Archive& archive, Derived& object)
{
    ::Serialization::serialize_base<Base>(archive, object);
}

template <class Base, class Archive, class Derived,
          SFREQUIRE(meta::all<meta::is_ioarchive<Archive>,
                              std::is_base_of<Base, Derived>>::value)>
void virtual_base(Archive& archive, Derived& object)
{
#ifdef SF_PTRTRACK_DISABLE
    if (::Serialization::trait(object) == ::Serialization::template trait<Derived>())
        base<Base>(archive, object);
#else
    using key_type = typename Archive::TrackingKeyType;

    auto address = Memory::pure(std::addressof(object));

    auto key = reinterpret_cast<key_type>(address);
    auto trait = ::Serialization::trait<Base>();

    auto& hierarchy_tracking = archive.template tracking<tracking::Hierarchy>();

    auto& is_tracking = hierarchy_tracking[{key, trait}];
    if (not is_tracking)
    {
        is_tracking = true;
        base<Base>(archive, object);
    }
#endif // SF_PTRTRACK_DISABLE
}

namespace detail
{

template <class Base, class Archive, class Derived,
          SFREQUIRE(not ::Serialization::is_virtual_base_of<Base, Derived>::value)>
void native_base(Archive& archive, Derived& object_with_base)
{
    base<Base>(archive, object_with_base);
}

template <class Base, class Archive, class Derived,
          SFREQUIRE(::Serialization::is_virtual_base_of<Base, Derived>::value)>
void native_base(Archive& archive, Derived& object_with_virtual_base)
{
    virtual_base<Base>(archive, object_with_virtual_base);
}

} // namespace detail

namespace apply
{

template <class Derived, class Base>
struct BaseFunctor : ApplyFunctor
{
    Derived& object;

    BaseFunctor(Derived& object) noexcept : object(object) {}

    template <class Archive>
    void operator() (Archive& archive) const { base<Base>(archive, object); }
};

template <class Derived, class Base>
struct VirtualBaseFunctor : ApplyFunctor
{
    Derived& object;

    VirtualBaseFunctor(Derived& object) noexcept : object(object) {}

    template <class Archive>
    void operator() (Archive& archive) const { virtual_base<Base>(archive, object); }
};

} // namespace apply

template <class Base, class Derived,
          SFREQUIRE(std::is_base_of<Base, Derived>::value)>
apply::BaseFunctor<Derived, Base> base(Derived& object) noexcept { return { object }; }

template <class Base, class Derived,
          SFREQUIRE(std::is_base_of<Base, Derived>::value)>
apply::VirtualBaseFunctor<Derived, Base> virtual_base(Derived& object) noexcept { return { object }; }

// default empty implementation
template <class Archive, class Derived>
void hierarchy(Archive& archive, Derived& object) noexcept { /*pass*/ }

// Variadic native_base function
template <class Base, class... Base_n, class Archive, class Derived,
          SFREQUIRE(meta::all<meta::is_ioarchive<Archive>,
                              meta::is_derived_of<Derived, Base, Base_n...>>::value)>
void hierarchy(Archive& archive, Derived& object)
{
    detail::native_base<Base>(archive, object);
    hierarchy<Base_n...>(archive, object);
}

namespace apply
{

template <class Derived, class Base, class... Base_n>
struct HierarchyFunctor : ApplyFunctor
{
    Derived& object;

    HierarchyFunctor(Derived& object) noexcept : object(object) {}

    template <class Archive>
    void operator() (Archive& archive) const { hierarchy<Base, Base_n...>(archive, object); }
};

} // namespace apply

template <class Base, class... Base_n, class Derived,
          SFREQUIRE(meta::is_derived_of<Derived, Base, Base_n...>::value)>
apply::HierarchyFunctor<Derived, Base, Base_n...> hierarchy(Derived& object) noexcept
{
    return { object };
}

} // namespace sf

#define SERIALIZATION_ACCESS(...)                                                                       \
    friend class ::Serialization;

// Alternative instantiable registration with library trait no-rtti
#ifndef SERIALIZABLE
    #define SERIALIZABLE(...)                                                                           \
        SERIALIZATION_ACCESS(__VA_ARGS__)                                                               \
        SERIALIZATION_FIXTURE(__VA_ARGS__)                                                              \
        SERIALIZATION_TRAIT(__VA_ARGS__)
#endif // SERIALIZABLE

namespace sf
{

// Type registry for instantiable & any serialization, allowed registered and supported types only
template <typename T> void serializable()
{
    static_assert(not meta::is_unsupported<T>::value, "The 'T' is an unsupported type for serialization.");
    static_assert(meta::is_registered<T>::value, "The 'T' is an unregistered type for serialization.");

    dynamic::InstantiableFixture<T>::call();

#if __cplusplus >= 201703L && !defined(SF_ANY_SUPPORT_DISABLE)
    dynamic::AnyFixture<T>::call();
#endif // if
}

template <typename T> T&& serializable(T&& object)
{
    serializable<meta::decay<T>>();
    return std::forward<T>(object);
}

} // namepsace sf

EXPORT_SERIALIZATION_ARCHIVE(0, I, IArchive<wrapper::IByteStream<wrapper::ByteContainer>>)
EXPORT_SERIALIZATION_ARCHIVE(0, O, OArchive<wrapper::OByteStream<wrapper::ByteContainer>>)

#ifndef SF_DEFAULT_DISABLE

#include <fstream> // ifstream, ofstream

EXPORT_SERIALIZATION_ARCHIVE(1, I, IArchive<wrapper::IFileStream<std::ifstream>>)
EXPORT_SERIALIZATION_ARCHIVE(1, O, OArchive<wrapper::OFileStream<std::ofstream>>)

#endif // SF_DEFAULT_DISABLE

namespace sf
{

template <typename T>
class alias
{
private:
    T* data_;

public:
    using type = T;

    // DONT use dereferencing of null data before rebinding
    alias() noexcept : data_(nullptr) {}

    template <typename dT,
              SFREQUIRE(::Serialization::is_pointer_cast_allowed<dT, T>::value)>
    alias(dT& data) noexcept
        : data_(std::addressof(data)) {}

    template <typename dT>
    alias(const alias<dT>& data) noexcept : alias(data.get()) {}

public:
    // rebinding data
    alias(const alias&) = default;
    alias& operator=(const alias&) = default;

    bool is_refer() const noexcept { return data_ != nullptr; }

    template <typename dT>
    bool is_refer(dT& data)  const noexcept { return data_ == std::addressof(data); }

    operator T&() const noexcept { return get(); }

    T& get() const noexcept { return *data_; }
    void set(T& data) noexcept { data_ = std::addressof(data); }
};

namespace meta
{

template <typename> struct is_alias : std::false_type {};
template <typename T>
struct is_alias<alias<T>> : std::true_type {};

} // namespace meta

// inline namespace common also used in namespace library
inline namespace common
{

EXTERN_CONDITIONAL_SERIALIZATION(Save, alias, meta::is_alias<T>::value)
{
    using key_type = typename Archive::TrackingKeyType;

    if (not alias.is_refer())
        throw "The write alias must be initialized.";

    auto pointer = std::addressof(alias.get());
    auto key = detail::refer_key(archive, pointer);

    auto& is_tracking = archive.template tracking<tracking::Raw>()[key];

    if (not is_tracking)
        throw "The write alias must be tracked before.";

    detail::native_save(archive, pointer, key);

    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(Load, alias, meta::is_alias<T>::value)
{
    using key_type   = typename Archive::TrackingKeyType;
    using value_type = typename T::type;

    using track_type = tracking::Raw;

#ifndef SF_GARBAGE_CHECK_DISABLE
    if (alias.is_refer())
        throw "The read alias must be null.";
#endif // SF_GARBAGE_CHECK_DISABLE

    key_type key{};
    archive & key;

    auto& item = archive.template tracking<tracking::Raw>()[key];

    if (item.address == nullptr)
        throw "The read alias must be tracked before.";

    value_type* pointer = nullptr;

    detail::native_load(archive, pointer, item.address);

    alias.set(*pointer); // pointer will never nullptr

    return archive;
}

} // inline namespace common

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_alias<T>::value)

namespace sf
{

namespace utility
{

template <typename T, std::size_t N>
class Span;

template <typename T, std::size_t N>
class SpanBase
{
public:
    using size_type         = std::size_t;
    using value_type        = Span<T, N - 1>;

    using pointer           = meta::pointer<T, N>;
    using const_pointer     = const meta::pointer<T, N>;

protected:
    using Dimension         = size_type[N];

protected:
    alias<pointer> data_;
    Dimension dim_;

protected:
    SpanBase(pointer& data) noexcept
        : data_(data), dim_() {}

    template <typename D, typename... Dn>
    SpanBase(pointer& data, D d, Dn... dn) noexcept
        : data_(data), dim_{d, dn...} {}

public:
    void init(pointer data) noexcept { data_.get() = data; }
    void data(alias<pointer> data) noexcept { data_ = data; }

    pointer& data() noexcept { return data_; }
    size_type size() const noexcept { return dim_[0]; }
    Dimension& dim() noexcept { return dim_; }
};

template <typename T, std::size_t N>
class Span : public SpanBase<T, N>
{
protected:
    using Core = SpanBase<T, N>;

public:
    using typename Core::size_type;
    using typename Core::pointer;

public:
    using value_type        = Span<T, N - 1>;
    using dereference_type  = meta::pointer<T, N - 1>;

    using reference         = value_type&;
    using const_reference   = const value_type&;

protected:
    using typename Core::Dimension;

private:
    mutable value_type child_scope_;

public:
    Span(pointer& data, Dimension dim) noexcept
        : Core(data), child_scope_(data[0], dim + 1)
    {
        for (size_type i = 0; i < N; ++i)
            this->dim_[i] = dim;
    }

    template <typename D, typename... Dn,
              SFREQUIRE(not std::is_array<D>::value)>
    Span(pointer& data, D d, Dn... dn) noexcept
        : Core(data, d, dn...), child_scope_(data[0], dn...) {}

    void size(size_type value) noexcept { this->dim_[0] = value; }

    reference operator[] (size_type i) noexcept
    {
        child_scope_.data(this->data_[i]);
        return child_scope_;
    }

public:
    using Core::size; // prevent Core function hiding
};

template <typename T>
class Span<T, 1> : public SpanBase<T, 1>
{
protected:
    using Core = SpanBase<T, 1>;

public:
    using typename Core::size_type;
    using typename Core::pointer;

public:
    using value_type        = T;
    using dereference_type  = T;

    using reference         = T&;
    using const_reference   = const T&;

protected:
    using typename Core::Dimension;

public:
    Span(pointer& data, Dimension size) noexcept
        : Core(data)
    {
        this->dim_[0] = size[0];
    }

    Span(pointer& data, size_type size) noexcept
        : Core(data, size) {}

    reference operator[] (size_type i) noexcept { return this->data_[i]; }
};

} // namespace utility

namespace meta
{

template <typename> struct is_span : std::false_type {};
template <typename T, std::size_t N>
struct is_span<utility::Span<T, N>> : std::true_type {};

template <typename Pointer, typename D, typename... Dn>
struct is_span_set
    : meta::all<meta::boolean<meta::pointer_count<Pointer>() >= sizeof...(Dn) + 1>,
                meta::all<std::is_arithmetic<D>,
                          std::is_arithmetic<Dn>...>> {};

} // namespace meta

namespace utility
{

template <typename Pointer, typename D, typename... Dn,
          std::size_t N = sizeof...(Dn) + 1,
          typename Type = meta::remove_pointer<Pointer, N>,
          SFREQUIRE(meta::is_span_set<Pointer, D, Dn...>::value)>
Span<Type, N> make_span(Pointer& data, D d, Dn... dn)
{
    using size_type = typename Span<Type, N>::size_type;
    return { data, static_cast<size_type>(d), static_cast<size_type>(dn)... };
}

} // namespace utility

namespace detail
{

template <class Archive, typename T,
          SFREQUIRE(meta::all<meta::is_archive<Archive>,
                              meta::negation<meta::is_span<T>>>::value)>
void span_implementation(Archive& archive, T& data)
{
    archive & data;
}

// serialization of scoped data with previous dimension initialization
template <class OArchive, typename T,
          SFREQUIRE(meta::all<meta::is_oarchive<OArchive>,
                              meta::is_span<T>>::value)>
void span_implementation(OArchive& archive, T& array)
{
    using size_type = typename T::size_type;

    for (size_type i = 0; i < array.size(); ++i)
        span_implementation(archive, array[i]);
}

template <class IArchive, typename T,
          SFREQUIRE(meta::all<meta::is_iarchive<IArchive>,
                              meta::is_span<T>>::value)>
void span_implementation(IArchive& archive, T& array)
{
    using size_type        = typename T::size_type;
    using dereference_type = typename T::dereference_type;

    using pointer          = typename T::pointer;

    auto ptr = new dereference_type [array.size()] {};
    array.init(ptr);

    for (size_type i = 0; i < array.size(); ++i)
        span_implementation(archive, array[i]);
}

} // namespace detail

// inline namespace common also used in namespace library
inline namespace common
{

template <class Archive, typename T,
          typename D, typename... Dn,
          SFREQUIRE(meta::all<meta::is_archive<Archive>,
                              meta::is_span_set<T, D, Dn...>>::value)>
void span(Archive& archive, T& pointer, D& dimension, Dn&... dimension_n)
{
    if (not detail::refer_key(archive, pointer)) return; // serialize refer info
    archive(dimension, dimension_n...);

    auto span_data = utility::make_span(pointer, dimension, dimension_n...);
    detail::span_implementation(archive, span_data);
}

} // inline namespace common

namespace apply
{

template <typename T, typename D, typename... Dn>
struct SpanFunctor : ApplyFunctor
{
    using Pack = std::tuple<T&, D&, Dn&...>;

    Pack pack;

    SpanFunctor(T& pointer, D& d, Dn&... dn) noexcept : pack(pointer, d, dn...) {}

    template <class Archive>
    void operator() (Archive& archive) const
    {
        invoke(archive, meta::make_index_sequence<std::tuple_size<Pack>::value>{});
    }

private:
    template <class Archive, std::size_t... I>
    void invoke(Archive& archive, meta::index_sequence<I...>) const
    {
        span(archive, std::get<I>(pack)...);
    }
};

} // namespace apply

// inline namespace common also used in namespace library
inline namespace common
{

template <typename T, typename D, typename... Dn,
          SFREQUIRE(meta::is_span_set<T, D, Dn...>::value)>
apply::SpanFunctor<T, D, Dn...> span(T& pointer, D& dimension, Dn&... dimension_n) noexcept
{
    return { pointer, dimension, dimension_n... };
}

} // inline namespace common

} // namespace sf

#define _BITPACK_N(...) SFCONCAT(_BITPACK_, SFVA_ARGS_SIZE(__VA_ARGS__))(__VA_ARGS__)
#define _BITPACK_BODY(archive, ...) archive); _BITPACK_N(__VA_ARGS__) }
#define _BITPACK_IMPLEMENTATION(...) { auto __bitpack = ::sf::bitpack<__VA_ARGS__>( _BITPACK_BODY

#define _BITFIELD(field_and_bits) SFFIRST_ARGUMENT field_and_bits = __bitpack field_and_bits;

#define _BITPACK_1(field_and_bits) _BITFIELD(field_and_bits)
#define _BITPACK_2(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_1(__VA_ARGS__)
#define _BITPACK_3(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_2(__VA_ARGS__)
#define _BITPACK_4(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_3(__VA_ARGS__)
#define _BITPACK_5(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_4(__VA_ARGS__)
#define _BITPACK_6(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_5(__VA_ARGS__)
#define _BITPACK_7(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_6(__VA_ARGS__)
#define _BITPACK_8(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_7(__VA_ARGS__)

#define _BITPACK_9(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_8(__VA_ARGS__)
#define _BITPACK_10(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_9(__VA_ARGS__)
#define _BITPACK_11(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_10(__VA_ARGS__)
#define _BITPACK_12(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_11(__VA_ARGS__)
#define _BITPACK_13(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_12(__VA_ARGS__)
#define _BITPACK_14(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_13(__VA_ARGS__)
#define _BITPACK_15(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_14(__VA_ARGS__)
#define _BITPACK_16(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_15(__VA_ARGS__)

#define _BITPACK_17(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_16(__VA_ARGS__)
#define _BITPACK_18(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_17(__VA_ARGS__)
#define _BITPACK_19(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_18(__VA_ARGS__)
#define _BITPACK_20(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_19(__VA_ARGS__)
#define _BITPACK_21(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_20(__VA_ARGS__)
#define _BITPACK_22(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_21(__VA_ARGS__)
#define _BITPACK_23(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_22(__VA_ARGS__)
#define _BITPACK_24(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_23(__VA_ARGS__)

#define _BITPACK_25(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_24(__VA_ARGS__)
#define _BITPACK_26(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_25(__VA_ARGS__)
#define _BITPACK_27(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_26(__VA_ARGS__)
#define _BITPACK_28(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_27(__VA_ARGS__)
#define _BITPACK_29(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_28(__VA_ARGS__)
#define _BITPACK_30(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_29(__VA_ARGS__)
#define _BITPACK_31(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_30(__VA_ARGS__)
#define _BITPACK_32(field_and_bits, ...) _BITFIELD(field_and_bits) _BITPACK_31(__VA_ARGS__)
// and etc.

// Signature:
// BITPACK(common_fields_type)(archive, (object.field0, field0_bits), (object.field1, field1_bits), ...)
#define BITPACK(...) _BITPACK_IMPLEMENTATION(__VA_ARGS__)

// Signature:
// FBITPACK(archive, (object.field0, field0_bits), (object.field1, field1_bits), ...)
#define FBITPACK(...) BITPACK()(__VA_ARGS__)

// FBITPACK use fixed common_fields_type size version.
// BITPACK macro will generate code:
// {
//     auto __bitpack = ::sf::bitpack<common_fields_type>(archive);
//     object.field0 = __bitpack(object.field0, field0_bits);
//     object.field1 = __bitpack(object.field1, field1_bits);
//     and etc.
// }

namespace sf
{

namespace detail
{

template <class Archive, typename T, typename enable = void>
struct BitPack;

template <class Archive, typename T>
struct BitPack<Archive, T, SFWHEN(sf::meta::is_oarchive<Archive>::value)>
{
    Archive& archive;
    T data{};
    std::size_t offset{};

    BitPack(Archive& archive) : archive(archive) {}
    ~BitPack() { archive & data; }

    T operator()(T field, std::size_t bits) noexcept
    {
        // same as data = data | (field << offset);
        data |= field << offset;
        offset += bits;

        return field;
    }
};

template <class Archive, typename T>
struct BitPack<Archive, T, SFWHEN(sf::meta::is_iarchive<Archive>::value)>
{
    Archive& archive;
    T data{};

    BitPack(Archive& archive) : archive(archive) { archive & data; }

    T operator()(T field, std::size_t bits) noexcept
    {
        //same as field = data & ~(0xf...f << bits)
        field = data & ~(~T{} << bits);
        data >>= bits;

        return field;
    }
};

} // namespace detail

template <typename PackType = let::u32, class Archive>
detail::BitPack<Archive, PackType> bitpack(Archive& archive) noexcept { return { archive }; }

} // namespace sf

namespace sf
{

namespace meta
{

template <typename> struct is_std_vector : std::false_type {};
template <typename T, typename Alloc>
struct is_std_vector<std::vector<T, Alloc>> : std::true_type {};

} // namespace meta

inline namespace library
{

EXTERN_CONDITIONAL_SERIALIZATION(Save, vector, meta::is_std_vector<T>::value)
{
    let::u64 size = vector.size();
    archive & size;

    compress::zip(archive, vector);

    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(Load, vector, meta::is_std_vector<T>::value)
{
    let::u64 size{};
    archive & size;

    vector.resize(size);
    compress::zip(archive, vector);

    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_vector<T>::value)
TYPE_REGISTRY(std::vector<bool>)

namespace sf
{

inline namespace library
{

// slow implementation
EXTERN_SERIALIZATION(Save, vector, std::vector<bool>)
{
    let::u64 size = vector.size();
    archive & size;

    for(auto item:vector)
    {
        bool boolean = item;
        archive & boolean;
    }

    return archive;
}

EXTERN_SERIALIZATION(Load, vector, std::vector<bool>)
{
    let::u64 size{};
    archive & size;

    vector.resize(size);

    for(auto item/*bit_reference*/:vector)
    {
        bool boolean{};
        archive & boolean;
        item = boolean;
    }

    return archive;
}

} // inline namespace library

} // namespace sf

namespace sf
{

inline namespace library
{

EXTERN_CONDITIONAL_SERIALIZATION(SaveLoad, array, meta::is_std_array<T>::value)
{
    compress::zip(archive, array);
    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_array<T>::value)

#include <string> // basic_string

namespace sf
{

namespace meta
{

template <typename>
struct is_std_basic_string : std::false_type {};

template <typename Char, typename Traits, typename Alloc>
struct is_std_basic_string<std::basic_string<Char, Traits, Alloc>> : std::true_type {};

} // namespace meta

inline namespace library
{

EXTERN_CONDITIONAL_SERIALIZATION(Save, string, meta::is_std_basic_string<T>::value)
{
    using char_type = typename T::value_type;

    let::u64 size = string.size();
    archive & size;

    compress::zip(archive, string);

    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(Load, string, meta::is_std_basic_string<T>::value)
{
    using char_type = typename T::value_type;

    let::u64 size{};
    archive & size;

    string.resize(size);
    compress::zip(archive, string);

    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_basic_string<T>::value)

namespace sf
{

namespace meta
{

template <typename> struct is_std_pair : std::false_type {};
template <typename T1, typename T2>
struct is_std_pair<std::pair<T1, T2>> : std::true_type {};

} // namespace meta

inline namespace library
{

EXTERN_CONDITIONAL_SERIALIZATION(SaveLoad, pair, meta::is_std_pair<T>::value)
{
    archive & pair.first & pair.second;
    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_pair<T>::value)

namespace sf
{

namespace meta
{

template <typename> struct is_std_tuple : std::false_type {};
template <typename... Tn>
struct is_std_tuple<std::tuple<Tn...>> : std::true_type {};

} // namespace meta

namespace detail
{

template <class Archive, class T, std::size_t... I,
          SFREQUIRE(meta::is_std_tuple<T>::value)>
void expand(Archive& archive, T& tuple, meta::index_sequence<I...>)
{
    archive(std::get<I>(tuple)...);
}

} // namespace detail

inline namespace library
{

EXTERN_CONDITIONAL_SERIALIZATION(SaveLoad, tuple, meta::is_std_tuple<T>::value)
{
    constexpr auto size = std::tuple_size<T>::value;
    detail::expand(archive, tuple, meta::make_index_sequence<size>{});

    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_tuple<T>::value)

#include <list> // list

namespace sf
{

namespace meta
{

template <typename> struct is_std_list : std::false_type {};
template <typename T, typename Alloc>
struct is_std_list<std::list<T, Alloc>> : std::true_type {};

} // namespace meta

inline namespace library
{

EXTERN_CONDITIONAL_SERIALIZATION(Save, list, meta::is_std_list<T>::value)
{
    let::u64 size = list.size();
    archive & size;

    compress::slow(archive, list);

    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(Load, list, meta::is_std_list<T>::value)
{
    let::u64 size{};
    archive & size;

    list.resize(size);
    compress::slow(archive, list);

    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_list<T>::value)

#include <forward_list> // forward_list

namespace sf
{

namespace meta
{

template <typename> struct is_std_forward_list : std::false_type {};
template <typename T, typename Alloc>
struct is_std_forward_list<std::forward_list<T, Alloc>> : std::true_type {};

} // namespace meta

inline namespace library
{

EXTERN_CONDITIONAL_SERIALIZATION(Save, forward_list, meta::is_std_forward_list<T>::value)
{
    let::u64 size = std::distance(forward_list.begin(), forward_list.end());
    archive & size;

    compress::slow(archive, forward_list);

    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(Load, forward_list, meta::is_std_forward_list<T>::value)
{
    let::u64 size{};
    archive & size;

    forward_list.resize(size);
    compress::slow(archive, forward_list);

    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_forward_list<T>::value)

#include <set> // set, multiset
#include <unordered_set> // unordered_set, unordered_multiset

#define _SF_IS_STD_SET_TYPE_META_GENERIC(set_type)                                                      \
    template <typename> struct is_std_##set_type : std::false_type {};                                  \
    template <typename Key, typename Compare, typename Alloc>                                           \
    struct is_std_##set_type<std::set_type<Key, Compare, Alloc>> : std::true_type {};

namespace sf
{

namespace meta
{

_SF_IS_STD_SET_TYPE_META_GENERIC(set)
_SF_IS_STD_SET_TYPE_META_GENERIC(unordered_set)
_SF_IS_STD_SET_TYPE_META_GENERIC(multiset)
_SF_IS_STD_SET_TYPE_META_GENERIC(unordered_multiset)

template <class T> struct is_std_any_unordered_set
    : one<is_std_unordered_set<T>,
          is_std_unordered_multiset<T>> {};

template <class T> struct is_std_any_set
    : one<is_std_set<T>,
          is_std_multiset<T>,
          is_std_any_unordered_set<T>> {};

} // namespace meta

namespace detail
{

template <class T,
          SFREQUIRE(not meta::is_std_any_unordered_set<T>::value)>
void reserve_unordered(T& ordered, std::size_t size) noexcept { /*pass*/ }

template <class T,
          SFREQUIRE(meta::is_std_any_unordered_set<T>::value)>
void reserve_unordered(T& unordered, std::size_t size)
{
    unordered.reserve(size);
}

} // namespace detail

inline namespace library
{

EXTERN_CONDITIONAL_SERIALIZATION(Save, set, meta::is_std_any_set<T>::value)
{
    let::u64 size = set.size();
    archive & size;

    compress::slow(archive, set);

    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(Load, set, meta::is_std_any_set<T>::value)
{
    using value_type = typename T::value_type;

    let::u64 size{};
    archive & size;

    set.clear();
    detail::reserve_unordered(set, size);

    auto hint = set.begin();
    for (let::u64 i = 0; i < size; ++i)
    {
        value_type item{}; // temp
        archive & item;

        hint = set.emplace_hint(hint, std::move(item));
    }

    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_any_set<T>::value)

// clean up
#undef _SF_IS_STD_SET_TYPE_META_GENERIC

namespace sf
{

namespace meta
{

template <typename> struct is_std_unique_ptr : std::false_type {};
template <typename T, typename Deleter>
struct is_std_unique_ptr<std::unique_ptr<T, Deleter>> : std::true_type {};

} // namespace meta

inline namespace library
{

EXTERN_CONDITIONAL_SERIALIZATION(Save, unique_ptr, meta::is_std_unique_ptr<T>::value)
{
    auto data = unique_ptr.get();
    archive & data;

    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(Load, unique_ptr, meta::is_std_unique_ptr<T>::value)
{
    using item_type = typename Memory::ptr_trait<T>::item;

    item_type* data = nullptr;
    archive & data;

    unique_ptr.reset(data);

    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_unique_ptr<T>::value)

namespace sf
{

inline namespace library
{

EXTERN_CONDITIONAL_SERIALIZATION(SaveLoad, shared_ptr, meta::is_std_shared_ptr<T>::value)
{
    tracking::track(archive, shared_ptr);
    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_shared_ptr<T>::value)

// serialization of shared_ptr

namespace sf
{

namespace meta
{

template <typename> struct is_std_weak_ptr : std::false_type {};
template <typename T> struct is_std_weak_ptr<std::weak_ptr<T>> : std::true_type {};

} // namespace meta

inline namespace library
{

EXTERN_CONDITIONAL_SERIALIZATION(Save, weak_ptr, meta::is_std_weak_ptr<T>::value)
{
    auto sptr = weak_ptr.lock();
    archive & sptr;

    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(Load, weak_ptr, meta::is_std_weak_ptr<T>::value)
{
    using item_type = typename Memory::ptr_trait<T>::item;

    std::shared_ptr<item_type> sptr;
    archive & sptr;

    weak_ptr = sptr;

    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_weak_ptr<T>::value)

#include <map> // map, multimap

// serialization of core map value_type

#define _SF_IS_STD_MAP_TYPE_META_GENERIC(map_type)                                                      \
    template <typename> struct is_std_##map_type : std::false_type {};                                  \
    template <typename Key, typename Type, typename Compare, typename Alloc>                            \
    struct is_std_##map_type<std::map_type<Key, Type, Compare, Alloc>> : std::true_type {};

namespace sf
{

namespace meta
{

_SF_IS_STD_MAP_TYPE_META_GENERIC(map)
_SF_IS_STD_MAP_TYPE_META_GENERIC(unordered_map)
_SF_IS_STD_MAP_TYPE_META_GENERIC(multimap)
_SF_IS_STD_MAP_TYPE_META_GENERIC(unordered_multimap)

template <class T> struct is_std_any_unordered_map
    : one<is_std_unordered_map<T>,
          is_std_unordered_multimap<T>> {};

template <class T> struct is_std_any_map
    : one<is_std_map<T>,
          is_std_multimap<T>,
          is_std_any_unordered_map<T>> {};

} // namespace meta

namespace detail
{

template <class T,
          SFREQUIRE(not meta::is_std_any_unordered_map<T>::value)>
void reserve_unordered(T& ordered, std::size_t size) noexcept { /*pass*/ }

template <class T,
          SFREQUIRE(meta::is_std_any_unordered_map<T>::value)>
void reserve_unordered(T& unordered, std::size_t size)
{
    unordered.reserve(size);
}

} // namespace detail

inline namespace library
{

EXTERN_CONDITIONAL_SERIALIZATION(Save, map, meta::is_std_any_map<T>::value)
{
    let::u64 size = map.size();
    archive & size;

    compress::slow(archive, map);

    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(Load, map, meta::is_std_any_map<T>::value)
{
    using key_type   = typename T::key_type;
    using value_type = typename T::mapped_type;

    let::u64 size{};
    archive & size;

    map.clear();
    detail::reserve_unordered(map, size);

    auto hint = map.begin();
    for (let::u64 i = 0; i < size; ++i)
    {
        key_type key{};
        value_type value{};

        archive & key & value;

        hint = map.emplace_hint(hint, std::move(key), std::move(value));
    }

    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_any_map<T>::value)

//clear
#undef _SF_IS_STD_MAP_TYPE_META_GENERIC

#include <deque> // deque

namespace sf
{

namespace meta
{

template <typename> struct is_std_deque : std::false_type {};
template <typename T, typename Alloc>
struct is_std_deque<std::deque<T, Alloc>> : std::true_type {};

} // namespace meta

inline namespace library
{

EXTERN_CONDITIONAL_SERIALIZATION(Save, deque, meta::is_std_deque<T>::value)
{
    let::u64 size = deque.size();
    archive & size;

    compress::slow(archive, deque);

    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(Load, deque, meta::is_std_deque<T>::value)
{
    let::u64 size{};
    archive & size;

    deque.resize(size);
    compress::slow(archive, deque);

    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_deque<T>::value)

#include <stack> // stack

namespace sf
{

namespace meta
{

template <template <typename...> class Adapter,
          typename Type, class Container, typename... Args>
Container& underlying(Adapter<Type, Container, Args...>& adapter) noexcept
{
    using Core = Adapter<Type, Container, Args...>;

    struct base_inner : public Core
    {
        static Container& underlying(Core& core)
        {
            auto underlying_container = &base_inner::c;
            return core.*underlying_container;
        }
    };

    return base_inner::underlying(adapter);
}

} // namespace meta

} // namespace sf

// default container for stack

namespace sf
{

namespace meta
{

template <typename> struct is_std_stack : std::false_type {};
template <typename T, class Container>
struct is_std_stack<std::stack<T, Container>> : std::true_type {};

} // namespace meta

inline namespace library
{

EXTERN_CONDITIONAL_SERIALIZATION(SaveLoad, stack, meta::is_std_stack<T>::value)
{
    archive & meta::underlying(stack);
    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_stack<T>::value)

#include <queue> // queue

// default container for queue

// default container for priority_queue

namespace sf
{

namespace meta
{

template <typename> struct is_std_queue : std::false_type {};
template <typename T, class Container>
struct is_std_queue<std::queue<T, Container>> : std::true_type {};

template <typename> struct is_std_priority_queue : std::false_type {};
template <typename T, class Container, class Compare>
struct is_std_priority_queue<std::priority_queue<T, Container, Compare>> : std::true_type {};

template <class T> struct is_std_any_queue
    : one<is_std_queue<T>,
          is_std_priority_queue<T>> {};

} // namespace meta

inline namespace library
{

EXTERN_CONDITIONAL_SERIALIZATION(SaveLoad, queue, meta::is_std_any_queue<T>::value)
{
    archive & meta::underlying(queue);
    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_any_queue<T>::value)

namespace sf
{

namespace meta
{

template <typename> struct is_std_valarray : std::false_type {};
template <typename T> struct is_std_valarray<std::valarray<T>> : std::true_type {};

} // namespace meta

inline namespace library
{

EXTERN_CONDITIONAL_SERIALIZATION(Save, valarray, meta::is_std_valarray<T>::value)
{
    let::u64 size = valarray.size();
    archive & size;

    compress::zip(archive, valarray);

    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(Load, valarray, meta::is_std_valarray<T>::value)
{
    let::u64 size{};
    archive & size;

    valarray.resize(size);
    compress::zip(archive, valarray);

    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_valarray<T>::value)

#include <bitset> // bitset

// default array for bitset convertion

namespace sf
{

namespace meta
{

template <typename> struct is_std_bitset : std::false_type {};
template <std::size_t N> struct is_std_bitset<std::bitset<N>> : std::true_type {};

} // namespace meta

inline namespace library
{

// slow implementation
EXTERN_CONDITIONAL_SERIALIZATION(Save, bitset, meta::is_std_bitset<T>::value)
{
    auto data = bitset.to_string();
    archive & data;

    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(Load, bitset, meta::is_std_bitset<T>::value)
{
    std::string data;
    archive & data;

    bitset = T(data);

    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_bitset<T>::value)

#include <atomic> // atomic

namespace sf
{

namespace meta
{

template <typename> struct is_std_atomic : std::false_type {};
template <typename T> struct is_std_atomic<std::atomic<T>> : std::true_type {};

template <typename T> struct atomic_trait;
template <typename T> struct atomic_trait<std::atomic<T>> { using value_type = T; };

} // namespace meta

inline namespace library
{

EXTERN_CONDITIONAL_SERIALIZATION(Save, atomic, meta::is_std_atomic<T>::value)
{
    auto object = atomic.load();
    archive & object;

    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(Load, atomic, meta::is_std_atomic<T>::value)
{
    using object_type = typename meta::atomic_trait<T>::value_type;

    object_type object{};
    archive & object;

    atomic.store(object);

    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_atomic<T>::value)

#include <complex> // complex

namespace sf
{

namespace meta
{

template <typename> struct is_std_complex : std::false_type {};
template <typename T> struct is_std_complex<std::complex<T>> : std::true_type {};

} // namespace meta

inline namespace library
{

EXTERN_CONDITIONAL_SERIALIZATION(Save, complex, meta::is_std_complex<T>::value)
{
    auto re = complex.real();
    auto im = complex.imag();

    archive & re & im;

    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(Load, complex, meta::is_std_complex<T>::value)
{
    using integral_type = typename T::value_type;

    integral_type re{};
    integral_type im{};

    archive & re & im;

    complex.real(re);
    complex.imag(im);

    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_complex<T>::value)

#if __cplusplus >= 201703L

#include <optional> // optional

namespace sf
{

namespace meta
{

template <typename> struct is_std_optional : std::false_type {};
template <typename T> struct is_std_optional<std::optional<T>> : std::true_type {};

} // namespace meta

inline namespace library
{

EXTERN_CONDITIONAL_SERIALIZATION(Save, optional, meta::is_std_optional<T>::value)
{
    auto is_init = optional.has_value();
    archive & is_init;

    if (is_init) archive & optional.value();

    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(Load, optional, meta::is_std_optional<T>::value)
{
    auto is_init = false;
    archive & is_init;

    if (is_init)
    {
        optional.emplace();
        archive & optional.value();
    }

    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_optional<T>::value)

#endif // if

#if __cplusplus >= 201703L

#include <variant> // variant

// serialization of std::monostate

namespace sf
{

namespace meta
{

template <typename> struct is_std_variant : std::false_type {};
template <typename... Tn> struct is_std_variant<std::variant<Tn...>> : std::true_type {};

} // namespace meta

namespace detail
{

template <let::u64 I, class Archive, class Variant,
          SFREQUIRE(I == std::variant_size<Variant>::value)>
void variant_save(Archive& archive, Variant& variant, let::u64 index) noexcept { /*pass*/ }

template <let::u64 I = 0, class Archive, class Variant,
          SFREQUIRE(I < std::variant_size<Variant>::value)>
void variant_save(Archive& archive, Variant& variant, let::u64 index)
{
    if (I < index) return variant_save<I + 1>(archive, variant, index);
    archive & std::get<I>(variant);
}

template <typename Type, class Archive, class Variant,
          SFREQUIRE(not std::is_constructible<Type>::value)>
void variant_load_implementation(Archive& archive, Variant& variant)
{
    throw "Require default constructor for specify type.";
}

template <typename Type, class Archive, class Variant,
          SFREQUIRE(std::is_constructible<Type>::value)>
void variant_load_implementation(Archive& archive, Variant& variant)
{
    archive & variant.template emplace<Type>();
}

template <let::u64 I, class Archive, class Variant,
          SFREQUIRE(I == std::variant_size<Variant>::value)>
void variant_load(Archive& archive, Variant& variant, let::u64 index) noexcept { /*pass*/ }

template <let::u64 I = 0, class Archive, class Variant,
          SFREQUIRE(I < std::variant_size<Variant>::value)>
void variant_load(Archive& archive, Variant& variant, let::u64 index)
{
    if (I < index) return variant_load<I + 1>(archive, variant, index);

    using type = typename std::variant_alternative<I, Variant>::type;
    variant_load_implementation<type>(archive, variant);
}

} // namespace detail

inline namespace library
{

EXTERN_CONDITIONAL_SERIALIZATION(Save, variant, meta::is_std_variant<T>::value)
{
    let::u64 index = variant.index();
    archive & index;

    if (index != std::variant_npos)
        detail::variant_save(archive, variant, index);

    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(Load, variant, meta::is_std_variant<T>::value)
{
    let::u64 index{};
    archive & index;

    if (index != std::variant_npos)
        detail::variant_load(archive, variant, index);

    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_variant<T>::value)

#endif // if

#if __cplusplus >= 201703L && !defined(SF_ANY_SUPPORT_DISABLE)

namespace sf
{

namespace meta
{

template <typename> struct is_std_any : std::false_type {};
template <> struct is_std_any<std::any> : std::true_type {};

} // namespace meta

inline namespace library
{

// please, use 'sf::serializable' for type any registry before std::any serialization
EXTERN_CONDITIONAL_SERIALIZATION(Save, any, meta::is_std_any<T>::value)
{
    let::u64 hash = SF_TYPE_HASH(any.type());
    archive & hash;

    dynamic::AnyRegistry::instance().save(archive, any, hash);

    return archive;
}

EXTERN_CONDITIONAL_SERIALIZATION(Load, any, meta::is_std_any<T>::value)
{
    let::u64 hash{};
    archive & hash;

    dynamic::AnyRegistry::instance().load(archive, any, hash);

    return archive;
}

} // inline namespace library

} // namespace sf

CONDITIONAL_TYPE_REGISTRY(meta::is_std_any<T>::value)

#endif // if

namespace trixy
{

namespace meta
{

template <class Archive> constexpr bool is_iarchive(Archive& archive) noexcept
{
    return sf::meta::is_iarchive<Archive>::value;
}

template <class Archive> constexpr bool is_oarchive(Archive& archive) noexcept
{
    return sf::meta::is_oarchive<Archive>::value;
}

} // namespace meta

} // namespace trixy

namespace trixy
{

namespace utility
{

template <typename Type>
class Container
{
    SERIALIZATION_ACCESS()

public:
    class iterator;
    class const_iterator;

public:
    using size_type       = std::size_t;
    using value_type      = Type;
    using difference_type = std::ptrdiff_t;

    using pointer         = Type*;
    using const_pointer   = const Type*;

    using reference       = Type&;
    using const_reference = const Type&;

private:
    pointer data_;
    size_type size_;
    size_type capacity_;

public:
    Container() noexcept;
    ~Container();

    explicit Container(size_type size);
    Container(const Container&);
    Container(Container&&) noexcept;
    Container(std::initializer_list<value_type>);

    Container& operator= (const Container&);
    Container& operator= (Container&&) noexcept;

    size_type capacity() const noexcept { return capacity_; }
    size_type size() const noexcept { return size_; }
    size_type max_size() const noexcept { return size_type(-1) / sizeof(value_type); }

    template <typename... Args>
    void resize(size_type n, Args&&... args);

    void reserve(size_type n);

    template <typename... Args>
    void emplace_back(Args&&... args);

    void pop_back();

    bool empty() const noexcept { return size_ == 0; }

    iterator begin() noexcept { return iterator(data_); }
    iterator end() noexcept { return iterator(data_ + size_); }

    const_iterator begin() const noexcept { return const_iterator(data_); }
    const_iterator end() const noexcept { return const_iterator(data_ + size_); }

    const_iterator cbegin() const noexcept { return const_iterator(data_); }
    const_iterator cend() const noexcept { return const_iterator(data_ + size_); }

    reference front() noexcept { return data_[0]; }
    const_reference front() const noexcept { return data_[0]; }

    reference back() noexcept { return data_[size_ - 1]; }
    const_reference back() const noexcept { return data_[size_ - 1]; }

    pointer data() noexcept { return data_; }
    const_pointer data() const noexcept { return data_; }

    reference operator[] (size_type i) noexcept { return data_[i]; }
    const_reference operator[] (size_type i) const noexcept { return data_[i]; }

private:
    static pointer allocate(size_type n);
    static void deallocate(pointer ptr);

    static void destroy(pointer first, pointer last);
};

template <typename Type>
class Container<Type>::iterator
{
private:
    pointer ptr_;

public:
    explicit iterator(pointer ptr) noexcept : ptr_(ptr) {}

    const pointer& base() const noexcept { return ptr_; }

    reference operator* () const noexcept { return *ptr_; }
    pointer operator-> () const noexcept { return ptr_; }

    bool operator!= (const iterator& it) const noexcept { return ptr_ != it.ptr_; }
    bool operator== (const iterator& it) const noexcept { return ptr_ == it.ptr_; }

    iterator operator++ () noexcept { ++ptr_; return *this; }
    iterator operator-- () noexcept { --ptr_; return *this; }

    difference_type operator- (iterator it) noexcept { return ptr_ - it.ptr_; }

    iterator operator+ (difference_type n) noexcept { ptr_ + n; return *this; }
    iterator operator- (difference_type n) noexcept { ptr_ - n; return *this; }

    reference operator[] (size_type i) noexcept { return ptr_[i]; }
};

template <typename Type>
class Container<Type>::const_iterator
{
private:
    pointer ptr_;

public:
    explicit const_iterator(pointer ptr) noexcept : ptr_(ptr) {}

    const const_pointer& base() const noexcept { return ptr_; }

    const_reference operator* () const noexcept { return *ptr_; }
    const_pointer operator-> () const noexcept { return ptr_; }

    bool operator!= (const const_iterator& it) const noexcept { return ptr_ != it.ptr_; }
    bool operator== (const const_iterator& it) const noexcept { return ptr_ == it.ptr_; }

    const_iterator operator++ () noexcept { ++ptr_; return *this; }
    const_iterator operator-- () noexcept { --ptr_; return *this; }

    difference_type operator- (const_iterator it) noexcept { return ptr_ - it.ptr_; }

    const_iterator operator+ (difference_type n) noexcept { ptr_ + n; return *this; }
    const_iterator operator- (difference_type n) noexcept { ptr_ - n; return *this; }

    const_reference operator[] (size_type i) const noexcept { return ptr_[i]; }
};

template <typename Type>
inline Container<Type>::Container() noexcept
    : data_(nullptr), size_(0), capacity_(0)
{
}

template <typename Type>
Container<Type>::~Container()
{
    Container::destroy(data_, data_ + size_);
    Container::deallocate(data_);
}

template <typename Type>
Container<Type>::Container(size_type size)
    : data_(Container::allocate(size))
    , size_(size)
    , capacity_(size)
{
    for (size_type i = 0; i < size_; ++i)
        new (data_ + i) value_type();
}

template <typename Type>
Container<Type>::Container(const Container& container)
    : data_(Container::allocate(container.size_))
    , size_(container.size_)
    , capacity_(container.capacity_)
{
    for (std::size_t i = 0; i < size_; ++i)
        new (data_ + i) value_type(container.data_[i]);
}

template <typename Type>
Container<Type>::Container(Container&& container) noexcept
{
    capacity_ = container.capacity_;

    size_ = container.size_;
    data_ = container.data_;

    container.data_ = nullptr;
}

template <typename Type>
Container<Type>::Container(std::initializer_list<value_type> list)
    : data_(Container::allocate(list.size()))
    , size_(list.size())
    , capacity_(list.size())
{
    size_type i = 0;
    for (const auto& arg: list)
    {
        new (data_ + i) value_type(arg);
        ++i;
    }
}

template <typename Type>
Container<Type>& Container<Type>::operator= (const Container& container)
{
    if(this == &container) return *this;

    Container::destroy(data_, data_ + size_);
    Container::deallocate(data_);

    capacity_ = container.capacity_;

    size_ = container.size_;
    data_ = Container::allocate(capacity_);

    for (size_type i = 0; i < size_; ++i)
        new (data_ + i) value_type(container.data_[i]);

    return *this;
}

template <typename Type>
Container<Type>& Container<Type>::operator= (Container&& container) noexcept
{
    if(this == &container) return *this;

    Container::destroy(data_, data_ + size_);
    Container::deallocate(data_);

    capacity_ = container.capacity_;

    size_ = container.size_;
    data_ = container.data_;

    container.data_ = nullptr;

    return *this;
}

template <typename Type>
template <typename... Args>
void Container<Type>::resize(size_type n, Args&&... args)
{
    // capacity is always more than or equal to size
    if (n > capacity_)
    {
        reserve(n);

        for (; size_ < n; ++size_)
            new (data_ + size_) value_type(std::forward<Args>(args)...);

        capacity_ = n;

        return;
    }

    if (n < size_)
    {
        Container::destroy(data_ + n, data_ + size_);
        size_ = n;
    }
    else
    {
        for (; size_ < n; ++size_)
            new (data_ + size_) value_type(std::forward<Args>(args)...);
    }
}

template <typename Type>
void Container<Type>::reserve(size_type n)
{
    if (n > capacity_)
    {
        pointer buff = Container::allocate(n);

        for (size_type i = 0; i < size_; ++i)
            new (buff + i) value_type(std::move(data_[i]));

        std::swap(buff, data_);

        Container::destroy(buff, buff + size_);
        Container::deallocate(buff);

        capacity_ = n;
    }
}

template <typename Type>
template <typename... Args>
void Container<Type>::emplace_back(Args&&... args)
{
    // size is always less than or equal to capacity
    if (size_ == capacity_)
        reserve(capacity_ * 2 + 1);

    new (data_ + size_) value_type(std::forward<Args>(args)...);
    ++size_;
}

template <typename Type>
void Container<Type>::pop_back()
{
    // call destructor of last element in Container
    --size_;
    data_[size_].~value_type();
}

template <typename Type>
inline typename Container<Type>::pointer Container<Type>::allocate(size_type n)
{
    // return void pointer to sizeof(value_type) * n bytes in memory
    return static_cast<pointer>(
        ::operator new[] (sizeof(value_type) * n)
    );
}

template <typename Type>
inline void Container<Type>::deallocate(pointer ptr)
{
    ::operator delete[] (ptr);
}

template <typename Type>
void Container<Type>::destroy(pointer first, pointer last)
{
    if (first == nullptr) return;

    while (first != last)
    {
        first->~value_type();
        ++first;
    }
}

} // namespace utility

namespace meta
{

template <typename T> struct is_container : std::false_type {};
template <typename Type> struct is_container<utility::Container<Type>> : std::true_type {};

} // namespace meta

} // namepace trixy

CONDITIONAL_SERIALIZATION(SaveLoad, trixy::meta::is_container<T>::value)
{
    archive & sf::span(self.data_, self.size_);
    self.capacity_ = self.size_;
}

namespace trixy
{

namespace utility
{

template <template <typename, typename...> class Derived, typename Type, typename... Pack>
class IContainer
{
public:
    class iterator;
    class const_iterator;

public:
    using size_type       = std::size_t;
    using value_type      = Type;
    using difference_type = std::ptrdiff_t;

    using pointer         = Type*;
    using const_pointer   = const Type*;

    using reference       = Type&;
    using const_reference = const Type&;

protected:
    using DerivedType     = Derived<Type, Pack...>;

private:
    DerivedType& self() noexcept
    { return *static_cast<DerivedType*>(this); }

    const DerivedType& self() const noexcept
    { return *static_cast<const DerivedType*>(this); }

public:
    size_type capacity() const noexcept { return self().capacity(); }
    size_type size() const noexcept { return self().size(); }
    size_type max_size() const noexcept { return self().max_size(); }

    void reserve(size_type n) { self().reserve(n); }

    template <typename... Args>
    void resize(size_type n, Args&&... args) { self().resize(n, std::forward<Args>(args)...); }

    template <typename... Args>
    void emplace_back(Args&&... args)
    { self().emplace_back(std::forward<Args>(args)...); }

    void pop_back() { self().pop_back(); }

    void empty() const noexcept { self().empty(); }

    iterator begin() noexcept { return self().begin(); }
    iterator end() noexcept { return self().end(); }

    const_iterator begin() const noexcept { return self().begin(); }
    const_iterator end() const noexcept { return self().end(); }

    const_iterator cbegin() const noexcept { return self().cbegin(); }
    const_iterator cend() const noexcept { return self().cend(); }

    reference front() noexcept { return self().front(); }
    const_reference front() const noexcept { return self().front(); }

    reference back() noexcept { return self().back(); }
    const_reference back() const noexcept { return self().back(); }

    pointer data() noexcept { return self().data(); }
    const_pointer data() const noexcept { return self().data(); }

    reference operator[] (size_type i) noexcept { return self().operator[](i); }
    const_reference operator[] (size_type i) const noexcept { return self().operator[](i); }
};

template <template <typename, typename...> class Derived, typename Type, typename... Pack>
class IContainer<Derived, Type, Pack...>::iterator
{
private:
    pointer ptr_;

public:
    explicit iterator(pointer ptr) noexcept : ptr_(ptr) {}

    const pointer& base() const noexcept { return ptr_; }

    reference operator* () const noexcept { return *ptr_; }
    pointer operator-> () const noexcept { return ptr_; }

    bool operator!= (const iterator& it) const noexcept { return ptr_ != it.ptr_; }
    bool operator== (const iterator& it) const noexcept { return ptr_ == it.ptr_; }

    iterator operator++ () noexcept { ++ptr_; return *this; }
    iterator operator-- () noexcept { --ptr_; return *this; }

    difference_type operator- (iterator it) noexcept { return ptr_ - it.ptr_; }

    iterator operator+ (difference_type n) noexcept { ptr_ + n; return *this; }
    iterator operator- (difference_type n) noexcept { ptr_ - n; return *this; }

    reference operator[] (size_type i) noexcept { return ptr_[i]; }
};

template <template <typename, typename...> class Derived, typename Type, typename... Pack>
class IContainer<Derived, Type, Pack...>::const_iterator
{
private:
    pointer ptr_;

public:
    explicit const_iterator(pointer ptr) noexcept : ptr_(ptr) {}

    const const_pointer& base() const noexcept { return ptr_; }

    const_reference operator* () const noexcept { return *ptr_; }
    const_pointer operator-> () const noexcept { return ptr_; }

    bool operator!= (const const_iterator& it) const noexcept { return ptr_ != it.ptr_; }
    bool operator== (const const_iterator& it) const noexcept { return ptr_ == it.ptr_; }

    const_iterator operator++ () noexcept { ++ptr_; return *this; }
    const_iterator operator-- () noexcept { --ptr_; return *this; }

    difference_type operator- (const_iterator it) noexcept { return ptr_ - it.ptr_; }

    const_iterator operator+ (difference_type n) noexcept { ptr_ + n; return *this; }
    const_iterator operator- (difference_type n) noexcept { ptr_ - n; return *this; }

    const_reference operator[] (size_type i) const noexcept { return ptr_[i]; }
};

} // namespace trixy

} // namespace utility

namespace trixy
{

namespace lique
{

template <typename Precision,
          typename TensorType = TensorType::tensor,
          typename TensorMode = TensorMode::own>
class Tensor;

} // namespace lique

} // namespace trixy

namespace trixy
{

namespace lique
{

// You MUST prevent any changes to this struct!
template <typename T>
struct Shape
{
private:
    static constexpr bool require = std::is_integral<T>::value;

    static_assert(require, "'T' should be an integral type.");

public:
    using size_type = T;

public:
    size_type depth;
    size_type height;
    size_type width;

    size_type size;

public:
    Shape() : depth(0), height(0), width(0) {}

    explicit Shape(size_type d, size_type h, size_type w)
    : depth(d), height(h), width(w), size(d * h * w) {}

    explicit Shape(size_type h, size_type w)
    : depth(1), height(h), width(w), size(h * w) {}

    explicit Shape(size_type w)
    : depth(1), height(1), width(w), size(w) {}
};

namespace meta
{

template <typename T> struct is_shape : std::false_type {};
template <typename T> struct is_shape<Shape<T>> : std::true_type {};

} // namespace meta

} // namespace lique

} // namespace trixy

CONDITIONAL_SERIALIZATION(SaveLoad, trixy::lique::meta::is_shape<T>::value)
{
    archive & self.depth & self.height & self.width & self.size;
}

namespace trixy
{

namespace utility
{

template <typename T, typename RangeType = RangeType::View>
struct Range;

} // namespace utility

} // namespace trixy

namespace trixy
{

namespace utility
{

template <typename T>
struct Range<T, RangeType::View>
{
public:
    using pointer           = T*;
    using const_pointer     = const T*;

    using value_type        = T;
    using size_type         = std::size_t;
    using difference_type   = std::ptrdiff_t;

private:
    pointer first_;
    pointer last_;

public:
    Range(pointer first, pointer last)
        : first_(first), last_(last) {}

    Range() : Range(nullptr, nullptr) {}

    Range(pointer first, pointer last, value_type value)
        : Range(first, last)
    {
        fill(first_, last_);
    }

    void fill(value_type value)
    {
        auto first = first_;
        auto last  = last_;

        while (first != last) *first++ = value;
    }

    pointer data() noexcept { return first_; }
    const_pointer data() const noexcept { return first_; }

    difference_type size() const noexcept { return last_ - first_; }

    pointer first() noexcept { return first_; }
    pointer last() noexcept { return last_; }

    const_pointer first() const noexcept { return first_; }
    const_pointer last() const noexcept { return last_; }
};

} // namespace utility

} // namespace trixy

#include <cmath> // sqrt
#include <thread> // thread

// enable_if, is_arithmetic, is_same, conditional, true_type, false_type, remove_reference

// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define TRIXY_TEMPLATE(...)                                                                             \
    template <__VA_ARGS__>

#define TRREQUIRE(...)                                                                                  \
    ::trixy::meta::require<(bool)(__VA_ARGS__)> = 0

#define TRNOEXCEPT_IF(predicate)                                                                        \
    noexcept((predicate))

#define TRWHEN(...)                                                                                     \
    ::trixy::meta::when<(bool)(__VA_ARGS__)>

#define TRWITH(type, ...)                                                                               \
    ::trixy::meta::when<__VA_ARGS__<type>::value>

#define TRIXY_HAS_FUNCTION_HELPER(name)                                                                 \
    template <typename C, typename = ::trixy::meta::to_void<>>                                          \
    struct has_##name : std::false_type {};								\
    template <typename C>                                                                               \
    struct has_##name<C, ::trixy::meta::to_void<decltype(&C::name)>>                                    \
        : std::true_type {}

#define TRIXY_HAS_TYPE_HELPER(name)                                                                     \
    template <typename T, typename = ::trixy::meta::to_void<>>                                          \
    struct has_##name : std::false_type {};								\
    template <typename T>                                                                               \
    struct has_##_name<T, ::trixy::meta::to_void<typename T::name>> : std::true_type {}

#define TRIXY_FUNCTION_TEMPLATE(...)                                                                    \
    TRIXY_TEMPLATE(typename Precision, TRREQUIRE(std::is_arithmetic<Precision>::value))

namespace trixy
{

namespace meta
{

template <bool condition, typename T = void>
using when = typename std::enable_if<condition, T>::type;

template <bool condition>
using require = when<condition, int>;

template <typename... Args>
using to_void = void;

template <typename T>
using remove_ptr = typename std::remove_pointer<T>::type;

template <typename T>
using remove_cv = typename std::remove_cv<T>::type;

template <typename T>
using remove_ref = typename std::remove_reference<T>::type;

template <typename T>
using decay = typename std::decay<T>::type;

template <typename...> struct scope;

template <> struct scope<>
{
public:
    template <int I> struct arg { using type = void; };
};

template <typename T, typename... Tn>
struct scope<T, Tn...>
{
public:
    template <int I, typename overload = void> struct arg
    {
        using type = typename scope<Tn...>::template arg<I - 1>::type;
    };

    template <typename overload> struct arg<0, overload>
    {
        using type = T;
    };

public:
    template <int I> using type = typename arg<I>::type;
};

template <bool condition, typename if_true, typename if_false>
using if_ = typename std::conditional<condition, if_true, if_false>::type;

template <class...> struct and_ : std::true_type {};
template <class B1> struct and_<B1> : B1 {};
template <class B1, class... Bn>
struct and_<B1, Bn...>
    : if_<bool(B1::value), and_<Bn...>, B1> {};

template <class...> struct or_ : std::false_type {};
template <class B1> struct or_<B1> : B1 {};
template <class B1, class... Bn>
struct or_<B1, Bn...>
    : if_<bool(B1::value), B1, or_<Bn...>> {};

template <typename... Bn> constexpr bool all() noexcept
{
    return and_<Bn...>::value;
}

template <typename... Bn> constexpr bool one() noexcept
{
    return or_<Bn...>::value;
}

template <class T, template <class> class... Bn>
struct has_true : or_<Bn<T>...> {};

TRIXY_HAS_FUNCTION_HELPER(type);

template <bool condition, typename T = void>
struct select_for : std::false_type
{
private:
    using std::false_type::type;
};

template <typename T>
struct select_for<true, T> : std::true_type
{
    using type = T;
};

template <class F, typename... Args>
struct is_callable
{
private:
    template <class> static std::false_type check(...);

    template <class U> static auto check(U* p) ->
    decltype((*p)(std::declval<Args>()...), std::true_type{});

public:
    static constexpr bool value = decltype(check<F>(nullptr))::value;
};

template <class T, class... Tn>
struct is_same_all: and_<std::is_same<T, Tn>...> {};

namespace detail
{

template <typename T, typename = void>
struct deref_impl { using type = T; };

template <>
struct deref_impl<void*> { using type = void; };

template <typename T>
struct deref_impl<T, to_void<decltype(*std::declval<T>())>>
{
    using type = remove_ref<decltype(*std::declval<T>())>;
};

} // namespace detail

template <typename It>
using dereference = typename detail::deref_impl<It>::type;

} // namespace meta

} // namespace trixy

namespace trixy
{

namespace detail
{

/// Function return pair of two elements: number_of_threads & block_size of data per thread
template <std::size_t min_per_thread>
std::pair<std::size_t, std::size_t> parallel_info(std::size_t size)
{
    constexpr std::size_t default_number_of_threads = 2;

    // even if size of data is equal to zero, number_of_threads should be 1
    if (size == 0) return { 1, 0 };

    const std::size_t hardware_threads = std::thread::hardware_concurrency();
    const std::size_t max_threads = (size - 1) / min_per_thread + 1;

    const std::size_t number_of_threads =
        std::min(hardware_threads == 0 ? default_number_of_threads : hardware_threads,
                 max_threads);

    const std::size_t block_size = size / number_of_threads;

    return { number_of_threads, block_size };
}

template <typename To, typename Alt = To, typename From,
          meta::require<std::is_convertible<From, To>::value> = 0>
constexpr To try_cast(From&& from)
{
    return static_cast<To>(std::forward<From>(from));
}

template <typename To, typename Alt = To, typename From,
          meta::require<not std::is_convertible<From, To>::value> = 0>
constexpr Alt try_cast(From&& /*unused*/)
{
    return {};
}

template <typename Precision, meta::require<std::is_arithmetic<Precision>::value> = 0>
Precision invert_sqrt(Precision x) noexcept
{
    return 1. / std::sqrt(1e-9 + x);
}

template <typename Pointer>
inline const char* const_byte_cast(Pointer* ptr) noexcept
{
    return reinterpret_cast<const char*>(ptr);
}

template <typename Pointer>
inline char* byte_cast(Pointer* ptr) noexcept
{
    return reinterpret_cast<char*>(ptr);
}

} // namespace detail

} // namespace trixy

namespace trixy
{

namespace lique
{

namespace detail
{

struct cpy
{
    template <typename T>
    void operator() (T& dst, const T& rhs) noexcept { dst = rhs; }
};

template <typename FwdIt, class Function>
void for_each(FwdIt first, FwdIt last, Function function)
{
    while (first != last)
    {
        function(*first);
        ++first;
    }
}

template <class FwdIt, class Function>
void block_for_each(
    FwdIt first, FwdIt last, std::size_t extern_block_width, Function func)
    TRNOEXCEPT_IF(noexcept(func))
{
    auto size = last - first + 1;

    auto width  = size % extern_block_width; // iterable part
    auto offset = extern_block_width - width; // offset to step over non-iterable part

    while (first < last) // 'first' maybe never equal to 'last'
    {
        auto non_iterable_part = first + width;
        while (first != non_iterable_part)
            func(*first++);

        first += offset;
    }
}

template <typename FwdIt, typename InIt>
void copy(FwdIt first, FwdIt last, InIt src)
{
    while (first != last) *first++ = *src++;
}

template <typename FwdIt, typename Generator>
void fill(FwdIt first, FwdIt last, Generator gen)
{
    while(first != last) *first++ = gen();
}

template <typename T, class Operation>
void assign(T* first, T* last, Operation operation, const T& value)
{
    while (first != last)
    {
        operation(*first, value);
        ++first;
    }
}

template <typename T, class Operation>
void assign(T* first, T* last, Operation operation, const T* src)
{
    while (first != last)
    {
        operation(*first, *src);

        ++first;
        ++src;
    }
}

template <typename T, class Operation>
void assign(T* first, T* last, Operation operation, const T& value, const T* rhs) // OVERIEW
{
    while (first != last)
    {
        operation(*first, value, *rhs);

        ++first;
        ++rhs;
    }
}

template <typename T, class Operation>
void assign(T* first, T* last, Operation operation, const T* lhs, const T* rhs) // OVERVIEW
{
    while (first != last)
    {
        operation(*first, *lhs, *rhs);

        ++first;
        ++lhs;
        ++rhs;
    }
}

template <typename FwdIt, class Function>
void apply(FwdIt first, FwdIt last, Function function)
{
    while (first != last)
    {
        *first = function(*first);
        ++first;
    }
}

template <typename FwdIt, class Function, typename InIt>
void apply(FwdIt first, FwdIt last, Function function, InIt src)
{
    while (first != last)
    {
        *first = function(*src);

        ++first;
        ++src;
    }
}

struct add
{
    template <typename T>
    void operator() (T& dst, const T& rhs) noexcept { dst += rhs; }

    template <typename T>
    void operator() (T& dst, const T& lhs, const T& rhs) noexcept { dst = lhs + rhs; }
};

struct sub
{
    template <typename T>
    void operator() (T& dst, const T& rhs) noexcept { dst -= rhs; }

    template <typename T>
    void operator() (T& dst, const T& lhs, const T& rhs) noexcept { dst = lhs - rhs; }
};

struct mul
{
    template <typename T>
    void operator() (T& dst, const T& rhs) noexcept { dst *= rhs; }

    template <typename T>
    void operator() (T& dst, const T& lhs, const T& rhs) noexcept { dst = lhs * rhs; }
};

} // namespace detail

} // namespace lique

} // namespace trixy

// This file contains all extern meta function
// For safer use, you MUST only include the Base*.hpp file from lib

// This file contains all extern meta function
// For safer use, you MUST only include the Base*.hpp file from lib

namespace trixy
{

namespace meta
{

template <typename> struct is_range : std::false_type {};
template <typename T, typename RangeType>
struct is_range<utility::Range<T, RangeType>> : std::true_type {};

} // namespace meta

} // namespace trixy

namespace trixy
{

namespace memory
{

template <class Lockable, typename LockerType>
class Locker;

} // namespace memory

} // namespace trixy

namespace trixy
{

namespace meta
{

template <typename> struct is_locker : std::false_type {};
template <class Lockable, typename LockerType>
struct is_locker<memory::Locker<Lockable, LockerType>> : std::true_type {};

} // namespace meta

} // namespace trixy

namespace trixy
{

namespace lique
{

namespace meta
{

template <typename> struct is_tensor_type : std::false_type {};
template <typename Precision, typename TensrorType, typename TensorMode>
struct is_tensor_type<Tensor<Precision, TensrorType, TensorMode>> : std::true_type {};

template <class Tensor>
struct is_vector : std::is_base_of<lique::TensorType::vector, Tensor> {};

template <class Tensor>
struct is_matrix : std::is_base_of<lique::TensorType::matrix, Tensor> {};

template <class Tensor>
struct is_tensor : std::is_base_of<lique::TensorType::tensor, Tensor> {};

template <class Tensor>
struct is_iterate : trixy::meta::or_
<
    is_tensor<Tensor>,
    is_matrix<Tensor>,
    is_vector<Tensor>,
    trixy::meta::is_range<trixy::meta::decay<Tensor>>
> {};

template <typename T>
using as_vector = trixy::meta::require<is_vector<T>::value>;

template <typename T>
using as_matrix = trixy::meta::require<is_matrix<T>::value>;

template <typename T>
using as_tensor = trixy::meta::require<is_tensor<T>::value>;

template <typename T>
using as_iterate = trixy::meta::require<is_iterate<T>::value>;

} // namespace meta

} // namespace lique

} // namespace trixy

// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define LIQUE_TENSOR_TEMPLATE(...) TRIXY_TEMPLATE(typename Precision)

#define _LIQUE_TENSOR_BASE_TYPES(...)                                                                   \
    private:                                                                                            \
        using Base = TensorBase<Precision>;                                                             \
                                                                                                        \
    public:                                                                                             \
        using typename Base::size_type;                                                                 \
        using typename Base::precision_type;                                                            \
        using typename Base::value_type;                                                                \
        using typename Base::shape_type;                                                                \
                                                                                                        \
        using typename Base::pointer;                                                                   \
        using typename Base::const_pointer;                                                             \
                                                                                                        \
        using typename Base::reference;                                                                 \
        using typename Base::const_reference;

#define _LIQUE_TENSOR_BASE_FUNCIONS(...)                                                                \
    public:                                                                                             \
        using Base::copy;                                                                               \
        using Base::fill;                                                                               \
        using Base::apply;                                                                              \
                                                                                                        \
        using Base::add;                                                                                \
        using Base::sub;                                                                                \
        using Base::mul;                                                                                \
        using Base::join;                                                                               \
                                                                                                        \
        using Base::at;                                                                                 \
        using Base::data;                                                                               \
        using Base::size;                                                                               \
        using Base::shape;                                                                              \
                                                                                                        \
        using Base::operator();

#define LIQUE_TENSOR_BASE_BODY(...)                                                                     \
    _LIQUE_TENSOR_BASE_TYPES(__VA_ARGS__)                                                               \
    _LIQUE_TENSOR_BASE_FUNCIONS(__VA_ARGS__)

namespace trixy
{

namespace lique
{

namespace meta
{

template <typename T>
using is_view_tensor_mode = std::is_same<T, TensorMode::view>;

template <typename T>
using is_own_tensor_mode = std::is_same<T, TensorMode::own>;

template <typename T>
using as_view_tensor_mode = trixy::meta::require<is_view_tensor_mode<T>::value>;

template <typename T>
using as_own_tensor_mode = trixy::meta::require<is_own_tensor_mode<T>::value>;

} // namespace meta

template <typename Precision>
using TensorBase = Tensor<Precision, TensorType::base, TensorMode::view>;

template <typename Precision>
class Tensor<Precision, TensorType::base, TensorMode::view> : public TensorType::base
{
    SERIALIZATION_ACCESS()

    static constexpr bool require = std::is_arithmetic<Precision>::value;

    static_assert(require, "'Precision' should be an arithmetic type.");

public:
    using size_type         = std::size_t;
    using precision_type    = Precision;
    using value_type        = Precision;
    using shape_type        = Shape<std::size_t>;

    using pointer           = Precision*;
    using const_pointer     = const Precision*;

    using reference         = Precision&;
    using const_reference   = const Precision&;

    using range_view        = utility::Range<Precision>;

protected:
    pointer data_;
    shape_type shape_;

public:
    Tensor() noexcept;
    ~Tensor();

    explicit Tensor(const shape_type& shape, pointer data = nullptr) noexcept;

    Tensor(size_type d, size_type h, size_type w, pointer data = nullptr) noexcept;
    Tensor(size_type h, size_type w, pointer data = nullptr) noexcept;
    Tensor(size_type w, pointer data = nullptr) noexcept;

    Tensor(const Tensor& tensor) noexcept;
    Tensor(Tensor&& tensor) noexcept;

    Tensor& operator= (const Tensor& tensor) noexcept;
    Tensor& operator= (Tensor&& tensor) noexcept;

    Tensor& copy(const_pointer src) noexcept;
    Tensor& copy(const Tensor&) noexcept;
    Tensor& copy(std::initializer_list<precision_type>) noexcept;

    template <class Generator,
              trixy::meta::require<trixy::meta::is_callable<Generator>::value> = 0>
    Tensor& fill(Generator generator) noexcept;

    Tensor& fill(precision_type value) noexcept;

    template <class Function>
    Tensor apply(Function func) const;

    template <class Function>
    Tensor& apply(Function func) noexcept;

    template <class Function>
    Tensor& apply(Function func, const_pointer src) noexcept;

    template <class Function>
    Tensor& apply(Function func, const Tensor& rhs) noexcept;

    Tensor add(const Tensor& rhs) const;
    Tensor& add(const Tensor& rhs) noexcept;
    Tensor& add(const Tensor& lhs, const Tensor& rhs) noexcept;

    Tensor sub(const Tensor& rhs) const;
    Tensor& sub(const Tensor& rhs) noexcept;
    Tensor& sub(const Tensor& lhs, const Tensor& rhs) noexcept;

    Tensor mul(const Tensor& rhs) const;
    Tensor& mul(const Tensor& rhs) noexcept;
    Tensor& mul(const Tensor& lhs, const Tensor& rhs) noexcept;

    Tensor join(precision_type value) const;
    Tensor& join(precision_type value) noexcept;
    Tensor& join(precision_type value, const Tensor&) noexcept;

    pointer data() noexcept;
    const_pointer data() const noexcept;

    size_type size() const noexcept;
    const shape_type& shape() const noexcept;

    void swap(Tensor& tensor) noexcept;

    operator range_view() const noexcept;

    pointer at(size_type i) noexcept;
    const_pointer at(size_type i) const noexcept;

    reference operator() (size_type i) noexcept;
    const_reference operator() (size_type i) const noexcept;
};

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>::Tensor() noexcept : data_(nullptr), shape_(0, 0, 0) {}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>::~Tensor() {}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>::Tensor(const shape_type& shape, pointer data) noexcept
: data_(data), shape_(shape) {}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>::Tensor(size_type d, size_type h, size_type w, pointer data) noexcept
: data_(data), shape_(d, h, w) {}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>::Tensor(size_type h, size_type w, pointer data) noexcept
: data_(data), shape_(h, w) {}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>::Tensor(size_type w, pointer data) noexcept
: data_(data), shape_(w) {}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>::Tensor(const Tensor& tensor) noexcept
{
    data_ = tensor.data_;
    shape_ = tensor.shape_;
}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>::Tensor(Tensor&& tensor) noexcept
{
    data_ = tensor.data_;
    shape_ = tensor.shape_;

    tensor.data_ = nullptr;
}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>& TensorBase<Precision>::operator= (const Tensor& tensor) noexcept
{
    if (this != &tensor)
    {
        data_ = tensor.data_;
        shape_ = tensor.shape_;
    }

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>& TensorBase<Precision>::operator= (Tensor&& tensor) noexcept
{
    if (this != &tensor)
    {
        data_ = tensor.data_;
        shape_ = tensor.shape_;

        tensor.data_ = nullptr;
    }

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>& TensorBase<Precision>::copy(const_pointer src) noexcept
{
    lique::detail::copy(data_, data_ + shape_.size, src);

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>& TensorBase<Precision>::copy(const Tensor& vector) noexcept
{
    if (this != &vector)
        lique::detail::copy(data_, data_ + shape_.size, vector.data_);

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>& TensorBase<Precision>::copy(
    std::initializer_list<precision_type> init) noexcept
{
    lique::detail::copy(data_, data_ + shape_.size, init.begin());

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
template <class Generator, trixy::meta::require<trixy::meta::is_callable<Generator>::value>>
TensorBase<Precision>& TensorBase<Precision>::fill(Generator generator) noexcept
{
    lique::detail::fill(data_, data_ + shape_.size, generator);

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>& TensorBase<Precision>::fill(precision_type value) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::cpy(), value);

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
template <class Function>
TensorBase<Precision> TensorBase<Precision>::apply(Function func) const
{
    Tensor vector(shape_.size);

    vector.apply(func, data_);

    return vector;
}

LIQUE_TENSOR_TEMPLATE()
template <class Function>
TensorBase<Precision>& TensorBase<Precision>::apply(Function func) noexcept
{
    lique::detail::apply(data_, data_ + shape_.size, func);

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
template <class Function>
TensorBase<Precision>& TensorBase<Precision>::apply(Function func, const_pointer src) noexcept
{
    lique::detail::apply(data_, data_ + shape_.size, func, src);

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
template <class Function>
TensorBase<Precision>& TensorBase<Precision>::apply(Function func, const Tensor& vector) noexcept
{
    return apply(func, vector.data_);
}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision> TensorBase<Precision>::add(const Tensor& rhs) const
{
    Tensor vector(shape_.size);

    vector.add(*this, rhs);

    return vector;
}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>& TensorBase<Precision>::add(const Tensor& rhs) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::add(), rhs.data_);

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>& TensorBase<Precision>::add(const Tensor& lhs, const Tensor& rhs) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::add(), lhs.data_, rhs.data_);

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision> TensorBase<Precision>::sub(const Tensor& rhs) const
{
    Tensor vector(shape_.size);

    vector.sub(*this, rhs);

    return vector;
}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>& TensorBase<Precision>::sub(const Tensor& rhs) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::sub(), rhs.data_);

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>& TensorBase<Precision>::sub(const Tensor& lhs, const Tensor& rhs) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::sub(), lhs.data_, rhs.data_);

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision> TensorBase<Precision>::mul(const Tensor& rhs) const
{
    Tensor vector(shape_.size);

    vector.mul(*this, rhs);

    return vector;
}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>& TensorBase<Precision>::mul(const Tensor& rhs) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::mul(), rhs.data_);

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>& TensorBase<Precision>::mul(const Tensor& lhs, const Tensor& rhs) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::mul(), lhs.data_, rhs.data_);

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision> TensorBase<Precision>::join(precision_type value) const
{
    Tensor tensor(shape_.size);

    tensor.join(value, *this);

    return tensor;
}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>& TensorBase<Precision>::join(precision_type value) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::mul(), value);

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
TensorBase<Precision>& TensorBase<Precision>::join(precision_type value, const Tensor& rhs) noexcept
{
    lique::detail::assign(data_, data_ + shape_.size, lique::detail::mul(), value, rhs.data_);

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
inline auto TensorBase<Precision>::data() noexcept -> pointer
{
    return data_;
}

LIQUE_TENSOR_TEMPLATE()
inline auto TensorBase<Precision>::data() const noexcept -> const_pointer
{
    return data_;
}

LIQUE_TENSOR_TEMPLATE()
inline auto TensorBase<Precision>::size() const noexcept -> size_type
{
    return shape_.size;
}

LIQUE_TENSOR_TEMPLATE()
inline auto TensorBase<Precision>::shape() const noexcept -> const shape_type&
{
    return shape_;
}

LIQUE_TENSOR_TEMPLATE()
void TensorBase<Precision>::swap(Tensor& tensor) noexcept
{
    std::swap(data_, tensor.data_);
    std::swap(shape_, tensor.shape_);
}

LIQUE_TENSOR_TEMPLATE()
inline TensorBase<Precision>::operator range_view() const noexcept
{
    return range_view(data_, data_ + shape_.size);
}

LIQUE_TENSOR_TEMPLATE()
inline auto TensorBase<Precision>::at(size_type i) noexcept -> pointer
{
    return data_ + i;
}

LIQUE_TENSOR_TEMPLATE()
inline auto TensorBase<Precision>::at(size_type i) const noexcept -> const_pointer
{
    return data_ + i;
}

LIQUE_TENSOR_TEMPLATE()
inline auto TensorBase<Precision>::operator() (size_type i) noexcept -> reference
{
    return *at(i); // dereferencing
}

LIQUE_TENSOR_TEMPLATE()
inline auto TensorBase<Precision>::operator() (size_type i) const noexcept -> const_reference
{
    return *at(i); // dereferencing
}

} // namespace lique

} // namespace trixy

CONDITIONAL_SERIALIZATION(SaveLoad, trixy::lique::meta::is_tensor_type<T>::value)
{
    archive & self.shape_;
    archive & sf::span(self.data_, self.shape_.size);
}

namespace trixy
{

namespace lique
{

template <typename Precision, typename TensorMode = TensorMode::own>
using Vector = Tensor<Precision, TensorType::vector, TensorMode>;

template <typename Precision>
using VectorView = Vector<Precision, TensorMode::view>;

template <typename Precision>
class Tensor<Precision, TensorType::vector, TensorMode::own>
    : public TensorBase<Precision>
    , public TensorType::vector
{
    LIQUE_TENSOR_BASE_BODY()

public:
    Tensor() noexcept = default;
    ~Tensor();

    explicit Tensor(const shape_type& shape, const_pointer data);
    explicit Tensor(const shape_type& shape, precision_type value);
    explicit Tensor(const shape_type& shape);

    Tensor(std::initializer_list<precision_type> init);

    Tensor(size_type width, const_pointer data);
    Tensor(size_type width, precision_type value);
    Tensor(size_type width);

    Tensor(const_pointer first, const_pointer last);

    Tensor(const Tensor& tensor);
    Tensor(Tensor&& tensor) noexcept;

    Tensor& operator= (const Tensor& tensor);
    Tensor& operator= (Tensor&& tensor) noexcept;

    Tensor& resize(const shape_type& shape);
    Tensor& resize(size_type width);

    Tensor& reshape(size_type width) noexcept;
};

template <typename Precision>
class Tensor<Precision, TensorType::vector, TensorMode::view>
    : public TensorBase<Precision>
    , public TensorType::vector
{
    LIQUE_TENSOR_BASE_BODY()

public:
    Tensor() noexcept = default;
    ~Tensor() = default;

    Tensor(const shape_type& shape, pointer data) noexcept;
    Tensor(size_type width, pointer data) noexcept;
    Tensor(pointer first, pointer last) noexcept;

    Tensor(const Tensor& tensor) noexcept = default;
    Tensor(Tensor&& tensor) noexcept = default;

    Tensor& operator= (const Tensor& tensor) noexcept;
    Tensor& operator= (Tensor&& tensor) noexcept;

    Tensor& reshape(size_type width) noexcept;
};

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::~Tensor()
{
    delete[] this->data_;
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::Tensor(const shape_type& shape, const_pointer data)
    : Base(shape.width)
{
    this->data = new precision_type [shape.size];

    this->copy(data);
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::Tensor(const shape_type& shape, precision_type value)
    : Base(shape.width)
{
    this->data = new precision_type [shape.size];

    this->fill(value);
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::Tensor(const shape_type& shape)
    : Base(shape.width)
{
    this->data = new precision_type [shape.size];
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::Tensor(std::initializer_list<precision_type> init)
    : Base(init.size())
{
    this->data_ = new precision_type [this->shape_.size];

    this->copy(init.begin());
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::Tensor(size_type width, const_pointer data)
    : Base(width)
{
    this->data_ = new precision_type [this->shape_.size];

    this->copy(data);
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::Tensor(size_type width, precision_type value)
    : Base(width)
{
    this->data_ = new precision_type [this->shape_.size];

    this->fill(value);
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::Tensor(size_type width)
    : Base(width)
{
    this->data_ = new precision_type [this->shape_.size];
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::Tensor(const_pointer first, const_pointer last)
    : Base(last - first)
{
    this->data_ = new precision_type [this->shape_.size];

    this->copy(first);
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::Tensor(const Tensor& tensor) : Base(tensor.shape_.width)
{
    this->data_ = new precision_type [tensor.shape_.size];

    this->copy(tensor.data_);
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>::Tensor(Tensor&& tensor) noexcept
    : Base(std::move(tensor))
{
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>& Vector<Precision>::operator= (const Tensor& tensor)
{
    if (this != &tensor)
    {
        delete[] this->data_;

        this->data_ = new precision_type [tensor.shape_.size];

        this->shape_.width = tensor.shape_.width;
        this->shape_.size = tensor.shape_.size;

        this->copy(tensor.data_);
    }

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
Vector<Precision>& Vector<Precision>::operator= (Tensor&& tensor) noexcept
{
    if (this != &tensor)
    {
        delete[] this->data_;

        this->data_ = tensor.data_;

        this->shape_.width = tensor.shape_.width;
        this->shape_.size = tensor.shape_.size;

        tensor.data_ = nullptr;
    }

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
auto Vector<Precision>::resize(const shape_type& shape) -> Tensor&
{
    resize(shape.width);
    return *this;
}

LIQUE_TENSOR_TEMPLATE()
auto Vector<Precision>::resize(size_type width) -> Tensor&
{
    delete[] this->data_;

    this->shape_ = shape_type(1, width, 1);

    this->data_ = new precision_type [width];

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
auto Vector<Precision>::reshape(size_type width) noexcept -> Tensor&
{
    this->shape_.width = width;
    return *this;
}

LIQUE_TENSOR_TEMPLATE()
VectorView<Precision>::Tensor(const shape_type& shape, pointer data) noexcept
    : Base(shape.width, data)
{
}

LIQUE_TENSOR_TEMPLATE()
VectorView<Precision>::Tensor(size_type width, pointer data) noexcept
    : Base(width, data)
{
}

LIQUE_TENSOR_TEMPLATE()
VectorView<Precision>::Tensor(pointer first, pointer last) noexcept
    : Base(last - first, first)
{
}

LIQUE_TENSOR_TEMPLATE()
VectorView<Precision>& VectorView<Precision>::operator= (const Tensor& tensor) noexcept
{
    if (this != &tensor)
    {
        this->data_ = tensor.data_;

        this->shape_.width = tensor.shape_.width;
        this->shape_.size = tensor.shape_.size;
    }

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
VectorView<Precision>& VectorView<Precision>::operator= (Tensor&& tensor) noexcept
{
    if (this != &tensor)
    {
        this->data_ = tensor.data_;

        this->shape_.width = tensor.shape_.width;
        this->shape_.size = tensor.shape_.size;

        tensor.data_ = nullptr;
    }

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
auto VectorView<Precision>::reshape(size_type width) noexcept -> Tensor&
{
    this->shape_.width = width;
    return *this;
}

} // namespace lique

} // namespace trixy

namespace trixy
{

namespace lique
{

template <typename Precision, typename TensorMode = TensorMode::own>
using Matrix = Tensor<Precision, TensorType::matrix, TensorMode>;

LIQUE_TENSOR_TEMPLATE()
using MatrixView = Matrix<Precision, TensorMode::view>;

LIQUE_TENSOR_TEMPLATE()
class Tensor<Precision, TensorType::matrix, TensorMode::own>
    : public TensorBase<Precision>
    , public TensorType::matrix
{
    LIQUE_TENSOR_BASE_BODY()

public:
    Tensor() noexcept = default;
    ~Tensor();

    explicit Tensor(const shape_type& shape, const_pointer data);
    explicit Tensor(const shape_type& shape, precision_type value);
    explicit Tensor(const shape_type& shape);

    Tensor(size_type height, size_type width, const_pointer data);
    Tensor(size_type height, size_type width, precision_type value);
    Tensor(size_type height, size_type width);

    Tensor(const_pointer first, const_pointer last);

    Tensor(const Tensor& tensor);
    Tensor(Tensor&& tensor) noexcept;

    Tensor& operator= (const Tensor& tensor);
    Tensor& operator= (Tensor&& tensor) noexcept;

    pointer at(size_type i, size_type j) noexcept;
    const_pointer at(size_type i , size_type j) const noexcept;

    reference operator() (size_type i, size_type j) noexcept;
    const_reference operator() (size_type i, size_type j) const noexcept;

    Tensor& resize(const shape_type& shape);
    Tensor& resize(size_type height, size_type width);

    Tensor& reshape(size_type height, size_type width) noexcept;
};

LIQUE_TENSOR_TEMPLATE()
class Tensor<Precision, TensorType::matrix, TensorMode::view>
    : public TensorBase<Precision>
    , public TensorType::matrix
{
    LIQUE_TENSOR_BASE_BODY()

public:
    Tensor() noexcept = default;
    ~Tensor() = default;

    Tensor(const shape_type& shape, pointer data) noexcept;
    Tensor(size_type height, size_type width, pointer data) noexcept;
    Tensor(pointer first, pointer last) noexcept;

    Tensor(const Tensor& tensor) noexcept = default;
    Tensor(Tensor&& tensor) noexcept = default;

    Tensor& operator= (const Tensor& tensor) noexcept;
    Tensor& operator= (Tensor&& tensor) noexcept;

    pointer at(size_type i, size_type j) noexcept;
    const_pointer at(size_type i , size_type j) const noexcept;

    reference operator() (size_type i, size_type j) noexcept;
    const_reference operator() (size_type i, size_type j) const noexcept;

    Tensor& reshape(size_type height, size_type width) noexcept;
};

LIQUE_TENSOR_TEMPLATE()
Matrix<Precision>::~Tensor()
{
    delete[] this->data_;
}

LIQUE_TENSOR_TEMPLATE()
Matrix<Precision>::Tensor(const shape_type& shape, const_pointer data)
    : Base(shape.depth * shape.height, shape.width)
{
    this->data_ = new precision_type [this->shape_.size];

    this->copy(data);
}

LIQUE_TENSOR_TEMPLATE()
Matrix<Precision>::Tensor(const shape_type& shape, precision_type value)
    : Base(shape.depth * shape.height, shape.width)
{
    this->data_ = new precision_type [this->shape_.size];

    this->fill(value);
}

LIQUE_TENSOR_TEMPLATE()
Matrix<Precision>::Tensor(const shape_type& shape)
    : Base(shape.depth * shape.height, shape.width)
{
    this->data_ = new precision_type [this->shape_.size];
}

LIQUE_TENSOR_TEMPLATE()
Matrix<Precision>::Tensor(size_type height, size_type width, const_pointer data)
    : Base(height, width)
{
    this->data_ = new precision_type [this->shape_.size];

    this->copy(data);
}

LIQUE_TENSOR_TEMPLATE()
Matrix<Precision>::Tensor(size_type height, size_type width, precision_type value)
    : Base(height, width)
{
    this->data_ = new precision_type [this->shape_.size];

    this->fill(value);
}

LIQUE_TENSOR_TEMPLATE()
Matrix<Precision>::Tensor(size_type height, size_type width)
    : Base(height, width)
{
    this->data_ = new precision_type [this->shape_.size];
}

LIQUE_TENSOR_TEMPLATE()
Matrix<Precision>::Tensor(const_pointer first, const_pointer last)
    : Base(1, last - first)
{
    this->data_ = new precision_type [this->shape_.size];

    this->copy(first);
}

LIQUE_TENSOR_TEMPLATE()
Matrix<Precision>::Tensor(const Tensor& tensor)
    : Base(tensor.shape_.depth * tensor.shape_.height, tensor.shape_.width)
{
    this->data_ = new precision_type [tensor.shape_.size];

    this->copy(tensor.data_);
}

LIQUE_TENSOR_TEMPLATE()
Matrix<Precision>::Tensor(Tensor&& tensor) noexcept
    : Base(std::move(tensor))
{
}

LIQUE_TENSOR_TEMPLATE()
Matrix<Precision>& Matrix<Precision>::operator= (const Tensor& tensor)
{
    if (this != &tensor)
    {
        delete[] this->data_;

        this->data_ = new precision_type [tensor.shape_.size];

        this->copy(tensor.data_);

        this->shape_.height = tensor.shape_.height;
        this->shape_.width = tensor.shape_.width;

        this->shape_.size = tensor.shape_.size;
    }

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
Matrix<Precision>& Matrix<Precision>::operator= (Tensor&& tensor) noexcept
{
    if (this != &tensor)
    {
        delete[] this->data_;

        this->data_ = tensor.data_;

        this->shape_.height = tensor.shape_.height;
        this->shape_.width = tensor.shape_.width;

        this->shape_.size = tensor.shape_.size;

        tensor.data_ = nullptr;
    }

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
inline auto Matrix<Precision>::at(size_type i, size_type j) noexcept -> pointer
{
    return this->data_ + i * this->shape_.width + j;
}

LIQUE_TENSOR_TEMPLATE()
inline auto Matrix<Precision>::at(size_type i, size_type j) const noexcept -> const_pointer
{
    return this->data_ + i * this->shape_.width + j;
}

LIQUE_TENSOR_TEMPLATE()
inline auto Matrix<Precision>::operator() (size_type i, size_type j) noexcept -> reference
{
    return *at(i, j); // dereferencing
}

LIQUE_TENSOR_TEMPLATE()
inline auto Matrix<Precision>::operator() (size_type i, size_type j) const noexcept -> const_reference
{
    return *at(i, j); // dereferencing
}

LIQUE_TENSOR_TEMPLATE()
auto Matrix<Precision>::resize(const shape_type& shape) -> Tensor&
{
    resize(shape.height, shape.width);
    return *this;
}

LIQUE_TENSOR_TEMPLATE()
auto Matrix<Precision>::resize(size_type height, size_type width) -> Tensor&
{
    delete[] this->data_;

    this->shape_.height = height;
    this->shape_.width = width;

    this->shape_.size = height * width;

    this->data_ = new precision_type [this->shape_.size];

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
auto Matrix<Precision>::reshape(size_type height, size_type width) noexcept -> Tensor&
{
    this->shape_.height = height;
    this->shape_.width = width;

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
MatrixView<Precision>::Tensor(const shape_type& shape, pointer data) noexcept
    : Base(shape.depth * shape.height, shape.width, data)
{
}

LIQUE_TENSOR_TEMPLATE()
MatrixView<Precision>::Tensor(size_type height, size_type width, pointer data) noexcept
    : Base(height, width, data)
{
}

LIQUE_TENSOR_TEMPLATE()
MatrixView<Precision>::Tensor(pointer first, pointer last) noexcept
    : Base(1, last - first, first)
{
}

LIQUE_TENSOR_TEMPLATE()
MatrixView<Precision>& MatrixView<Precision>::operator= (const Tensor& tensor) noexcept
{
    if (this != &tensor)
    {
        this->data_ = tensor.data_;

        this->shape_.height = tensor.shape_.height;
        this->shape_.width = tensor.shape_.width;

        this->shape_.size = tensor.shape_.size;
    }

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
MatrixView<Precision>& MatrixView<Precision>::operator= (Tensor&& tensor) noexcept
{
    if (this != &tensor)
    {
        this->data_ = tensor.data_;

        this->shape_.height = tensor.shape_.height;
        this->shape_.width = tensor.shape_.width;

        this->shape_.size = tensor.shape_.size;

        tensor.data_ = nullptr;
    }

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
inline auto MatrixView<Precision>::at(size_type i, size_type j) noexcept -> pointer
{
    return this->data_ + i * this->shape_.width + j;
}

LIQUE_TENSOR_TEMPLATE()
inline auto MatrixView<Precision>::at(size_type i, size_type j) const noexcept -> const_pointer
{
    return this->data_ + i * this->shape_.width + j;
}

LIQUE_TENSOR_TEMPLATE()
inline auto MatrixView<Precision>::operator() (size_type i, size_type j) noexcept -> reference
{
    return *at(i, j); // dereferencing
}

LIQUE_TENSOR_TEMPLATE()
inline auto MatrixView<Precision>::operator() (size_type i, size_type j) const noexcept -> const_reference
{
    return *at(i, j); // dereferencing
}

LIQUE_TENSOR_TEMPLATE()
auto MatrixView<Precision>::reshape(size_type height, size_type width) noexcept -> Tensor&
{
    this->shape_.height = height;
    this->shape_.width = width;

    return *this;
}

} // namespace lique

} // namespace trixy

namespace trixy
{

namespace lique
{

template <typename Precision>
using TensorView = Tensor<Precision, TensorType::tensor, TensorMode::view>;

template <typename Precision>
class Tensor<Precision, TensorType::tensor, TensorMode::own>
    : public TensorBase<Precision>
    , public TensorType::tensor
{
    LIQUE_TENSOR_BASE_BODY()

public:
    Tensor() noexcept = default;
    ~Tensor();

    explicit Tensor(const shape_type& shape, const_pointer data);
    explicit Tensor(const shape_type& shape, precision_type value);
    explicit Tensor(const shape_type& shape);

    Tensor(size_type depth, size_type height, size_type width, const_pointer data);
    Tensor(size_type depth, size_type height, size_type width, precision_type value);
    Tensor(size_type depth, size_type height, size_type width);

    Tensor(const_pointer first, const_pointer last);

    Tensor(std::initializer_list<precision_type> list);

    Tensor(const Tensor& tensor);
    Tensor(Tensor&& tensor) noexcept;

    Tensor& operator= (const Tensor& tensor);
    Tensor& operator= (Tensor&& tensor) noexcept;

    pointer at(size_type i, size_type j, size_type k) noexcept;
    const_pointer at(size_type i , size_type j, size_type k) const noexcept;

    reference operator() (size_type i, size_type j, size_type k) noexcept;
    const_reference operator() (size_type i, size_type j, size_type k) const noexcept;

    Tensor& resize(const shape_type& shape);
    Tensor& resize(size_type depth, size_type height, size_type width);

    Tensor& reshape(size_type depth, size_type height, size_type width) noexcept;
};

template <typename Precision>
class Tensor<Precision, TensorType::tensor, TensorMode::view>
    : public TensorBase<Precision>
    , public TensorType::tensor
{
    LIQUE_TENSOR_BASE_BODY()

public:
    Tensor() noexcept = default;
    ~Tensor() = default;

    Tensor(const shape_type& shape, pointer data) noexcept;
    Tensor(size_type depth, size_type height, size_type width, pointer data) noexcept;
    Tensor(pointer first, pointer last) noexcept;

    Tensor(const Tensor& tensor) noexcept = default;
    Tensor(Tensor&& tensor) noexcept = default;

    Tensor& operator= (const Tensor& tensor) noexcept = default;
    Tensor& operator= (Tensor&& tensor) noexcept = default;

    pointer at(size_type i, size_type j, size_type k) noexcept;
    const_pointer at(size_type i , size_type j, size_type k) const noexcept;

    reference operator() (size_type i, size_type j, size_type k) noexcept;
    const_reference operator() (size_type i, size_type j, size_type k) const noexcept;

    Tensor& reshape(size_type depth, size_type height, size_type width) noexcept;
};

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::~Tensor()
{
    delete[] this->data_;
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::Tensor(const shape_type& shape, const_pointer data)
    : Base(shape)
{
    this->data_ = new precision_type [this->shape_.size];

    this->copy(data);
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::Tensor(const shape_type& shape, precision_type value)
    : Base(shape)
{
    this->data_ = new precision_type [this->shape_.size];

    this->fill(value);
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::Tensor(const shape_type& shape)
    : Base(shape)
{
    this->data_ = new precision_type [this->shape_.size];
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::Tensor(size_type depth, size_type height, size_type width, const_pointer data)
    : Base(depth, height, width)
{
    this->data_ = new precision_type [this->shape_.size];

    this->copy(data);
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::Tensor(size_type depth, size_type height, size_type width, precision_type value)
    : Base(depth, height, width)
{
    this->data_ = new precision_type [this->shape_.size];

    this->fill(value);
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::Tensor(size_type depth, size_type height, size_type width)
    : Base(depth, height, width)
{
    this->data_ = new precision_type [this->shape_.size];
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::Tensor(const_pointer first, const_pointer last)
    : Base(1, 1, last - first)
{
    this->data_ = new precision_type [this->shape_.size];

    this->copy(first);
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::Tensor(std::initializer_list<precision_type> list)
    : Base(1, 1, list.size())
{
    this->data_ = new precision_type [this->shape_.size];

    this->copy(list.begin());
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::Tensor(const Tensor& tensor)
    : Base(tensor.shape_)
{
    this->data_ = new precision_type [tensor.shape_.size];
    this->shape_ = tensor.shape_;

    this->copy(tensor.data_);
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>::Tensor(Tensor&& tensor) noexcept
    : Base(std::move(tensor))
{
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>& Tensor<Precision>::operator= (const Tensor& tensor)
{
    if (this != &tensor)
    {
        delete[] this->data_;

        this->data_ = new precision_type [tensor.shape_.size];

        this->copy(tensor.data_);

        this->shape_ = tensor.shape_;
    }

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
Tensor<Precision>& Tensor<Precision>::operator= (Tensor&& tensor) noexcept
{
    if (this != &tensor)
    {
        delete[] this->data_;

        this->data_ = tensor.data_;
        this->shape_ = tensor.shape_;

        tensor.data_ = nullptr;
    }

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
inline auto Tensor<Precision>::at(
    size_type i, size_type j, size_type k) noexcept -> pointer
{
    return this->data_ + (i * this->shape_.height + j) * this->shape_.width + k;
}

LIQUE_TENSOR_TEMPLATE()
inline auto Tensor<Precision>::at(
    size_type i, size_type j, size_type k) const noexcept -> const_pointer
{
    return this->data_ + (i * this->shape_.height + j) * this->shape_.width + k;
}

LIQUE_TENSOR_TEMPLATE()
inline auto Tensor<Precision>::operator() (
    size_type i, size_type j, size_type k) noexcept -> reference
{
    return *at(i, j, k); // dereferencing
}

LIQUE_TENSOR_TEMPLATE()
inline auto Tensor<Precision>::operator() (
    size_type i, size_type j, size_type k) const noexcept -> const_reference
{
    return *at(i, j, k); // dereferencing
}

LIQUE_TENSOR_TEMPLATE()
auto Tensor<Precision>::resize(const shape_type& shape) -> Tensor&
{
    resize(shape.depth, shape.height, shape.width);
    return *this;
}

LIQUE_TENSOR_TEMPLATE()
auto Tensor<Precision>::resize(size_type depth, size_type height, size_type width) -> Tensor&
{
    delete[] this->data_;

    this->shape_ = shape_type(depth, height, width);

    this->data_ = new precision_type [this->shape_.size];

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
auto Tensor<Precision>::reshape(size_type depth, size_type height, size_type width) noexcept -> Tensor&
{
    this->shape_.depth = depth;
    this->shape_.height = height;
    this->shape_.width = width;

    return *this;
}

LIQUE_TENSOR_TEMPLATE()
TensorView<Precision>::Tensor(const shape_type& shape, pointer data) noexcept
    : Base(shape, data)
{
}

LIQUE_TENSOR_TEMPLATE()
TensorView<Precision>::Tensor(
    size_type depth, size_type height, size_type width, pointer data) noexcept
    : Base(depth, height, width, data)
{
}

LIQUE_TENSOR_TEMPLATE()
TensorView<Precision>::Tensor(pointer first, pointer last) noexcept
    : Base(1, 1, last - first, first)
{
}

LIQUE_TENSOR_TEMPLATE()
inline auto TensorView<Precision>::at(
    size_type i, size_type j, size_type k) noexcept -> pointer
{
    return this->data_ + (i * this->shape_.height + j) * this->shape_.width + k;
}

LIQUE_TENSOR_TEMPLATE()
inline auto TensorView<Precision>::at(
    size_type i, size_type j, size_type k) const noexcept -> const_pointer
{
    return this->data_ + (i * this->shape_.height + j) * this->shape_.width + k;
}

LIQUE_TENSOR_TEMPLATE()
inline auto TensorView<Precision>::operator() (
    size_type i, size_type j, size_type k) noexcept -> reference
{
    return *at(i, j, k); // dereferencing
}

LIQUE_TENSOR_TEMPLATE()
inline auto TensorView<Precision>::operator() (
    size_type i, size_type j, size_type k) const noexcept -> const_reference
{
    return *at(i, j, k); // dereferencing
}

LIQUE_TENSOR_TEMPLATE()
auto TensorView<Precision>::reshape(size_type depth, size_type height, size_type width) noexcept -> Tensor&
{
    this->shape_.depth = depth;
    this->shape_.height = height;
    this->shape_.width = width;

    return *this;
}

} // namespace lique

} // namespace trixy

namespace trixy
{

namespace guard
{

template <class Requirable, typename RequireType>
struct Require;

} // namespace guard

} // namespace trixy

namespace trixy
{

namespace guard
{

template <class Linear>
using LinearRequire = Require<Linear, RequireType::linear>;

template <class Linear>
struct Require<Linear, RequireType::linear> : protected Linear
{
public:
    using type = RequireType::linear;

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
    using require::transpose;
    using require::inverse;

    using require::add;
    using require::sub;
    using require::mul;
    using require::join;

    using require::apply;

    using require::loop;
};

} // namespace guard

} // namespace trixy

namespace trixy
{

namespace lique
{

template <typename Precision>
class Linear
{
private:
    template <class T>
    using as_flat_iterate =
        trixy::meta::require<not meta::is_matrix<T>::value and
                             meta::is_iterate<T>::value>;

public:
    using size_type      = std::size_t;
    using precision_type = Precision;

public:
    template <class Iterable, lique::meta::as_iterate<Iterable> = 0>
    auto first(Iterable& it) const noexcept -> decltype(it.data())
    {
        return it.data();
    }

    template <class Iterable, lique::meta::as_iterate<Iterable> = 0>
    auto last(Iterable& it) const noexcept -> decltype(it.data() + it.size())
    {
        return it.data() + it.size();
    }

    template <class Vector1, class Vector2, class Matrix,
              as_flat_iterate<Vector1> = 0,
              as_flat_iterate<Vector2> = 0,
              meta::as_matrix<Matrix> = 0>
    void dot(
        Vector1& result,
        const Vector2& row_vector,
        const Matrix& matrix) const noexcept
    {
        precision_type temp;

        detail::assign(first(result), last(result), detail::cpy(), precision_type(0.));

        for (size_type i = 0; i < row_vector.size(); ++i)
        {
            temp = row_vector(i);
            for (size_type j = 0; j < result.size(); ++j)
                result(j) += temp * matrix(i, j);
        }
    }

    template <class Vector1, class Vector2, class Matrix,
              as_flat_iterate<Vector1> = 0,
              as_flat_iterate<Vector2> = 0,
              meta::as_matrix<Matrix> = 0>
    void dot(
        Vector1& result,
        const Matrix& matrix,
        const Vector2& col_vector) const noexcept
    {
        detail::assign(first(result), last(result), detail::cpy(), precision_type(0.));

        for (size_type i = 0; i < result.size(); ++i)
            for (size_type j = 0; j < col_vector.size(); ++j)
                result(i) += matrix(i, j) * col_vector(j);
    }

    template <class Matrix1, class Matrix2, class Matrix3,
              meta::as_matrix<Matrix1> = 0,
              meta::as_matrix<Matrix2> = 0,
              meta::as_matrix<Matrix3> = 0>
    void dot(
        Matrix1& result,
        const Matrix2& lhs,
        const Matrix3& rhs) const noexcept
    {
        precision_type buff;
        for (size_type i = 0; i < lhs.shape().height; ++i)
        {
            for (size_type r = 0; r < lhs.shape().width; ++r)
            {
                buff = lhs(i, r);

                for (size_type j = 0; j < rhs.shape().width; ++j)
                    result(i, j) += buff * rhs(r, j);
            }
        }
    }

    template <class Vector1, class Vector2, class Matrix,
              as_flat_iterate<Vector1> = 0,
              as_flat_iterate<Vector2> = 0,
              meta::as_matrix<Matrix> = 0>
    void tensordot(
        Matrix& result,
        const Vector1& col_vector,
        const Vector2& row_vector) const noexcept
    {
        /*
        precision_type temp;

        for(size_type i = 0; i < col_vector.size(); ++i)
        {
            temp = col_vector(i);
            for(size_type j = 0; j < row_vector.size(); ++j)
                result(i, j) = temp * row_vector(j);
        }
        */
        const size_type block_size = row_vector.size();

        auto dst = first(result);

        auto c_first = first(col_vector);
        auto c_last = last(col_vector);

        auto r_first = first(row_vector);

        while (c_first != c_last)
        {
            detail::assign(dst, dst + block_size, detail::mul(), *c_first, r_first);

            dst += block_size;
            ++c_first;
        }
    }

    template <class Matrix1, class Matrix2,
              meta::as_matrix<Matrix1> = 0,
              meta::as_matrix<Matrix2> = 0>
    void transpose(
        Matrix1& result,
        const Matrix2& matrix) const noexcept
    {
        for (size_type i = 0; i < result.shape().height; ++i)
            for (size_type j = 0; j < result.shape().width; ++j)
                result(i, j) = matrix(j, i);
    }

    template <class Matrix1, class Matrix2,
              meta::as_matrix<Matrix1> = 0,
              meta::as_matrix<Matrix2> = 0>
    void inverse(
        Matrix1& result,
        Matrix2& matrix) const noexcept
    {
        size_type N = matrix.shape().height;

        size_type i;
        size_type j;

        precision_type buff;

        for (i = 0; i < N; ++i)
            for (j = 0; j < N; ++j)
                result(i, j) = (i == j) ? 1. : 0.;

        for (size_type k = 0, p; k < N; ++k)
        {
            p = k;
            for (i = k + 1; i < N; ++i)
                if (std::fabs(matrix(p, k)) < std::fabs(matrix(i, k)))
                    p = i;

            if (p != k)
            {
                for (j = k; j < N; ++j)
                {
                    buff = matrix(k, j);
                    matrix(k, j) = matrix(p, j);
                    matrix(p, j) = buff;
                }

                for (j = 0; j < N; ++j)
                {
                    buff = result(k, j);
                    result(k, j) = result(p, j);
                    result(p, j) = buff;
                }
            }

            buff = 1. / matrix(k, k);

            for (j = k; j < N; ++j) matrix(k, j) *= buff;
            for (j = 0; j < N; ++j) result(k, j) *= buff;

            for (i = 0; i < N; ++i)
            {
                if (i == k) continue;

                buff = matrix(i, k);

                for (j = k; j < N; ++j) matrix(i, j) -= matrix(k, j) * buff;
                for (j = 0; j < N; ++j) result(i, j) -= result(k, j) * buff;
            }
        }
    }

    template <class Vector1, class Vector2,
              as_flat_iterate<Vector1> = 0,
              as_flat_iterate<Vector2> = 0>
    precision_type dot(
        const Vector1& lhs,
        const Vector2& rhs) const noexcept
    {
        precision_type result = 0.0;

        auto first = lhs.data();
        auto last  = lhs.data() + lhs.size();

        auto data = rhs.data();

        while (first != last)
        {
            result += (*first) * (*data);

            ++first;
            ++data;
        }

        return result;
    }

    template <class Vector, class Matrix, class VectorRet = Vector,
              as_flat_iterate<Vector> = 0,
              meta::as_matrix<Matrix> = 0,
              as_flat_iterate<VectorRet> = 0>
    VectorRet dot(
        const Vector& row_vector,
        const Matrix& matrix) const
    {
        Vector result(matrix.shape().width);

        dot(result, row_vector, matrix);

        return result;
    }

    template <class Vector, class Matrix, class VectorRet = Vector,
              as_flat_iterate<Vector> = 0,
              meta::as_matrix<Matrix> = 0,
              as_flat_iterate<VectorRet> = 0>
    VectorRet dot(
        const Matrix& matrix,
        const Vector& col_vector) const
    {
        Vector result(matrix.shape().height);

        dot(result, matrix, col_vector);

        return result;
    }

    template <class Matrix1, class Matrix2, class MatrixRet = Matrix1,
              meta::as_matrix<Matrix1> = 0,
              meta::as_matrix<Matrix2> = 0,
              meta::as_matrix<MatrixRet> = 0>
    MatrixRet dot(
        const Matrix1& lhs,
        const Matrix2& rhs) const
    {
        MatrixRet matrix(lhs.shape().height, rhs.shape().width, 0.);

        dot(matrix, lhs, rhs);

        return matrix;
    }

    template <class MatrixRet, class Vector,
              meta::as_matrix<MatrixRet> = 0,
              as_flat_iterate<Vector> = 0>
    MatrixRet tensordot(
        const Vector& col_vector,
        const Vector& row_vector) const
    {
        MatrixRet result(col_vector.size(), row_vector.size());

        tensordot(result, col_vector, row_vector);

        return result;
    }

    template <class Matrix, class MatrixRet = Matrix,
              meta::as_matrix<Matrix> = 0,
              meta::as_matrix<MatrixRet> = 0>
    MatrixRet transpose(const Matrix& matrix) const
    {
        MatrixRet result(matrix.shape().width, matrix.shape().height);

        transpose(result, matrix);

        return result;
    }

    template <class Matrix, class MatrixRet = Matrix,
              meta::as_matrix<Matrix> = 0,
              meta::as_matrix<MatrixRet> = 0>
    MatrixRet inverse(Matrix& matrix) const
    {
        MatrixRet result(matrix.shape());

        inverse(result, matrix);

        return result;
    }

    template <class Tensor1, class Tensor2,
              meta::as_iterate<Tensor1> = 0,
              meta::as_iterate<Tensor2> = 0>
    void add(
        Tensor1& result,
        const Tensor2& rhs) const noexcept
    {
        detail::assign(first(result), last(result), detail::add(), first(rhs));
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              meta::as_iterate<Tensor1> = 0,
              meta::as_iterate<Tensor2> = 0,
              meta::as_iterate<Tensor3> = 0>
    void add(
        Tensor1& result,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        detail::assign(first(result), last(result), detail::add(), first(lhs), first(rhs));
    }

    template <class Tensor1, class Tensor2,
              meta::as_iterate<Tensor1> = 0,
              meta::as_iterate<Tensor2> = 0>
    void sub(
        Tensor1& result,
        const Tensor2& rhs) const noexcept
    {
        detail::assign(first(result), last(result), detail::sub(), first(rhs));
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              meta::as_iterate<Tensor1> = 0,
              meta::as_iterate<Tensor2> = 0,
              meta::as_iterate<Tensor3> = 0>
    void sub(
        Tensor1& result,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        detail::assign(first(result), last(result), detail::sub(), first(lhs), first(rhs));
    }

    template <class Tensor1, class Tensor2,
              meta::as_iterate<Tensor1> = 0,
              meta::as_iterate<Tensor2> = 0>
    void mul(
        Tensor1& result,
        const Tensor2& rhs) const noexcept
    {
        detail::assign(first(result), last(result), detail::mul(), first(rhs));
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              meta::as_iterate<Tensor1> = 0,
              meta::as_iterate<Tensor2> = 0,
              meta::as_iterate<Tensor3> = 0>
    void mul(
        Tensor1& result,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        detail::assign(first(result), last(result), detail::mul(), first(lhs), first(rhs));
    }

    template <class Tensor1,
              meta::as_iterate<Tensor1> = 0>
    void join(
        Tensor1& result,
        precision_type value) const noexcept
    {
        detail::assign(first(result), last(result), detail::mul(), value);
    }

    template <class Tensor1, class Tensor2,
              meta::as_iterate<Tensor1> = 0,
              meta::as_iterate<Tensor2> = 0>
    void join(
        Tensor1& result,
        precision_type value,
        const Tensor2& rhs) const noexcept
    {
        detail::assign(first(result), last(result), detail::mul(), value, first(rhs));
    }

    template <class Tensor, class Function,
              meta::as_iterate<Tensor> = 0>
    void apply(
        Tensor& result,
        Function func) const TRNOEXCEPT_IF(noexcept(func))
    {
        detail::apply(first(result), last(result), func);
    }

    template <class Tensor1, class Tensor2, class Function,
              meta::as_iterate<Tensor1> = 0,
              meta::as_iterate<Tensor2> = 0>
    void apply(
        Tensor1& result,
        Function func,
        const Tensor2& rhs) const TRNOEXCEPT_IF(noexcept(func))
    {
        detail::apply(first(result), last(result), func, first(rhs));
    }

    template <class Tensor1, class Tensor2,
              meta::as_iterate<Tensor1> = 0,
              meta::as_iterate<Tensor2> = 0>
    void assign(
        Tensor1& lhs,
        const Tensor2& rhs) const noexcept
    {
        detail::copy(first(lhs), last(lhs), first(rhs));
    }

    template <class Tensor, class Function,
              meta::as_iterate<Tensor> = 0>
    void loop(
        Tensor& tensor,
        Function func) const TRNOEXCEPT_IF(noexcept(func))
    {
        detail::for_each(first(tensor), last(tensor), func);
    }
};

} // namespace lique

} // namespace trixy

#include <random> // rand

namespace trixy
{

namespace lique
{

enum class Axis { X, Y, Z };

namespace comp
{

struct is_bigger
{
    template <typename T>
    bool operator() (T previous, T current) { return previous > current; }
};

struct is_less
{
    template <typename T>
    bool operator() (T previous, T current) { return previous < current; }
};

} // namespace comp

template <class T>
inline T sum(T&& t) noexcept { return t; }

template <class T, class... Tn,
          trixy::meta::require<trixy::meta::is_same_all<T, Tn...>::value> = 0>
inline T sum(T&& t, Tn&&... tn)
{
    return t + sum(std::forward<T>(tn)...);
}

template <class Iterable, lique::meta::as_iterate<Iterable> = 0>
inline auto first(Iterable& it) -> decltype(it.data())
{
    return it.data();
}

template <class Iterable, lique::meta::as_iterate<Iterable> = 0>
inline auto last(Iterable& it) -> decltype(it.data() + it.size())
{
    return it.data() + it.size();
}

template <typename InIt, typename T>
T accumulate(InIt first, InIt last, T init)
{
    detail::for_each(
        first, last, [&init](const T& value) { init += value; }
    );

    return init;
}

template <class FwdIt, class Binary>
FwdIt search(FwdIt first, FwdIt last, Binary compare) noexcept
{
    if (first == last) return first;

    auto hold = first;
    auto it = ++first;

    while (it != last)
    {
        if (compare(*hold, *it)) hold = it;

        ++it;
    }

    return hold;
}

template <class Iterable, class Binary,
          lique::meta::as_iterate<Iterable> = 0>
std::size_t search(const Iterable& it, Binary compare) noexcept
{
    return search(first(it), last(it), compare) - first(it);
}

template <typename Precision, class Binary>
Vector<std::size_t> search(const Matrix<Precision>& matrix, Axis axis, Binary compare) // repair
{
    using size_type = std::size_t;

    const size_type block_size = matrix.shape().width;
    const size_type number_of_blocks = matrix.shape().height;

    Vector<size_type> vector;
    size_type arg;

    if (axis == Axis::X)
    {
        vector.resize(block_size);
        vector.fill(size_type(0));

        for (size_type i = 1; i < number_of_blocks; ++i)
            for (size_type n = 0; n < vector.size(); ++n)
                if (compare(matrix(vector(n), n), matrix(i, n)))
                    vector(n) = i;
    }
    else if (axis == Axis::Y)
    {
        vector.resize(number_of_blocks);

        for (size_type n = 0; n < vector.size(); ++n)
        {
            for (size_type i = 1; i < block_size; ++i)
                if (compare(matrix(n, arg), matrix(n, i)))
                    arg = i;

            vector(n) = arg;
        }
    }

    return vector;
}

template <class FwdIt>
std::size_t argmin(FwdIt first, FwdIt last) noexcept
{
    return search(first, last, comp::is_bigger{}) - first;
}

template <class Iterable, lique::meta::as_iterate<Iterable> = 0>
std::size_t argmin(const Iterable& it) noexcept
{
    return search(it, comp::is_bigger{});
}

template <class FwdIt>
std::size_t argmax(FwdIt first, FwdIt last) noexcept
{
    return search(first, last, comp::is_less{}) - first;
}

template <class Iterable, lique::meta::as_iterate<Iterable> = 0>
std::size_t argmax(const Iterable& it) noexcept
{
    return search(it, comp::is_less{});
}

TRIXY_FUNCTION_TEMPLATE()
Vector<std::size_t> argmin(const Matrix<Precision>& matrix, Axis axis)
{
    return search(matrix, axis, comp::is_bigger{});
}

TRIXY_FUNCTION_TEMPLATE()
Vector<std::size_t> argmax(const Matrix<Precision>& matrix, Axis axis)
{
    return search(matrix, axis, comp::is_less{});
}

template <class FwdIt>
auto min(FwdIt first, FwdIt last) noexcept -> decltype(*search(first, last, comp::is_bigger{}))
{
    return *search(first, last, comp::is_bigger{});
}

template <class Iterable, typename precision_type = typename Iterable::precision_type,
          lique::meta::as_iterate<Iterable> = 0>
precision_type min(const Iterable& it) noexcept
{
    return it(search(it, comp::is_bigger{}));
}

template <class FwdIt>
auto max(FwdIt first, FwdIt last) noexcept -> decltype(*search(first, last, comp::is_less{}))
{
    return *search(first, last, comp::is_less{});
}

template <class Iterable, typename precision_type = typename Iterable::precision_type,
          lique::meta::as_iterate<Iterable> = 0>
precision_type max(const Iterable& it) noexcept
{
    return it(search(it, comp::is_less{}));
}

template <class InIt, typename T>
T mean(InIt first, InIt last, T init) noexcept
{
    init = lique::accumulate(first, last, init);

    return init / static_cast<T>(last - first);
}

template <class Iterable, typename T = double, lique::meta::as_iterate<Iterable> = 0>
T mean(const Iterable& it) noexcept
{
    return mean(first(it), last(it), T{});
}

template <class InIt, typename T>
T std(InIt first, InIt last, T init, bool unbiased = false)
{
    T mean_value = mean(first, last, init);
    T std_value{};

    auto it = first;

    while (it != last)
    {
        init = *it - mean_value;
        std_value += init * init;

        ++it;
    }

    std_value /= static_cast<T>(last - first - unbiased);

    return static_cast<T>(std::sqrt(std_value));
}

template <class Iterable, typename T = double,
          lique::meta::as_iterate<Iterable> = 0>
T std(const Iterable& it, bool unbiased = false)
{
    return std(first(it), last(it), T{}, unbiased);
}

TRIXY_FUNCTION_TEMPLATE()
Vector<double> mean(const Matrix<Precision>& matrix, Axis axis) // repair
{
    using size_type = typename Matrix<Precision>::size_type;

    const size_type block_size = matrix.shape().width;
    const size_type number_of_blocks = matrix.shape().height;

    auto m_first = first(matrix);
    auto m_last  = last(matrix);

    Vector<double> vector;

    if (axis == Axis::X)
    {
        vector.resize(block_size, Precision(0.));

        auto v_first = first(vector);
        auto v_last = last(vector);

        while (m_first != m_last)
        {
            detail::assign(v_first, v_last, detail::add(), m_first);
            m_first += vector.size();
        }

        vector.join( 1. / static_cast<double>(number_of_blocks));
    }
    else if (axis == Axis::Y)
    {
        vector.resize(number_of_blocks);

        auto v_first = first(vector);
        auto v_last = last(vector);

        while (v_first != v_last)
        {
            *v_first = lique::accumulate(m_first, m_first + block_size, Precision(0.));

            m_first += block_size;
            ++v_first;
        }

        vector.join(1. / static_cast<double>(block_size));
    }

    return vector;
}

TRIXY_FUNCTION_TEMPLATE()
Vector<double> std(const Matrix<Precision>& matrix, Axis axis, bool unbiased = false)
{
    using size_type = typename Matrix<Precision>::size_type;

    const size_type block_size = matrix.shape().width;
    const size_type number_of_blocks = matrix.shape().height;

    Vector<double> vector = mean(matrix, axis);

    double std_value;
    double mean_value;

    double buff;

    auto accumulate_std = [buff](double mean, double value, double& accumulate) mutable
    {
        buff = mean - value;
        accumulate += buff * buff;
    };

    if (axis == Axis::X)
    {
        for (size_type i = 0; i < vector.size(); ++i)
        {
            std_value = 0.;
            for (size_type n = 0; n < number_of_blocks; ++n)
                accumulate_std(vector(i), matrix(n, i), std_value);

            vector(i) = std_value;
        }

        vector.join(1. / static_cast<double>(number_of_blocks - unbiased));
        vector.apply<double (*)(double)>(std::sqrt);
    }
    else
    {
        auto v_first = first(vector);
        auto v_last  = last(vector);

        auto m_first = first(matrix);

        while (v_first != v_last)
        {
            std_value = 0.;

            mean_value = *v_first;
            auto accumulate_adapter = [accumulate_std, mean_value, &std_value](double value)
            {
                accumulate_std(mean_value, value, std_value);
            };

            detail::for_each(m_first, m_first + block_size, accumulate_adapter);
            *v_first = std_value;

            m_first += block_size;
            ++v_first;
        }

        vector.join(1. / static_cast<double>(block_size - unbiased));
        vector.apply<double (*)(double)>(std::sqrt);
    }

    return vector;
}

using detail::for_each;

template <class Iterable, class Function,
          lique::meta::as_iterate<Iterable> = 0>
void loop(Iterable& it, Function func) TRNOEXCEPT_IF(noexcept(func))
{
    detail::for_each(first(it), last(it), func);
}

template <class FwdIt, class Function>
void block_loop(
    FwdIt A,
    FwdIt B,
    std::size_t extern_block_width,
    Function func) TRNOEXCEPT_IF(noexcept(func))
{
    detail::block_for_each(A, B, extern_block_width, func);
}

namespace detail
{

template <class T, lique::meta::as_iterate<T> = 0>
void concat(T& out, std::size_t& at, const T& it)
{
    detail::copy(out.data() + at, out.data() + at + it.size(), it.data());
}

template <class T, class... Tn,
          lique::meta::as_iterate<T> = 0,
          trixy::meta::require<trixy::meta::is_same_all<T, Tn...>::value> = 0>
void concat(T& out, std::size_t& at, const T& it, const Tn&... it_n)
{
    detail::copy(out.data() + at, out.data() + at + it.size(), it.data());
    at += it.size();

    concat(out, at, it_n...);
}

} // namespace detail

template <class Iterable, template <typename...> class Container,
          lique::meta::as_iterate<Iterable> = 0>
Iterable concat(const Container<Iterable>& list)
{
    using size_type = typename Iterable::size_type;

    size_type accumulate_size = 0;

    for (const auto& it : list) accumulate_size += it.size();

    Iterable it(accumulate_size);

    size_type at = 0;
    for (const auto& it : list)
    {
        detail::copy(it.data() + at, it.data() + at + it.size(), it.data());
        at += it.size();
    }

    return it;
}

template <class T, class... Tn,
          lique::meta::as_iterate<T> = 0,
          trixy::meta::require<trixy::meta::is_same_all<T, Tn...>::value> = 0>
T concat(const T& it, const Tn&... it_n)
{
    using size_type = typename T::size_type;

    T out = sum(it.size(), it_n.size()...);

    size_type position = 0;
    detail::concat(out, position, it, it_n...);

    return out;
}

template <class FwdIt, class Generator>
std::size_t multinomial(FwdIt first, FwdIt last, Generator generator, std::size_t rand_max) noexcept
{
    using precision_type = trixy::meta::decay<decltype(*first)>;

    // random_value satisfies the range [0, 1]
    precision_type random_value = precision_type(generator()) / precision_type(rand_max);

    precision_type accumulate = 0.;

    auto it = first;

    while (it != last)
    {
        accumulate += *it;

        if (random_value < accumulate) return std::size_t(it - first);

        ++it;
    }

    // special case for invalid input data
    // finding max it* in the sequance
    return std::size_t(search(first, last, comp::is_less{}) - first);
}

template <class Iterable, class Generator, lique::meta::as_iterate<Iterable> = 0>
std::size_t multinomial(const Iterable& it, Generator generator, std::size_t rand_max) noexcept
{
    return multinomial(first(it), last(it), generator, rand_max);
}

template <class FwdIt>
std::size_t multinomial(FwdIt first, FwdIt last) noexcept
{
    return multinomial(first, last, std::rand, RAND_MAX);
}

template <class Iterable, lique::meta::as_iterate<Iterable> = 0>
std::size_t multinomial(const Iterable& it) noexcept
{
    return multinomial(it, std::rand, RAND_MAX);
}

} // namespace lique

} // namespace trixy

namespace trixy
{

namespace ilique
{

template <typename tensor_type,
          template <typename, typename...> class Derived,
          typename Precision, typename... Pack>
class ITensor;

template <template <typename, typename...> class Derived,
          typename Precision, typename... Pack>
class ITensorBase : public lique::TensorType::base
{
public:
    using Tensor            = Derived<Precision, Pack...>;

public:
    using size_type         = std::size_t;
    using precision_type    = Precision;
    using shape_type        = lique::Shape<std::size_t>;

    using pointer           = Precision*;
    using const_pointer     = const Precision*;

    using reference         = Precision&;
    using const_reference   = const Precision&;

private:
    Tensor& self() noexcept
    { return *static_cast<Tensor*>(this); }

    const Tensor& self() const noexcept
    { return *static_cast<const Tensor*>(this); }

public:
    Tensor& copy(const Tensor& tensor) noexcept { return self().copy(tensor); }

    Tensor& fill(Precision value) noexcept { return self().fill(value); }

    template <class Generator, TRREQUIRE(meta::is_callable<Generator>::value)>
    Tensor& fill(Generator gen) noexcept { return self().fill(gen); }

    template <class Function>
    Tensor  apply(Function func) const { return self().apply(func); }

    template <class Function>
    Tensor& apply(Function func) noexcept { return self().apply(func); }

    template <class Function>
    Tensor& apply(Function func, const Tensor& tensor) noexcept
    { return self().apply(func, tensor); }

    template <class Function>
    Tensor& apply(Function func, const_pointer src) noexcept
    { return self().apply(func, src); }

    Tensor  mul(const Tensor& tensor) const { return self().mul(tensor); }
    Tensor& mul(const Tensor& tensor) noexcept { return self().mul(tensor); }

    Tensor& mul(const Tensor& lhs, const Tensor& rhs) noexcept
    { return self().mul(lhs, rhs); }

    Tensor  join(Precision value) const { return self().join(value); }
    Tensor& join(Precision value) noexcept { return self().join(value); }

    Tensor& join(Precision value, const Tensor& tensor) noexcept
    { return self().join(value, tensor); }

    Tensor  add(const Tensor& tensor) const { return self().add(tensor); }
    Tensor& add(const Tensor& tensor) noexcept { return self().add(tensor); }

    Tensor& add(const Tensor& lhs, const Tensor& rhs) noexcept
    { return self().add(lhs, rhs); }

    Tensor  sub(const Tensor& tensor) const { return self().sub(tensor); }
    Tensor& sub(const Tensor& tensor) noexcept { return self().sub(tensor); }

    Tensor& sub(const Tensor& lhs, const Tensor& rhs) noexcept
    { return self().sub(lhs, rhs); }

    pointer data() noexcept { return self().data(); }
    const_pointer data() const noexcept { return self().data(); }

    size_type size() const noexcept { return self().size(); }
    const shape_type& shape() const noexcept { return self().shape(); }

    void swap(Tensor& tensor) noexcept { self().swap(tensor); }

    reference operator() (size_type i) noexcept { return self().operator()(i); }
    const_reference operator() (size_type i) const noexcept { return self().operator()(i); }
};

} // namespace ilique

} // namespace trixy

// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define ILIQUE_TENSOR_TEMPLATE(...)                                                                     \
    TRIXY_TEMPLATE(template <typename, typename...> class Derived,                                      \
                   typename Precision, typename... Pack)

#define ILIQUE_TENSOR_TEMPLATE_CLASS(...)                                                               \
    ITensor<__VA_ARGS__, Derived, Precision, Pack...>

#define _ILIQUE_TENSOR_BASE_TYPES(...)                                                                  \
    private:                                                                                            \
        using Base = ITensorBase<Derived, Precision, Pack...>;                                          \
                                                                                                        \
    public:                                                                                             \
        using typename Base::size_type;                                                                 \
        using typename Base::precision_type;                                                            \
        using typename Base::shape_type;                                                                \
                                                                                                        \
        using typename Base::pointer;                                                                   \
        using typename Base::const_pointer;                                                             \
                                                                                                        \
        using typename Base::reference;                                                                 \
        using typename Base::const_reference;

#define _ILIQUE_TENSOR_BASE_FUNCIONS(...)                                                               \
    public:                                                                                             \
        using Base::copy;                                                                               \
        using Base::fill;                                                                               \
        using Base::apply;                                                                              \
                                                                                                        \
        using Base::add;                                                                                \
        using Base::sub;                                                                                \
        using Base::mul;                                                                                \
        using Base::join;                                                                               \
                                                                                                        \
        using Base::data;                                                                               \
        using Base::size;                                                                               \
        using Base::shape;                                                                              \
                                                                                                        \
        using Base::operator();                                                                         \
                                                                                                        \
    protected:                                                                                          \
        using Base::self;

#define ILIQUE_TENSOR_BASE_BODY(...)                                                                    \
    _ILIQUE_TENSOR_BASE_TYPES(__VA_ARGS__)                                                              \
    _ILIQUE_TENSOR_BASE_FUNCIONS(__VA_ARGS__)

namespace trixy
{

namespace ilique
{

ILIQUE_TENSOR_TEMPLATE()
using IVector = ILIQUE_TENSOR_TEMPLATE_CLASS(lique::TensorType::vector);

ILIQUE_TENSOR_TEMPLATE()
class ILIQUE_TENSOR_TEMPLATE_CLASS(lique::TensorType::vector)
    : protected ilique::ITensorBase<Derived, Precision, Pack...>
    , public lique::TensorType::vector
{
    ILIQUE_TENSOR_BASE_BODY()

public:
    void resize(const shape_type& shape) { self().resize(shape); }
    void resize(size_type width) { self().resize(width); }

    void reshape(size_type width) noexcept { self().reshape(width); }
};

} // namespace ilique

} // namespace trixy

namespace trixy
{

namespace ilique
{

ILIQUE_TENSOR_TEMPLATE()
using IMatrix = ILIQUE_TENSOR_TEMPLATE_CLASS(lique::TensorType::matrix);

ILIQUE_TENSOR_TEMPLATE()
class ILIQUE_TENSOR_TEMPLATE_CLASS(lique::TensorType::matrix)
    : protected ilique::ITensorBase<Derived, Precision, Pack...>
    , public lique::TensorType::matrix
{
    ILIQUE_TENSOR_BASE_BODY()

public:
    reference operator() (size_type i, size_type j) noexcept
    { return self().operator()(i, j); }

    const_reference operator() (size_type i, size_type j) const noexcept
    { return self().operator()(i, j); }

    void resize(const shape_type& shape) { self().resize(shape); }
    void resize(size_type height, size_type width) { self().resize(height, width); }

    void reshape(size_type height, size_type width) noexcept { self().reshape(height, width); }
};

} // namespace ilique

} // namespace trixy

namespace trixy
{

namespace ilique
{

ILIQUE_TENSOR_TEMPLATE()
class ILIQUE_TENSOR_TEMPLATE_CLASS(lique::TensorType::tensor)
    : protected ilique::ITensorBase<Derived, Precision, Pack...>
    , public lique::TensorType::tensor
{
    ILIQUE_TENSOR_BASE_BODY()

public:
    reference operator() (size_type i, size_type j, size_type k) noexcept
    { return self().operator()(i, j, k); }

    const_reference operator() (size_type i, size_type j, size_type k) const noexcept
    { return self().operator()(i, j, k); }

    void resize(const shape_type& shape) { self().resize(shape); }
    void resize(size_type depth, size_type height, size_type width)
    { self().resize(depth, height, width); }

    void reshape(size_type depth, size_type height, size_type width) noexcept
    { self().reshape(depth, height, width); }
};

} // namespace ilique

} // namespace trixy

namespace trixy
{

namespace ilique
{

template <template <typename, typename...> class Derived,
          typename Precision, typename... Pack>
class ILinear
{
private:
    template <class T>
    using as_flat_iterate =
        trixy::meta::require<not lique::meta::is_matrix<T>::value and
                             lique::meta::is_iterate<T>::value>;

public:
    using Linear         = Derived<Precision, Pack...>;

    using size_type      = std::size_t;
    using precision_type = Precision;

private:
    const Linear& self() const { return *static_cast<const Linear*>(this); }

public:
    template <class Vector1, class Vector2, class Matrix,
              as_flat_iterate<Vector1> = 0,
              as_flat_iterate<Vector2> = 0,
              lique::meta::as_matrix<Matrix> = 0>
    void dot(
        Vector1& result,
        const Vector2& row_vector,
        const Matrix& matrix) const noexcept
    {
        self().dot(result, row_vector, matrix);
    }

    template <class Vector1, class Vector2, class Matrix,
              as_flat_iterate<Vector1> = 0,
              as_flat_iterate<Vector2> = 0,
              lique::meta::as_matrix<Matrix> = 0>
    void dot(
        Vector1& result,
        const Matrix& matrix,
        const Vector2& col_vector) const noexcept
    {
        self().dot(result, matrix, col_vector);
    }

    template <class Vector1, class Vector2, class Matrix,
              as_flat_iterate<Vector1> = 0,
              as_flat_iterate<Vector2> = 0,
              lique::meta::as_matrix<Matrix> = 0>
    void tensordot(
        Matrix& buff2,
        const Vector1& col_vector,
        const Vector2& row_vector) const noexcept
    {
        self().tensordot(buff2, col_vector, row_vector);
    }

    template <class Matrix1, class Matrix2, class Matrix3,
              lique::meta::as_matrix<Matrix1> = 0,
              lique::meta::as_matrix<Matrix2> = 0,
              lique::meta::as_matrix<Matrix3> = 0>
    void dot(
        Matrix1& result,
        const Matrix2& lhs,
        const Matrix3& rhs) const noexcept
    {
        self().dot(result, lhs, rhs);
    }

    template <class Matrix1, class Matrix2,
              lique::meta::as_matrix<Matrix1> = 0,
              lique::meta::as_matrix<Matrix2> = 0>
    void transpose(
        Matrix1& result,
        const Matrix2& matrix) const noexcept
    {
        self().transpose(result, matrix);
    }

    template <class Matrix1, class Matrix2,
              lique::meta::as_matrix<Matrix1> = 0,
              lique::meta::as_matrix<Matrix2> = 0>
    void inverse(
        Matrix1& result,
        Matrix2& matrix) const noexcept
    {
        self().inverse(result, matrix);
    }

    template <class Tensor1, class Tensor2,
              lique::meta::as_iterate<Tensor1> = 0,
              lique::meta::as_iterate<Tensor2> = 0>
    void add(
        Tensor1& result,
        const Tensor2& tensor) const noexcept
    {
        self().add(result, tensor);
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              lique::meta::as_iterate<Tensor1> = 0,
              lique::meta::as_iterate<Tensor2> = 0,
              lique::meta::as_iterate<Tensor3> = 0>
    void add(
        Tensor1& result,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        self().add(result, lhs, rhs);
    }

    template <class Tensor1, class Tensor2,
              lique::meta::as_iterate<Tensor1> = 0,
              lique::meta::as_iterate<Tensor2> = 0>
    void sub(
        Tensor1& result,
        const Tensor2& tensor) const noexcept
    {
        self().sub(result, tensor);
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              lique::meta::as_iterate<Tensor1> = 0,
              lique::meta::as_iterate<Tensor2> = 0,
              lique::meta::as_iterate<Tensor3> = 0>
    void sub(
        Tensor1& result,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        self().sub(result, lhs, rhs);
    }

    template <class Tensor1, class Tensor2,
              lique::meta::as_iterate<Tensor1> = 0,
              lique::meta::as_iterate<Tensor2> = 0>
    void mul(
        Tensor1& result,
        const Tensor2& tensor) const noexcept
    {
        self().mul(result, tensor);
    }

    template <class Tensor1, class Tensor2, class Tensor3,
              lique::meta::as_iterate<Tensor1> = 0,
              lique::meta::as_iterate<Tensor2> = 0,
              lique::meta::as_iterate<Tensor3> = 0>
    void mul(
        Tensor1& result,
        const Tensor2& lhs,
        const Tensor3& rhs) const noexcept
    {
        self().mul(result, lhs, rhs);
    }

    template <class Tensor1,
              lique::meta::as_iterate<Tensor1> = 0>
    void join(
        Tensor1& result,
        precision_type value) const noexcept
    {
        self().join(result, value);
    }

    template <class Tensor1, class Tensor2,
              lique::meta::as_iterate<Tensor1> = 0,
              lique::meta::as_iterate<Tensor2> = 0>
    void join(
        Tensor1& result,
        precision_type value,
        const Tensor2& tensor) const noexcept
    {
        self().join(result, value, tensor);
    }

    template <class Tensor, class Function,
              lique::meta::as_iterate<Tensor> = 0>
    void apply(
        Tensor& result,
        Function func) const TRNOEXCEPT_IF(noexcept(func))
    {
        self().apply(result, func);
    }

    template <class Tensor1, class Tensor2, class Function,
              lique::meta::as_iterate<Tensor1> = 0,
              lique::meta::as_iterate<Tensor2> = 0>
    void apply(
        Tensor1& result,
        Function func,
        const Tensor2& tensor) const TRNOEXCEPT_IF(noexcept(func))
    {
        self().apply(result, func, tensor);
    }

    template <class Tensor1, class Tensor2,
              lique::meta::as_iterate<Tensor1> = 0,
              lique::meta::as_iterate<Tensor2> = 0>
    void assign(
        Tensor1& lhs,
        const Tensor2& rhs) const noexcept
    {
        self().assign(lhs, rhs);
    }

    template <class Tensor, class Function,
              lique::meta::as_iterate<Tensor> = 0>
    void loop(
        Tensor& tensor,
        Function func) const TRNOEXCEPT_IF(noexcept(func))
    {
        self().loop(tensor, func);
    }
};

} // namespace ilique

} // namespace trixy

namespace trixy
{

template <typename TypeSet, typename TrixyNetType = TrixyNetType::Unified>
class TrixyNet;

namespace guard
{

template <typename TypeSet, typename TrixyNetType = TrixyNetType::Unified>
struct TrixyNetRequire;

} // namespace guard

} // namespace trixy

namespace trixy
{

namespace guard
{

template <typename Precision>
using PrecisionRequire = Require<Precision, RequireType::precision>;

template <typename Precision>
struct Require<Precision, RequireType::precision>
{
public:
    using type = RequireType::precision;

protected:
    using require = Precision;

protected:
    static constexpr bool precision_require = std::is_floating_point<require>::value;

    static_assert(precision_require, "'Precision' is not a floating point type.");
};

} // namespace guard

} // namespace trixy

namespace trixy
{

namespace guard
{

template <class Tensor>
using VectorRequire = Require<Tensor, RequireType::vector>;

template <class Tensor>
struct Require<Tensor, RequireType::vector> : protected Tensor
{
public:
    using type = RequireType::vector;

protected:
    static constexpr bool vector_require =
        std::is_base_of<lique::TensorType::vector, Tensor>::value;

    static_assert(vector_require, "'Tensor' is not base of trixy::lique::TensorType::vector.");

    using require = Tensor;

protected:
    using typename require::size_type;
    using typename require::precision_type;
    using typename require::value_type;
    using typename require::shape_type;

    using typename require::pointer;
    using typename require::const_pointer;

    using typename require::reference;
    using typename require::const_reference;

    using typename require::range_view;

protected:
    using require::copy;

    using require::shape; // maybe unused
    using require::size;

    using require::resize;
    using require::reshape; // maybe unused

    using require::fill;
    using require::apply;

    using require::operator();
    using require::operator range_view;

    using require::add;
    using require::sub;
    using require::mul;
    using require::join;

    using require::swap; // maybe unused

    using require::data;
};

} // namespace guard

} // namespace trixy

namespace trixy
{

namespace guard
{

template <class Tensor>
using MatrixRequire = Require<Tensor, RequireType::matrix>;

template <class Tensor>
struct Require<Tensor, RequireType::matrix> : protected Tensor
{
public:
    using type = RequireType::matrix;

protected:
    static constexpr bool matrix_require =
        std::is_base_of<lique::TensorType::matrix, Tensor>::value;

    static_assert(matrix_require, "'Tensor' is not base of trixy::lique::TensorType::matrix.");

    using require = Tensor;

protected:
    using typename require::size_type;
    using typename require::precision_type;
    using typename require::value_type;
    using typename require::shape_type;

    using typename require::pointer;
    using typename require::const_pointer;

    using typename require::reference;
    using typename require::const_reference;

    using typename require::range_view;

protected:
    using require::copy;

    using require::shape;
    using require::size;

    using require::resize;
    using require::reshape; // maybe unused

    using require::fill;
    using require::apply; // maybe unused

    using require::operator();
    using require::operator range_view;

    using require::add;
    using require::sub;
    using require::mul;
    using require::join;

    using require::swap; // maybe unused

    using require::data;
};

} // namespace guard

} // namespace trixy

namespace trixy
{

namespace guard
{

template <class Tensor>
using TensorRequire = Require<Tensor, RequireType::tensor>;

template <class Tensor>
struct Require<Tensor, RequireType::tensor> : protected Tensor
{
public:
    using type = RequireType::tensor;

protected:
    static constexpr bool tensor_require =
        std::is_base_of<lique::TensorType::tensor, Tensor>::value;

    static_assert(tensor_require, "'Tensor' is not base of trixy::lique::TensorType::tensor.");

    using require = Tensor;

protected:
    using typename require::size_type;
    using typename require::precision_type;
    using typename require::value_type;
    using typename require::shape_type;

    using typename require::pointer;
    using typename require::const_pointer;

    using typename require::reference;
    using typename require::const_reference;

    using typename require::range_view;

protected:
    using require::copy;

    using require::shape;
    using require::size;

    using require::resize;
    using require::reshape; // maybe unused

    using require::fill;
    using require::apply; // maybe unused

    using require::operator();
    using require::operator range_view;

    using require::add;
    using require::sub;
    using require::mul;
    using require::join;

    using require::swap; // maybe unused

    using require::data;
};

} // namespace guard

} // namespace trixy

namespace trixy
{

namespace guard
{

template <class Container>
using ContainerRequire = Require<Container, RequireType::container>;

template <class Container>
struct Require<Container, RequireType::container> : protected Container
{
public:
    using type = RequireType::container;

protected:
    using require = Container;

protected:
    using typename require::iterator;
    using typename require::const_iterator;

protected:
    using typename require::size_type;
    using typename require::value_type;
    using typename require::difference_type;

    using typename require::pointer;
    using typename require::const_pointer;

    using typename require::reference;
    using typename require::const_reference;

protected:
    using require::capacity;
    using require::size;
    using require::max_size;

    using require::resize;
    using require::reserve;

    using require::emplace_back;
    using require::pop_back;

    using require::empty;

    using require::begin;
    using require::end;
    using require::cbegin;
    using require::cend;

    using require::front;
    using require::back;

    using require::data;

    using require::operator[];
};

} // namespace guard

} // namespace trixy

// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define TRIXY_NET_TEMPLATE(...) TRIXY_TEMPLATE(typename TypeSet)
#define TRIXY_SERIALIZER_TEMPLATE(...) TRIXY_TEMPLATE(class Serializable)
#define TRIXY_FUNCTIONAL_TEMPLATE(...) TRIXY_TEMPLATE(class Functionable)
#define TRIXY_OPTIMIZER_TEMPLATE(...) TRIXY_TEMPLATE(class Optimizeriable, class TypeSet)
#define TRIXY_TRAINING_TEMPLATE(...) TRIXY_TEMPLATE(class Trainable)
#define TRIXY_REGRESSION_TEMPLATE(...) TRIXY_TEMPLATE(typename TypeSet)

#define TRIXY_OPTIMIZER_TEMPLATE_CLASS(is_type, optimizer_type)                                         \
    Optimizer<optimizer_type, Optimizeriable, TypeSet, TRWITH(Optimizeriable, is_type)>

namespace trixy
{

namespace guard
{

TRIXY_NET_TEMPLATE()
struct TrixyNetRequire<TypeSet, TrixyNetType::Unified>
{
public:
    using type = TrixyNetType::Unified;

protected:
    using precision_type    = typename TypeSet::precision_type;

    using Vector            = typename TypeSet::Vector;
    using Matrix            = typename TypeSet::Matrix;

    using Linear            = typename TypeSet::Linear;

    using Container         = typename TypeSet::template Container<precision_type>;

protected:
    using require_precision = typename PrecisionRequire<precision_type>::type;

    using require_vector    = typename VectorRequire<Vector>::type;
    using require_matrix    = typename MatrixRequire<Matrix>::type;

    using require_linear    = typename LinearRequire<Linear>::type;

    using require_container = typename ContainerRequire<Container>::type;
};

} // namespace guard

} // namespace trixy

#include <functional> // function

namespace trixy
{

namespace functional
{

struct ActivationType {};

namespace activation
{

template <typename Precision>
class IActivation : public ActivationType, public sf::Instantiable
{
    SERIALIZABLE(IActivation)

public:
    using precision_type = Precision;
    using Range = utility::Range<Precision>;

public:
    virtual ~IActivation() = default;

    virtual void f(Range result, const Range input) noexcept = 0;
    virtual void df(const Range result, const Range input) noexcept = 0;
};

} // namespace activation

struct LossType {};

namespace loss
{

template <typename Precision>
class ILoss : public LossType, public sf::Instantiable
{
    SERIALIZABLE(ILoss)

public:
    using precision_type = Precision;
    using Range = utility::Range<Precision>;

public:
    virtual ~ILoss() = default;

    virtual void f(precision_type& result, const Range y_true, const Range y_pred) noexcept = 0;
    virtual void df(Range result, const Range y_true, const Range y_pred) noexcept = 0;
};

} // namespace loss

} // namespace functional

namespace meta
{

template <typename T> struct is_iactivation : std::is_base_of<functional::ActivationType, T> {};
template <typename T> struct is_iloss : std::is_base_of<functional::LossType, T> {};

} // namespace meta

} // namespace trixy

CONDITIONAL_SERIALIZATION(SaveLoad, trixy::meta::is_iactivation<T>::value) {}
CONDITIONAL_SERIALIZATION(SaveLoad, trixy::meta::is_iloss<T>::value) {}

// This file contains all enum functional, you MUST prevent rewriting him,
// since changes can breake a TrixyNet deserialization proccess

namespace trixy
{

namespace functional
{

enum class ActivationId : std::uint8_t
{
    undefined = 0,          ///< default null value
    identity = 1,           ///< same value from input
    sigmoid = 2,            ///< sigmoid(x) = 1 / (exp(-x) + 1)
    tanh = 3,               ///< hyperbolic tangent
    relu = 4,               ///< relu(x) = max(0, x) (Rectified Linear Unit)
    elu = 5,                ///< exponential relu with alpha = 0.2
    lrelu = 6,              ///< leaky relu (same as relu, but with low negative signal)
    selu = 7,               ///< exponential relu with lambda = 1.050701, beta = 1.758099
    gelu = 8,               ///< gaussian relu
    softsign = 9,           ///< absolute value hyperbola
    softplus = 10,          ///< logarithm with exponential argument
    swish = 11,             ///< same as relu & sigmoid
    softmax = 12,           ///< normalization function
    mod_relu = 13,          ///< relu for range [0, 1]
    mod_tanh = 14,          ///< tanh for range [0, 1]
    unstable_softmax = 15,  ///< deprecated
    size
};

enum class LossId : std::uint8_t
{
    undefined = 0,          ///< default null value
    MSE = 1,                ///< mean squared error
    MAE = 2,                ///< mean absolute error
    CCE = 3,                ///< categorical cross entropy (for softmax)
    BCE = 4,                ///< binary cross entropy (for sigmoid)
    MSLE = 5,               ///< mean squared logarithmic error
    NLL = 6,                ///< negative logarithmic likelihood (for softmax)
    LC = 7,                 ///< logcosh (maybe unused)
    CCE_ = 8,               ///< categorical cross entropy (deprecated)
    BCE_ = 9,               ///< binary_cross_entropy (maybe unused)
    size
};

enum class OptimizationId : std::uint8_t
{
    undefined = 0,          ///< Default null value
    grad_descent = 1,       ///< Gradient descent optimizer
    stograd_descent = 2,    ///< Stochastic Gradient Descent optimizer
    momentum = 3,           ///< Momentum (slowed & stable)
    nestorov = 4,           ///< Nesterov accelerated gradient (modified momentum)
    ada_grad = 5,           ///< Adaptive Gradient algorithm (stable)
    rms_prop = 6,           ///< Root Mean Square Propagation (horny)
    adam = 7,               ///< Adaptive moment estimation (quick)
    size
};

} // namespace functional

} // namespace trixy

#define _TRIXY_DEF_OPTIMIZER_HELPER(id_type, T)                                                         \
    struct T {                                                                                          \
        template <id_type id>                                                                           \
        using type = ::trixy::meta::select_for<id == id_type::T, T>;                                    \
    };

namespace trixy
{

namespace train
{

struct OptimizerTypeSet
{
    template <typename Key, typename Value>
    using Table = std::unordered_map<Key, Value>;
};

template <class OptimizerType,
          class Optimizeriable,
          class TypeSet = OptimizerTypeSet,
          typename enable = void>
class Optimizer;

template <class Optimizeriable, typename enable = void>
class IOptimizer;

struct OptimizerType
{
private:
    template <class... Bn>
    using switch_type = typename meta::or_<Bn...>::type;

    using id_type = trixy::functional::OptimizationId;

public:
    _TRIXY_DEF_OPTIMIZER_HELPER(id_type, undefined)
    _TRIXY_DEF_OPTIMIZER_HELPER(id_type, grad_descent)
    _TRIXY_DEF_OPTIMIZER_HELPER(id_type, stograd_descent)
    _TRIXY_DEF_OPTIMIZER_HELPER(id_type, momentum)
    _TRIXY_DEF_OPTIMIZER_HELPER(id_type, nestorov)
    _TRIXY_DEF_OPTIMIZER_HELPER(id_type, ada_grad)
    _TRIXY_DEF_OPTIMIZER_HELPER(id_type, rms_prop)
    _TRIXY_DEF_OPTIMIZER_HELPER(id_type, adam)

public:
    template <id_type id> using type_from = switch_type
    <
        undefined::type<id>,
        grad_descent::type<id>,
        stograd_descent::type<id>,
        momentum::type<id>,
        nestorov::type<id>,
        ada_grad::type<id>,
        rms_prop::type<id>,
        adam::type<id>
    >;
};

} // namespace train

} // namespace trixy

// clean up
#undef _TRIXY_DEF_OPTIMIZER_HELPER

namespace trixy
{

namespace layer
{

template <typename LayerType, class Net, typename LayerMode>
class Layer;

template <class Net>
class ILayer : public sf::Instantiable
{
    SERIALIZABLE(ILayer)

public:
    template <typename T>
    using Container             = typename Net::template Container<T>;

    using Vector                = typename Net::Vector;
    using Matrix                = typename Net::Matrix;
    using Tensor                = typename Net::Tensor;

    using XVector               = typename Net::XVector;
    using XMatrix               = typename Net::XMatrix;
    using XTensor               = typename Net::XTensor;

    using size_type             = typename Net::size_type;
    using precision_type        = typename Net::precision_type;
    using shape_type            = typename Net::Tensor::shape_type;

    using Linear                = typename Net::Linear;

    using Generator             = std::function<precision_type()>; // type erasing
    using IActivation           = functional::activation::IActivation<precision_type>;

    using IOptimizer = train::IOptimizer<Net>;

public:
    virtual ~ILayer() = default;

    virtual void init(Generator& generator) noexcept { /*pass*/ }
    virtual void connect(IActivation* activation) = 0;

    virtual void forward(const Tensor& input) noexcept = 0;
    virtual const Tensor& value() const noexcept = 0;

    virtual const shape_type& isize() const noexcept = 0;
    virtual const shape_type& osize() const noexcept = 0;
};

template <class Net>
class ITrainLayer : public ILayer<Net>
{
    SERIALIZABLE(ITrainLayer)

    using Base = ILayer<Net>;

public:
    template <typename T>
    using Container = typename Base::template Container<T>;

    using typename Base::Vector;
    using typename Base::Matrix;
    using typename Base::Tensor;

    using typename Base::XVector;
    using typename Base::XMatrix;
    using typename Base::XTensor;

    using typename Base::size_type;
    using typename Base::precision_type;
    using typename Base::shape_type;

    using typename Base::Linear;

    using typename Base::Generator;
    using typename Base::IActivation;

    using typename Base::IOptimizer;

public:
    virtual ~ITrainLayer() = default;

public:
    virtual void backward(const Tensor& input, const Tensor& idelta, bool full = true) noexcept = 0;
    virtual const Tensor& delta() const noexcept = 0;

    virtual void update(IOptimizer& optimizer, precision_type alpha) noexcept { /*pass*/ }

    virtual void accumulate() noexcept { /*pass*/ }
    virtual void reset() noexcept { /*pass*/ }
};

} // namespace layer

namespace meta
{

template <typename T> struct is_ilayer : std::false_type {};
template <class Net> struct is_ilayer<layer::ILayer<Net>> : std::true_type {};

template <typename T> struct is_itrain_layer : std::false_type {};
template <class Net> struct is_itrain_layer<layer::ITrainLayer<Net>> : std::true_type {};

} // namespace meta

} // namespace trixy

CONDITIONAL_SERIALIZATION(SaveLoad, trixy::meta::is_ilayer<T>::value) {}
CONDITIONAL_SERIALIZATION(SaveLoad, trixy::meta::is_itrain_layer<T>::value) {}

namespace trixy
{

namespace meta
{

template <typename T>
struct locker_trait;

template <class Lockable, typename LockerType>
struct locker_trait<memory::Locker<Lockable, LockerType>>
{
    using lockable = Lockable;
};

} // namespace meta

} // namespace trixy

CONDITIONAL_SERIALIZATION(SaveLoad, trixy::meta::is_locker<T>::value)
{
    using lockable = typename trixy::meta::locker_trait<T>::lockable;
    archive & sf::base<lockable>(self);
}

namespace trixy
{

namespace memory
{

template <class Tensor>
using VectorLocker = Locker<Tensor, LockerType::vector>;

template <class Tensor>
class Locker<Tensor, LockerType::vector> : protected Tensor
{
    SERIALIZATION_ACCESS()

protected:
    using require = Tensor;

public:
    using typename require::size_type;
    using typename require::precision_type;
    using typename require::value_type;

    using typename require::pointer;
    using typename require::const_pointer;

    using typename require::range_view;

public:
    template <typename T = Tensor, TRREQUIRE(std::is_constructible<T>::value)>
    Locker() : Tensor() {}

    // We MUST define explicit copy and move constructors
    // to prevent EATING args by constructor with perfect forwarding
    template <typename T, typename... Tn,
              TRREQUIRE(not std::is_base_of<trixy::meta::decay<T>, Locker>::value and
                            std::is_constructible<Tensor, T, Tn...>::value)>
    explicit Locker(T&& t, Tn&&... tn)
        : Tensor(std::forward<T>(t), std::forward<Tn>(tn)...) {}

    // operator= for copy and move Locker object will not implicit generate
    Locker(const Locker& vector) : Tensor(vector) {}
    Locker(Locker&& vector) noexcept : Tensor(std::move(vector)) {}

    Locker(const Tensor& vector) : Tensor(vector) {}
    Locker(Tensor&& vector) noexcept : Tensor(std::move(vector)) {}

    ~Locker() = default;

    const Tensor& base() const noexcept
    { return static_cast<const Tensor&>(*this); }

public:
    using require::operator();
    using require::operator range_view;

    using require::copy;

    using require::size;
    using require::shape;

    using require::fill;
    using require::apply;

    using require::add;
    using require::sub;
    using require::mul;
    using require::join;

    using require::data;
};

} // namespace memory

} // namespace trixy

namespace trixy
{

namespace memory
{

template <class Tensor>
using MatrixLocker = Locker<Tensor, LockerType::matrix>;

template <class Tensor>
class Locker<Tensor, LockerType::matrix> : protected Tensor
{
    SERIALIZATION_ACCESS()

protected:
    using require = Tensor;

public:
    using typename require::size_type;
    using typename require::precision_type;
    using typename require::value_type;

    using typename require::pointer;
    using typename require::const_pointer;

    using typename require::range_view;

public:
    template <typename T = Tensor, TRREQUIRE(std::is_constructible<T>::value)>
    Locker() : Tensor() {}

    // We MUST define explicit copy and move constructors
    // to prevent EATING args by constructor with perfect forwarding
    template <typename T, typename... Tn,
              TRREQUIRE(not std::is_base_of<trixy::meta::decay<T>, Locker>::value and
                            std::is_constructible<Tensor, T, Tn...>::value)>
    explicit Locker(T&& t, Tn&&... tn)
        : Tensor(std::forward<T>(t), std::forward<Tn>(tn)...) {}

    // operator= for copy and move Locker object will not implicit generate
    Locker(const Locker& matrix) : Tensor(matrix) {}
    Locker(Locker&& matrix) noexcept : Tensor(std::move(matrix)) {}

    Locker(const Tensor& matrix) : Tensor(matrix) {}
    Locker(Tensor&& matrix) noexcept : Tensor(std::move(matrix)) {}

    ~Locker() = default;

    const Tensor& base() const noexcept
    { return static_cast<const Tensor&>(*this); }

public:
    using require::operator();
    using require::operator range_view;

    using require::copy;

    using require::size;
    using require::shape;

    using require::fill;
    using require::apply;

    using require::add;
    using require::sub;
    using require::mul;
    using require::join;

    using require::data;
};

} // namespace memory

} // namespace trixy

namespace trixy
{

namespace memory
{

template <class Tensor>
using TensorLocker = Locker<Tensor, LockerType::tensor>;

template <class Tensor>
class Locker<Tensor, LockerType::tensor> : protected Tensor
{
    SERIALIZATION_ACCESS()

protected:
    using require = Tensor;

public:
    using typename require::size_type;
    using typename require::precision_type;
    using typename require::value_type;

    using typename require::pointer;
    using typename require::const_pointer;

    using typename require::range_view;
    //using typename require::Shape; // deprecated

public:
    template <typename T = Tensor, TRREQUIRE(std::is_constructible<T>::value)>
    Locker() : Tensor() {}

    // We MUST define explicit copy and move constructors
    // to prevent EATING args by constructor with perfect forwarding
    template <typename T, typename... Tn,
              TRREQUIRE(not std::is_base_of<trixy::meta::decay<T>, Locker>::value and
                            std::is_constructible<Tensor, T, Tn...>::value)>
    explicit Locker(T&& t, Tn&&... tn)
        : Tensor(std::forward<T>(t), std::forward<Tn>(tn)...) {}

    // operator= for copy and move Locker object will not implicit generate
    Locker(const Locker& tensor) : Tensor(tensor) {}
    Locker(Locker&& tensor) noexcept : Tensor(std::move(tensor)) {}

    Locker(const Tensor& tensor) : Tensor(tensor) {}
    Locker(Tensor&& tensor) noexcept : Tensor(std::move(tensor)) {}

    ~Locker() = default;

    const Tensor& base() const noexcept
    { return static_cast<const Tensor&>(*this); }

public:
    using require::operator();
    using require::operator range_view;

    using require::copy;

    using require::size;
    using require::shape;

    using require::fill;
    using require::apply;

    using require::add;
    using require::sub;
    using require::mul;
    using require::join;

    using require::data;
};

} // namespace memory

} // namespace trixy

namespace trixy
{

namespace memory
{

template <class Container>
using ContainerLocker = Locker<Container, LockerType::container>;

template <class Container>
class Locker<Container, LockerType::container> : protected Container
{
    SERIALIZATION_ACCESS()

protected:
    using require = Container;

public:
    using typename require::size_type;
    using typename require::value_type;

    using typename require::reference;
    using typename require::const_reference;

public:
    template <typename T = Container, TRREQUIRE(std::is_constructible<T>::value)>
    Locker() : Container() {}

    // We MUST define explicit copy and move constructors
    // to prevent EATING args by constructor with perfect forwarding
    template <typename T, typename... Tn,
              TRREQUIRE(not std::is_base_of<trixy::meta::decay<T>, Locker>::value and
                            std::is_constructible<Container, T, Tn...>::value)>
    explicit Locker(T&& t, Tn&&... tn)
        : Container(std::forward<T>(t), std::forward<Tn>(tn)...) {}

    // operator= for copy and move Locker object will not implicit generate
    Locker(const Locker& container) : Container(container) {}
    Locker(Locker&& container) noexcept : Container(std::move(container)) {}

    Locker(const Container& container) : Container(container) {}
    Locker(Container&& container) noexcept : Container(std::move(container)) {}

    Locker(std::initializer_list<value_type> list) : Container(list) {}

    ~Locker() = default;

    const Container& base() const noexcept
    { return static_cast<const Container&>(*this); }

public:
    using require::size;
    using require::max_size;

    using require::empty;

    using require::begin;
    using require::end;
    using require::cbegin;
    using require::cend;

    using require::front;
    using require::back;

    using require::data;

    using require::operator[];
};

} // namespace memory

} // namespace trixy

// This file contains all extern meta function
// For safer use, you MUST only include the Base*.hpp file from lib

namespace trixy
{

template <typename TypeSet, typename RegressionType = RegressionType::Polynomial>
class Regression;

namespace guard
{

template <typename TypeSet, typename RegressionType = RegressionType::Polynomial>
struct RegressionRequire;

} // namespace guard

} // namespace trixy

namespace trixy
{

template <class Functionable, typename enable = void>
class Functional;

} // namespace trixy

namespace trixy
{

namespace train
{

template <class Trainable, typename enable = void>
class Training;

} // namespace train

} // namespace trixy

namespace trixy
{

template <class Serializable>
class Serializer;

} // namespace trixy

namespace trixy
{

namespace meta
{

template <typename> struct is_trixy_net : std::false_type {};
template <typename TrixyNetType, typename TypeSet>
struct is_trixy_net<TrixyNet<TypeSet, TrixyNetType>> : std::true_type {};

template <typename> struct is_unified_net : std::false_type {};
template <typename TypeSet>
struct is_unified_net<TrixyNet<TypeSet, TrixyNetType::Unified>> : std::true_type {};

template <typename> struct is_regression : std::false_type {};
template <typename RegressionType, typename TypeSet>
struct is_regression<Regression<TypeSet, RegressionType>> : std::true_type {};

template <typename> struct is_linear_regression : std::false_type {};
template <typename TypeSet>
struct is_linear_regression<Regression<TypeSet, RegressionType::Linear>> : std::true_type {};

template <typename> struct is_polynomial_regression : std::false_type {};
template <typename TypeSet>
struct is_polynomial_regression<Regression<TypeSet, RegressionType::Polynomial>> : std::true_type {};

template <typename> struct is_optimizer : std::false_type {};
template <class Optimizeriable,
          class OptimizationType>
struct is_optimizer<train::Optimizer<Optimizeriable, OptimizationType>> : std::true_type {};

template <typename> struct is_serializer : std::false_type {};
template <class Serializable>
struct is_serializer<Serializer<Serializable>> : std::true_type {};

template <typename> struct is_functional : std::false_type {};
template <class Functionable>
struct is_functional<Functional<Functionable>> : std::true_type {};

template <typename> struct is_training : std::false_type {};
template <class Trainable>
struct is_training<train::Training<Trainable>> : std::true_type {};

} // namespace meta

} // namespace trixy

namespace trixy
{

TRIXY_NET_TEMPLATE()
using UnifiedNed = TrixyNet<TypeSet>;

TRIXY_NET_TEMPLATE()
class TrixyNet<TypeSet>
    : public guard::TrixyNetRequire<TypeSet>::type
{
    SERIALIZATION_ACCESS()

public:
    template <typename T>
    using Container                 = typename TypeSet::template Container<T>;

    using Vector                    = typename TypeSet::Vector;
    using Matrix                    = typename TypeSet::Matrix;
    using Tensor                    = typename TypeSet::Tensor;

    template <typename T>
    using XContainer                = memory::ContainerLocker<Container<T>>;

    using XVector                   = memory::VectorLocker<Vector>;
    using XMatrix                   = memory::MatrixLocker<Matrix>;
    using XTensor                   = memory::TensorLocker<Tensor>;

    using precision_type            = typename TypeSet::precision_type;
    using size_type                 = typename TypeSet::size_type;

    using Linear                    = typename TypeSet::Linear;

    using ILayer                    = layer::ILayer<TrixyNet>;
    using ITrainLayer               = layer::ITrainLayer<TrixyNet>;

    using Topology                  = Container<ILayer*>;

private:
    Topology inner_;

public:
    Linear linear;

public:
    TrixyNet(size_type reserve_size = 8);
    TrixyNet(const Topology& topology);
    ~TrixyNet();

    TrixyNet& add(ILayer* layer);
    bool remove(ILayer* layer);

    const Topology& inner() const noexcept { return inner_; }
    ILayer& layer(size_type i) noexcept { return *inner_[i]; }

    size_type size() const noexcept { return inner_.size(); }

    const Tensor& feedforward(const Tensor& sample) noexcept;
    const Tensor& operator() (const Tensor& sample) noexcept;

    template <class FloatGenerator>
    void init(FloatGenerator generator) noexcept;
};

TRIXY_NET_TEMPLATE()
TrixyNet<TypeSet>::TrixyNet(size_type reserve_size)
{
    inner_.reserve(reserve_size);
}

TRIXY_NET_TEMPLATE()
TrixyNet<TypeSet>::TrixyNet(const Topology& topology)
{
    inner_ = topology;
}

TRIXY_NET_TEMPLATE()
TrixyNet<TypeSet>::~TrixyNet()
{
    for (size_type i = 0; i < inner_.size(); ++i)
        delete inner_[i];
}

TRIXY_NET_TEMPLATE()
auto TrixyNet<TypeSet>::add(ILayer* layer) -> TrixyNet&
{
    inner_.emplace_back(layer);
    return *this;
}

TRIXY_NET_TEMPLATE()
bool TrixyNet<TypeSet>::remove(ILayer* layer)
{
    Topology inner;
    inner.reserve(inner_.capacity());

    for (auto ilayer : inner_)
        if (ilayer != layer) inner.emplace_back(ilayer);

    inner_ = std::move(inner);

    return *this;
}

TRIXY_NET_TEMPLATE()
auto TrixyNet<TypeSet>::feedforward(
    const Tensor& sample) noexcept -> const Tensor&
{
    layer(0).forward(sample);

    for (size_type i = 1; i < inner_.size(); ++i)
        layer(i).forward(layer(i - 1).value());

    return layer(inner_.size() - 1).value();
}

TRIXY_NET_TEMPLATE()
auto TrixyNet<TypeSet>::operator() (
    const Tensor& sample) noexcept -> const Tensor&
{
    return feedforward(sample);
}

TRIXY_NET_TEMPLATE()
template <class TopologyGenerator>
void TrixyNet<TypeSet>::init(
    TopologyGenerator functor) noexcept
{
    typename ILayer::Generator generator{functor};

    for (size_type i = 0; i < inner_.size(); ++i)
        layer(i).init(generator);
}

} // namespace trixy

CONDITIONAL_SERIALIZATION(SaveLoad, trixy::meta::is_unified_net<T>::value)
{
    archive & self.inner_;
}

namespace trixy
{

namespace guard
{

TRIXY_REGRESSION_TEMPLATE()
struct RegressionRequire<TypeSet, RegressionType::Linear>
{
public:
    using type = RegressionType::Linear;

protected:
    using precision_type    = typename TypeSet::precision_type;

    using Vector            = typename TypeSet::Vector;
    using Matrix            = typename TypeSet::Matrix;

    using Linear            = typename TypeSet::Linear;

protected:
    using require_precision = typename PrecisionRequire<precision_type>::type;

    using require_vector    = typename VectorRequire<Vector>::type;
    using require_matrix    = typename MatrixRequire<Matrix>::type;

    using require_linear    = typename LinearRequire<Linear>::type;
};

TRIXY_REGRESSION_TEMPLATE()
struct RegressionRequire<TypeSet>
{
public:
    using type = RegressionType::Polynomial;

protected:
    using precision_type    = typename TypeSet::precision_type;

    using Vector            = typename TypeSet::Vector;
    using Matrix            = typename TypeSet::Matrix;

    using Linear            = typename TypeSet::Linear;

protected:
    using require_precision = typename PrecisionRequire<precision_type>::type;

    using require_vector    = typename VectorRequire<Vector>::type;
    using require_matrix    = typename MatrixRequire<Matrix>::type;

    using require_linear    = typename LinearRequire<Linear>::type;
};

} // namespace guard

} // namespace trixy

namespace trixy
{

TRIXY_REGRESSION_TEMPLATE()
using LinearRegression = Regression<TypeSet, RegressionType::Linear>;

TRIXY_REGRESSION_TEMPLATE()
class Regression<TypeSet, RegressionType::Linear> :
    public guard::RegressionRequire<TypeSet, RegressionType::Linear>::type
{
    SERIALIZATION_ACCESS()

friend train::Training<LinearRegression<TypeSet>>;

public:
    using Vector          = typename TypeSet::Vector;
    using Matrix          = typename TypeSet::Matrix;

    using Linear          = typename TypeSet::Linear;

    using precision_type  = typename TypeSet::precision_type;
    using size_type       = typename TypeSet::size_type;

private:
    Vector W;             ///< Inner weight
    size_type N;          ///< Size of weight vector (same as sample size + 1)

    Linear linear;

public:
    explicit Regression(size_type sample_size = 0);

    void init(Vector weight) noexcept;

    void reset(size_type new_sample_size);

    precision_type feedforward_sample(const Vector& sample) const;
    Vector feedforward(const Matrix& idata) const;

    Vector operator() (const Matrix& idata) const
    { return feedforward(idata); }

    const Vector& weight() const noexcept { return W; }
    size_type size() const noexcept { return N - 1; }
};

TRIXY_REGRESSION_TEMPLATE()
LinearRegression<TypeSet>::Regression(size_type sample_size)
    : W(sample_size + 1), N(sample_size + 1)
{
}

TRIXY_REGRESSION_TEMPLATE()
void LinearRegression<TypeSet>::init(Vector weight) noexcept
{
    W.copy(weight);
}

TRIXY_REGRESSION_TEMPLATE()
void LinearRegression<TypeSet>::reset(size_type new_sample_size)
{
    N = new_sample_size + 1;
    W.resize(N);
}

TRIXY_REGRESSION_TEMPLATE()
auto LinearRegression<TypeSet>::feedforward_sample(
    const Vector& sample) const -> precision_type
{
    precision_type result = W(0);

    for (size_type i = 1; i < N; ++i)
    {
        result += sample(i - 1) * W(i);
    }

    return result;
}

TRIXY_REGRESSION_TEMPLATE()
auto LinearRegression<TypeSet>::feedforward(
    const Matrix& idata) const -> Vector
{
    Matrix X(idata.shape().height, N);

    for (size_type i = 0; i < X.shape().height; ++i)
    {
        X(i, 0) = 1.;
        for (size_type j = 1; j < N; ++j)
            X(i, j) = idata(i, j - 1);
    }

    return linear.dot(X, W);
}

} // namespace trixy

CONDITIONAL_SERIALIZATION(SaveLoad, trixy::meta::is_linear_regression<T>::value)
{
    archive & self.W & self.N;
}

namespace trixy
{

TRIXY_REGRESSION_TEMPLATE()
using PolynomialRegression = Regression<TypeSet>;

TRIXY_REGRESSION_TEMPLATE()
class Regression<TypeSet> :
    public guard::RegressionRequire<TypeSet>::type
{
    SERIALIZATION_ACCESS()

friend train::Training<PolynomialRegression<TypeSet>>;

public:
    using Vector          = typename TypeSet::Vector;
    using Matrix          = typename TypeSet::Matrix;

    using Linear          = typename TypeSet::Linear;

    using precision_type  = typename TypeSet::precision_type;
    using size_type       = typename TypeSet::size_type;

private:
    Vector W;             ///< Inner weight
    size_type N;          ///< Size of weight vector (same as power size + 1)

    Linear linear;

public:
    explicit Regression(size_type power = 0);

    void init(Vector weight) noexcept;

    void reset(size_type new_power);

    precision_type feedforward(precision_type sample) const noexcept;
    Vector feedforward(const Vector& idata) const;

    Vector operator() (const Vector& idata) const
    { return feedforward(idata); }

    const Vector& weight() const noexcept { return W; }
    size_type power() const noexcept { return N - 1; }
};

TRIXY_REGRESSION_TEMPLATE()
Regression<TypeSet>::Regression(size_type power)
    : W(power + 1), N(power + 1)
{
}

TRIXY_REGRESSION_TEMPLATE()
void Regression<TypeSet>::init(
    Vector weight) noexcept
{
    W.copy(weight);
}

TRIXY_REGRESSION_TEMPLATE()
void Regression<TypeSet>::reset(
    size_type new_power)
{
    N = new_power + 1;
    W.resize(N);
}

TRIXY_REGRESSION_TEMPLATE()
auto Regression<TypeSet>::feedforward(
    precision_type sample) const noexcept -> precision_type
{
    precision_type result = W(0);
    precision_type power  = 1.;

    for (size_type i = 1; i < N; ++i)
    {
        power  *= sample;
        result += power * W(i);
    }

    return result;
}

TRIXY_REGRESSION_TEMPLATE()
auto Regression<TypeSet>::feedforward(
    const Vector& idata) const -> Vector
{
    Matrix X(idata.size(), N);

    precision_type sample;
    precision_type power;

    for (size_type i = 0; i < idata.size(); ++i)
    {
        sample  = idata(i);
        power   = 1.;

        X(i, 0) = 1.;
        for (size_type j = 1; j < N; ++j)
        {
            power  *= sample;
            X(i, j) = power;
        }
    }

    return linear.dot(X, W);
}

} // namespace trixy

CONDITIONAL_SERIALIZATION(SaveLoad, trixy::meta::is_polynomial_regression<T>::value)
{
    archive & self.W & self.N;
}

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

namespace trixy
{

namespace functional
{

namespace activation
{

// inline namespace for generation code
inline namespace detail
{

TRIXY_FUNCTION_TEMPLATE() inline Precision identity(Precision x) noexcept
{
    return x;
}

TRIXY_FUNCTION_TEMPLATE() inline Precision identity_derived(Precision x) noexcept
{
    return 1.;
}

TRIXY_FUNCTION_TEMPLATE() inline Precision relu(Precision x) noexcept
{
    return x > 0. ? x : 0.;
}

TRIXY_FUNCTION_TEMPLATE() inline Precision relu_derived(Precision x) noexcept
{
    return x > 0. ? 1. : 0.;
}

TRIXY_FUNCTION_TEMPLATE() Precision elu(Precision x) noexcept
{
    constexpr Precision alpha = 0.2;
    return x > 0. ? x : alpha * std::expm1(x);
}

TRIXY_FUNCTION_TEMPLATE() Precision elu_derived(Precision x) noexcept
{
    constexpr Precision alpha = 0.2;
    return x > 0. ? 1. : alpha * std::exp(x);
}

TRIXY_FUNCTION_TEMPLATE() inline Precision lrelu(Precision x) noexcept
{
    constexpr Precision alpha = 0.01;
    return x > 0. ? x : alpha * x;
}

TRIXY_FUNCTION_TEMPLATE() inline Precision lrelu_derived(Precision x) noexcept
{
    constexpr Precision alpha = 0.01;
    return x > 0. ? 1. : alpha;
}

TRIXY_FUNCTION_TEMPLATE() Precision selu(Precision x) noexcept
{
    constexpr Precision lambda = 1.050701;
    constexpr Precision beta   = 1.758099;

    return x > 0. ? lambda * x : beta * std::expm1(x);
}

TRIXY_FUNCTION_TEMPLATE() Precision selu_derived(Precision x) noexcept
{
    constexpr Precision lambda = 1.050701;
    constexpr Precision beta   = 1.758099;

    return x > 0. ? lambda : beta * std::exp(x);
}

TRIXY_FUNCTION_TEMPLATE() Precision gelu(Precision x) noexcept
{
    constexpr Precision a = 0.797885;
    constexpr Precision b = 0.0356774;

    return 0.5 * x * (std::tanh(x * a + x * x * x * b) + 1.);
}

TRIXY_FUNCTION_TEMPLATE() Precision gelu_derived(Precision x) noexcept
{
    constexpr Precision a = 0.797885;
    constexpr Precision b = 0.0356774;
    constexpr Precision c = 0.0535161;
    constexpr Precision d = 0.398942;

    Precision x3 = x * x * x;
    Precision y = a * x3 + b * x;
    Precision sch = 1. / std::cosh(y);

    return 0.5 * std::tanh(y) + (c * x3 + d * x) * sch * sch + 0.5;
}

TRIXY_FUNCTION_TEMPLATE() Precision sigmoid(Precision x) noexcept
{
    return 1. / (std::exp(-x) + 1.);
}

TRIXY_FUNCTION_TEMPLATE() Precision sigmoid_derived(Precision x) noexcept
{
    return 0.5 / (std::cosh(x) + 1.);
}

TRIXY_FUNCTION_TEMPLATE() inline Precision sigmoid_derived_self(Precision x) noexcept
{
    return x * (1 - x);
}

TRIXY_FUNCTION_TEMPLATE() Precision tanh(Precision x) noexcept
{
    return std::tanh(x);
}

TRIXY_FUNCTION_TEMPLATE() Precision tanh_derived(Precision x) noexcept
{
    Precision sech = 1. / std::cosh(x);
    return sech * sech;
}

TRIXY_FUNCTION_TEMPLATE() Precision softsign(Precision x) noexcept
{
    return x / (std::fabs(x) + 1.);
}

TRIXY_FUNCTION_TEMPLATE() Precision softsign_derived(Precision x) noexcept
{
    Precision f = 1. / (std::fabs(x) + 1.);
    return f * f;
}

TRIXY_FUNCTION_TEMPLATE() Precision softplus(Precision x) noexcept
{
    return std::log(std::exp(x) + 1.);
}

TRIXY_FUNCTION_TEMPLATE() Precision softplus_derived(Precision x) noexcept
{
    return 1. / (std::exp(-x) + 1.);
}

TRIXY_FUNCTION_TEMPLATE() Precision swish(Precision x) noexcept
{
    return x / (std::exp(-x) + 1.);
}

TRIXY_FUNCTION_TEMPLATE() Precision swish_derived(Precision x) noexcept
{
    Precision a = std::exp(-x);
    Precision b = a + 1.;
    return (a * x + b) / (b * b);
}

TRIXY_FUNCTION_TEMPLATE() inline Precision mod_relu(Precision x) noexcept
{
    if      (x < 0.) return 0.01 * x;
    else if (x > 1.) return 0.99 + 0.01 * x;
    else             return x;
}
TRIXY_FUNCTION_TEMPLATE() inline Precision mod_relu_derived(Precision x) noexcept
{
    return (x < 0. or x > 1.) ? 0.01 : 1.;
}

TRIXY_FUNCTION_TEMPLATE() Precision mod_tanh(Precision x) noexcept
{
    return x < 0. ? 0.01 * std::tanh(x) : std::tanh(x);
}

TRIXY_FUNCTION_TEMPLATE() Precision mod_tanh_derived(Precision x) noexcept
{
    Precision sech2 = 1. / std::cosh(x);
    sech2 *= sech2;
    return x < 0. ? 0.01 * sech2 : sech2;
}

} // inline namespace detail

} // namespace activation

} // namespace functional

} // namespace trixy

// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define TRIXY_APPLY_FUNCTION_GENERIC_HELPER(name)                                                       \
    template <class InRange, class OutRange>                                                            \
    void name(InRange& result, const OutRange& input) noexcept {                                        \
        auto it = input.data();                                                                         \
        auto first = result.data();                                                                     \
        auto last = result.data() + result.size();                                                      \
        while (first != last) *first++ = name(*it++);                                                   \
    }

#define TRIXY_FUNCTION_GENERIC_HELPER(name)                                                             \
    TRIXY_APPLY_FUNCTION_GENERIC_HELPER(name)                                                           \
    TRIXY_APPLY_FUNCTION_GENERIC_HELPER(name##_derived)

#define TRIXY_FUNCTION_GENERIC_LOSS_HELPER(name, function_name, derived_function_name)                  \
    template <typename Precision = double>                                                              \
    class name : public ILoss<Precision> {                                                              \
        SERIALIZABLE(name)                                                                              \
    public:                                                                                             \
        using Base = ILoss<Precision>;                                                                  \
                                                                                                        \
        using typename Base::precision_type;                                                            \
        using typename Base::Range;                                                                     \
                                                                                                        \
        name() : Base() {}                                                                              \
                                                                                                        \
        void f(precision_type& result, const Range y_true, const Range y_pred) noexcept                 \
        { function_name(result, y_true, y_pred); }                                                      \
                                                                                                        \
        void df(Range result, const Range y_true, const Range y_pred) noexcept                          \
        { derived_function_name(result, y_true, y_pred); }                                              \
                                                                                                        \
        void operator() (precision_type& result, const Range y_true, const Range y_pred) noexcept       \
        { function_name(result, y_true, y_pred); }                                                      \
    }

#define TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(name, function_name, derived_function_name)            \
    template <typename Precision = double>                                                              \
    class name : public IActivation<Precision> {                                                        \
        SERIALIZABLE(name)                                                                              \
    public:                                                                                             \
        using Base = IActivation<Precision>;                                                            \
                                                                                                        \
        using typename Base::precision_type;                                                            \
        using typename Base::Range;                                                                     \
                                                                                                        \
        name() : Base() {}                                                                              \
                                                                                                        \
        void f(Range result, const Range input) noexcept { function_name(result, input); }              \
        void df(Range result, const Range input) noexcept { derived_function_name(result, input); }     \
                                                                                                        \
        void operator() (Range result, const Range input) noexcept { function_name(result, input); }    \
    }

namespace trixy
{

namespace functional
{

namespace activation
{

TRIXY_FUNCTION_GENERIC_HELPER(identity)

TRIXY_FUNCTION_GENERIC_HELPER(relu)
TRIXY_FUNCTION_GENERIC_HELPER(elu)
TRIXY_FUNCTION_GENERIC_HELPER(lrelu)
TRIXY_FUNCTION_GENERIC_HELPER(selu)
TRIXY_FUNCTION_GENERIC_HELPER(gelu)

TRIXY_FUNCTION_GENERIC_HELPER(sigmoid)
TRIXY_FUNCTION_GENERIC_HELPER(tanh)

TRIXY_FUNCTION_GENERIC_HELPER(softsign)
TRIXY_FUNCTION_GENERIC_HELPER(softplus)
TRIXY_FUNCTION_GENERIC_HELPER(swish)

TRIXY_FUNCTION_GENERIC_HELPER(mod_relu)
TRIXY_FUNCTION_GENERIC_HELPER(mod_tanh)

template <class OutRange, class InRange>
void unstable_softmax(OutRange& result, const InRange& input) noexcept
{
    using precision_type = typename OutRange::value_type;

    auto first = result.data();
    auto last  = result.data() + result.size();

    auto it = input.data();

    while (first != last) *first++ = std::exp(*it++);

    precision_type denominator = 0.;

    first = result.data();
    last  = result.data() + result.size();

    while (first != last)
    {
        denominator += *first;
        ++first;
    }

    denominator = 1. / denominator;

    first = result.data();
    last  = result.data() + result.size();

    while (first != last)
    {
        *first *= denominator;
        ++first;
    }
}

template <class OutRange, class InRange>
void softmax(OutRange& result, const InRange& input) noexcept
{
    using precision_type = typename OutRange::value_type;

    precision_type max;
    {
        auto first = input.data();
        auto last  = input.data() + input.size();

        max = *first++; // assign of curr value and increment of it

        while (first != last)
        {
            if (max < *first) max = *first;

            ++first;
        }
    }

    auto first = result.data();
    auto last  = result.data() + result.size();

    auto it = input.data();

    while (first != last)
    {
        *first = std::exp(*it - max);
        ++first;
        ++it;
    }

    first = result.data();
    last  = result.data() + result.size();

    precision_type denominator = 0.;

    while (first != last)
    {
        denominator += *first;
        ++first;
    }

    denominator = 1. / denominator;

    first = result.data();
    last  = result.data() + result.size();

    while (first != last)
    {
        *first *= denominator;
        ++first;
    }
}

template <class Range1, class Range2>
void softmax_derived(Range1& result, const Range2& input) noexcept
{
    auto first = result.data();
    auto last  = result.data() + result.size();

    auto it = input.data();

    while (first != last) *first++ = 1.;
}

TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(Identity, identity, identity_derived);

TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(ReLU, relu, relu_derived);
TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(ELU, elu, elu_derived);

TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(LReLU, lrelu, lrelu_derived);
TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(SELU, selu, selu_derived);
TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(GELU, gelu, gelu_derived);

TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(Sigmoid, sigmoid, sigmoid_derived);
TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(Tanh, tanh, tanh_derived);

TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(SoftSign, softsign, softsign_derived);
TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(SoftPlus, softplus, softplus_derived);
TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(Swish, swish, swish_derived);

TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(ModRelu, mod_relu, mod_relu_derived);
TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(ModTanh, mod_tanh, mod_tanh_derived);

TRIXY_FUNCTION_GENERIC_ACTIVATION_HELPER(SoftMax, softmax, softmax_derived);

} // namespace activation

} // namespace functional

} // namespace trixy

// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define TRIXY_LAYER_BODY(...)                                                                           \
    public:                                                                                             \
        using Base = __VA_ARGS__;                                                                       \
        using typename Base::IOptimizer;                                                                \
    public:                                                                                             \
        template <typename T>                                                                           \
        using Container = typename Base::template Container<T>;                                         \
                                                                                                        \
        using typename Base::Vector;                                                                    \
        using typename Base::Matrix;                                                                    \
        using typename Base::Tensor;                                                                    \
                                                                                                        \
        using typename Base::XVector;                                                                   \
        using typename Base::XMatrix;                                                                   \
        using typename Base::XTensor;                                                                   \
                                                                                                        \
        using typename Base::Linear;                                                                    \
                                                                                                        \
        using typename Base::size_type;                                                                 \
        using typename Base::precision_type;                                                            \
        using typename Base::shape_type;                                                                \
                                                                                                        \
        using typename Base::Generator;                                                                 \
        using typename Base::IActivation;                                                               \
                                                                                                        \
    public:                                                                                             \
        using Identity = functional::activation::Identity<precision_type>;

namespace trixy
{

namespace layer
{

template <class Net,
          typename LayerMode = LayerMode::Train>
using FullyConnected = Layer<trixy::LayerType::FullyConnected, Net, LayerMode>;

template <class Net>
using XFullyConnected = FullyConnected<Net, LayerMode::Raw>;

template <class Net>
class Layer<trixy::LayerType::FullyConnected, Net, LayerMode::Raw>
    : public ILayer<Net>
{
    TRIXY_LAYER_BODY(ILayer<Net>)
    SERIALIZABLE(Layer<trixy::LayerType::FullyConnected, Net, LayerMode::Raw>)

protected:
    shape_type isize_;
    shape_type osize_;

    Vector B_;
    Matrix W_;

    IActivation* activation_;

protected:
    // cache
    Tensor value_;

public:
    Linear linear;

public:
    Layer() : activation_(nullptr) {}

    Layer(const set::Input& input, const set::Output& output, IActivation* activation = new Identity)
        : Layer(input.size, output.size, activation)
    {
    }

    Layer(size_type isize, size_type osize, IActivation* activation = new Identity)
        : Base()
        , isize_(1, 1, isize), osize_(1, 1, osize)
        , activation_(activation)
    {
        B_.resize(osize).fill(0.f);
        W_.resize(isize, osize).fll(0.f);

        prepare();
    }

protected:
    void prepare()
    {
        value_.resize(osize_).fill(0.f);
    }

public:
    virtual ~Layer() { delete activation_; }

    void connect(IActivation* activation) override
    {
        delete activation_;
        activation_ = activation;
    }

    void forward(const Tensor& input) noexcept override
    {
        // H - input
        // S - buff

        // S = H . W + B
        linear.dot(value_, input, W_);
        linear.add(value_, B_);

        // value = F(S)
        activation_->f(value_, value_);
    }

    const Tensor& value() const noexcept override { return value_; }

    const shape_type& isize() const noexcept override { return isize_; }
    const shape_type& osize() const noexcept override { return osize_; }
};

template <class Net>
class Layer<trixy::LayerType::FullyConnected, Net, LayerMode::Train>
    : public ITrainLayer<Net>
{
    TRIXY_LAYER_BODY(ITrainLayer<Net>)
    SERIALIZABLE(Layer<trixy::LayerType::FullyConnected, Net, LayerMode::Train>)

protected:
    shape_type isize_;
    shape_type osize_;

    Vector B_;
    Matrix W_;

    IActivation* activation_;

protected:
    // cache
    Tensor value_;
    Vector buff_;

    Vector gradB_;
    Matrix gradW_;

    Vector gradBs_;
    Matrix gradWs_;

    Tensor delta_;

    bool accumulated_;

public:
    Linear linear;

public:
    Layer() : activation_(nullptr) {}

    Layer(const set::Input& input, const set::Output& output, IActivation* activation = new Identity)
        : Layer(input.size, output.size, activation)
    {
    }

    // maybe change in the future release
    Layer(size_type isize, size_type osize, IActivation* activation = new Identity)
        : Base()
        , isize_(1, 1, isize), osize_(1, 1, osize)
        , activation_(activation)
    {
        B_.resize(osize).fill(0.f);
        W_.resize(isize, osize).fill(0.f);

        prepare();
    }

protected:
    void prepare()
    {
        value_.resize(osize_).fill(0.f);
        buff_.resize(osize_).fill(0.f);
        gradBs_.resize(osize_).fill(0.f);
        gradWs_.resize(isize_.width, osize_.width).fill(0.f);
        gradB_.resize(osize_).fill(0.f);
        gradW_.resize(isize_.width, osize_.width).fill(0.f);
        delta_.resize(isize_).fill(0.f);
        accumulated_ = false;
    }

public:
    virtual ~Layer() { delete activation_; }

    void init(Generator& generation) noexcept override
    {
        B_.fill(generation);
        W_.fill(generation);
    }

    void connect(IActivation* activation) override
    {
        delete activation_;
        activation_ = activation;
    }

    void forward(const Tensor& input) noexcept override
    {
        // H - input
        // S - buff

        // S = H . W + B

        linear.dot(buff_, input, W_);
        linear.add(buff_, B_);

        // value = F(S)
        activation_->f(value_, buff_);
    }

    void backward(const Tensor& input, const Tensor& idelta, bool full = true) noexcept override
    {
        // curr_delta  - gradB
        // input_delta - idelta
        // S - buff
        // curr_delta = input_delta * F'(S)

        activation_->df(gradB_, buff_);
        linear.mul(gradB_, idelta);

        // H - input
        // gradB - delta
        // gradW = H . delta, where . - tensordot
        linear.tensordot(gradW_, input, gradB_);

        // curr_delta - gradB
        // delta = curr_delta . W^T

        if (full) linear.dot(delta_, W_, gradB_);
    }

    void update(IOptimizer& optimizer, precision_type alpha) noexcept override
    {
        auto& gradB = accumulated_ ? gradBs_ : gradB_;
        auto& gradW = accumulated_ ? gradWs_ : gradW_;

        if (alpha != 1.f)
        {
            linear.join(gradB, alpha);
            linear.join(gradW, alpha);
        }

        optimizer.update(B_, gradB);
        optimizer.update(W_, gradW);
    }

    void reset() noexcept override
    {
        gradBs_.fill(0.f);
        gradWs_.fill(0.f);

        accumulated_ = false;
    }

    void accumulate() noexcept override
    {
        linear.add(gradBs_, gradB_);
        linear.add(gradWs_, gradW_);

        accumulated_ = true;
    }

    const Tensor& value() const noexcept override { return value_; }
    const Tensor& delta() const noexcept override { return delta_; }

    const shape_type& isize() const noexcept override { return isize_; }
    const shape_type& osize() const noexcept override { return osize_; }
};

} // namespace layer

namespace meta
{

template <typename T> struct is_fully_connected_layer : std::false_type {};
template <class Net, typename LayerMode>
struct is_fully_connected_layer<layer::Layer<LayerType::FullyConnected, Net, LayerMode>> : std::true_type {};

} // namespace meta

} // namespace trixy

CONDITIONAL_SERIALIZATION(SaveLoad, trixy::meta::is_fully_connected_layer<T>::value)
{
    archive & self.isize_ & self.osize_
            & self.B_ & self.W_
            & self.activation_;

    if (trixy::meta::is_iarchive(archive)) self.prepare();
}

namespace trixy
{

namespace layer
{
template <class Net,
          typename LayerMode = LayerMode::Train>
using Convolutional = Layer<trixy::LayerType::Convolutional, Net, LayerMode>;

template <class Net>
using XConvolutional = Convolutional<Net, LayerMode::Raw>;

template <class Net>
class Layer<trixy::LayerType::Convolutional, Net, LayerMode::Raw>
    : public ILayer<Net>
{
    TRIXY_LAYER_BODY(ILayer<Net>)
    SERIALIZABLE(Layer<trixy::LayerType::Convolutional, Net, LayerMode::Raw>)

protected:
    shape_type isize_;
    shape_type osize_;

    size_type padding_;

    size_type vertical_stride_;
    size_type horizontal_stride_;

    Vector B_;
    Container<Tensor> Ws_;

protected:
    // cache
    size_type filter_count_;
    shape_type filter_size_;

    Tensor value_;

public:
    Layer() {}

    Layer(const set::Input& input,
          const set::Filter& filter,
          const set::Padding& padding = set::Padding(0),
          const set::Stride& stride = set::Stride(1))
        : Layer(input,
                filter.depth, filter.height, filter.width,
                padding.height,
                stride.height, stride.width) {}

    Layer(shape_type size,
          size_type filter_count, size_type filter_height, size_type filter_width,
          size_type padding, size_type vertical_stride, size_type horizontal_stride)
        : Base()
        , isize_(size)
        , osize_(filter_count,
                 (size.height - filter_height + 2 * padding) / vertical_stride + 1,
                 (size.width - filter_width + 2 * padding) / horizontal_stride + 1)
        , padding_(padding)
        , vertical_stride_(vertical_stride)
        , horizontal_stride_(horizontal_stride)
    {
        B_.resize(filter_count).fill(0.f);

        Ws_.resize(filter_count);
        for (auto& W : Ws_) W.resize(size.depth, filter_height, filter_width).fill(0.f);

        prepare();
    }

protected:
    void prepare()
    {
        filter_count_ = Ws_.size();
        filter_size_ = Ws_.front().shape();

        value_.resize(osize_).fill(0.f);
    }

    void init(Generator& gen) noexcept override
    {
        for (auto& W : Ws_) W.fill(gen);
        B_.fill(gen);
    }

    void connect(IActivation* activation) override { /*pass*/ }

    void forward(const Tensor& input) noexcept override
    {
        for (size_type f = 0; f < filter_count_; ++f)
        {
            for (size_type y = 0; y < osize_.height; ++y)
            {
                for (size_type x = 0; x < osize_.width; ++x)
                {
                    precision_type sum = B_(f);

                    for (size_type i = 0; i < filter_size_.height; ++i)
                    {
                        for (size_type j = 0; j < filter_size_.width; ++j)
                        {
                            size_type i0 = vertical_stride_ * y + i - padding_;
                            size_type j0 = horizontal_stride_ * x + j - padding_;

                            // negative value will be bigger than bounds
                            if (i0 >= isize_.height || j0 >= isize_.width)
                                continue;

                            for (size_type c = 0; c < filter_size_.depth; ++c)
                                sum += input(c, i0, j0) * Ws_[f](c, i, j);
                        }
                    }

                    value_(f, y, x) = sum;
                }
            }
        }
    }

    const Tensor& value() const noexcept override { return value_; }

    const shape_type& isize() const noexcept override { return isize_; }
    const shape_type& osize() const noexcept override { return osize_; }
};

template <class Net>
class Layer<trixy::LayerType::Convolutional, Net, LayerMode::Train>
    : public ITrainLayer<Net>
{
    TRIXY_LAYER_BODY(ITrainLayer<Net>)
    SERIALIZABLE(Layer<trixy::LayerType::Convolutional, Net, LayerMode::Train>)

protected:
    shape_type isize_;
    shape_type osize_;

    size_type padding_;

    size_type vertical_stride_;
    size_type horizontal_stride_;

    Vector B_;
    Container<Tensor> Ws_;

protected:
    // cache
    size_type filter_count_;
    shape_type filter_size_;

    Tensor value_;

    Container<Tensor> gradWs_;
    Vector gradB_;

    Tensor delta_;
    Tensor buff_;

public:
    Linear linear;

public:
    Layer() {}

    Layer(const set::Input& input,
          const set::Filter& filter,
          const set::Padding& padding = set::Padding(0),
          const set::Stride& stride = set::Stride(1))
        : Layer(input,
                filter.depth, filter.height, filter.width,
                padding.height,
                stride.height, stride.width) {}

    Layer(shape_type size,
          size_type filter_count, size_type filter_height, size_type filter_width,
          size_type padding, size_type vertical_stride, size_type horizontal_stride)
        : Base()
        , isize_(size)
        , osize_(filter_count,
                 (size.height - filter_height + 2 * padding) / vertical_stride + 1,
                 (size.width - filter_width + 2 * padding) / horizontal_stride + 1)
        , padding_(padding)
        , vertical_stride_(vertical_stride)
        , horizontal_stride_(horizontal_stride)
    {
        B_.resize(filter_count).fill(0.f);

        Ws_.resize(filter_count);
        for (auto& W : Ws_) W.resize(size.depth, filter_height, filter_width).fill(0.f);

        prepare();
    }

protected:
    void prepare()
    {
        filter_count_ = Ws_.size();
        filter_size_ = Ws_.front().shape();

        value_.resize(osize_).fill(0.f);

        gradWs_.resize(filter_count_);
        for (auto& gradW : gradWs_) gradW.resize(filter_size_).fill(0.f);

        gradB_.resize(filter_count_).fill(0.f);

        delta_.resize(isize_).fill(0.f);

        auto buff_size = shape_type
        (
            osize_.depth,
            vertical_stride_ * (osize_.height - 1) + 1,
            horizontal_stride_ * (osize_.width - 1) + 1
        );

        buff_.resize(buff_size).fill(0.f);
    }

public:
    void init(Generator& generation) noexcept override
    {
        for (auto& W : Ws_) W.fill(generation);
        B_.fill(generation);
    }

    void connect(IActivation* activation) override { /*pass*/ }

    void forward(const Tensor& input) noexcept override
    {
        for (size_type f = 0; f < filter_count_; ++f)
        {
            for (size_type y = 0; y < osize_.height; ++y)
            {
                for (size_type x = 0; x < osize_.width; ++x)
                {
                    precision_type sum = B_(f);

                    for (size_type i = 0; i < filter_size_.height; ++i)
                    {
                        for (size_type j = 0; j < filter_size_.width; ++j)
                        {
                            size_type i0 = vertical_stride_ * y + i - padding_;
                            size_type j0 = horizontal_stride_ * x + j - padding_;

                            // negative value will be bigger than bounds
                            if (i0 >= isize_.height || j0 >= isize_.width)
                                continue;

                            for (size_type c = 0; c < filter_size_.depth; ++c)
                                sum += input(c, i0, j0) * Ws_[f](c, i, j);
                        }
                    }

                    value_(f, y, x) = sum;
                }
            }
        }
    }

    void backward(const Tensor& input, const Tensor& idelta, bool full = true/*unused*/) noexcept override
    {
        auto& size = buff_.shape();

        for (size_type d = 0; d < size.depth; d++)
            for (size_type i = 0; i < osize_.height; ++i)
                for (size_type j = 0; j < osize_.width; ++j)
                    buff_(d, i * vertical_stride_, j * horizontal_stride_) = idelta(d, i, j);

        for (size_type f = 0; f < filter_count_; ++f)
        {
            for (size_type y = 0; y < size.height; ++y)
            {
                for (size_type x = 0; x < size.width; ++x)
                {
                    precision_type delta_value = buff_(f, y, x);

                    for (size_type i = 0; i < filter_size_.height; ++i)
                    {
                        for (size_type j = 0; j < filter_size_.width; ++j)
                        {
                            size_type i0 = i + y - padding_;
                            size_type j0 = j + x - padding_;

                            if (i0 >= isize_.height || j0 >= isize_.width)
                                continue;

                            for (size_type c = 0; c < filter_size_.depth; ++c)
                                gradWs_[f](c, i, j) += delta_value * input(c, i0, j0);
                        }
                    }

                    gradB_(f) += delta_value;
                }
            }
        }

        size_type pad_i = filter_size_.height - 1 - padding_;
        size_type pad_j = filter_size_.width - 1 - padding_;

        for (size_type y = 0; y < isize_.height; ++y)
        {
            for (size_type x = 0; x < isize_.width; ++x)
            {
                for (size_type c = 0; c < filter_size_.depth; ++c)
                {
                    precision_type sum = 0;
                    for (size_type i = 0; i < filter_size_.height; ++i)
                    {
                        for (size_type j = 0; j < filter_size_.width; ++j)
                        {
                            size_type i0 = y + i - pad_i;
                            size_type j0 = x + j - pad_j;

                            if (i0 >= size.height || j0 >= size.width)
                                continue;

                            for (size_type f = 0; f < filter_count_; ++f)
                                sum += Ws_[f](c, filter_size_.height - 1 - i, filter_size_.width - 1 - j) * buff_(f, i0, j0);
                        }
                    }

                    delta_(c, y, x) = sum;
                }
            }
        }
    }

    void update(IOptimizer& optimizer, precision_type alpha) noexcept override
    {
        for (auto& gradW : gradWs_) linear.join(gradW, alpha);
        linear.join(gradB_, alpha);

        for (size_type i = 0; i < Ws_.size(); ++i) optimizer.update(Ws_[i], gradWs_[i]);
        optimizer.update(B_, gradB_);
    }

    const Tensor& value() const noexcept override { return value_; }
    const Tensor& delta() const noexcept override { return delta_; }

    const shape_type& isize() const noexcept override { return isize_; }
    const shape_type& osize() const noexcept override { return osize_; }
};

} // namespace layer

namespace meta
{

template <typename T> struct is_convolutional_layer : std::false_type {};
template <class Net, typename LayerMode>
struct is_convolutional_layer<layer::Layer<LayerType::Convolutional, Net, LayerMode>> : std::true_type {};

} // namespace meta

} // namespace trixy

CONDITIONAL_SERIALIZATION(SaveLoad, trixy::meta::is_convolutional_layer<T>::value)
{
    archive & self.isize_ & self.osize_
            & self.padding_
            & self.vertical_stride_ & self.horizontal_stride_
            & self.B_ & self.Ws_;

    if (trixy::meta::is_iarchive(archive)) self.prepare();
}

namespace trixy
{

namespace layer
{

template <class Net,
          typename LayerMode = LayerMode::Train>
using MaxPooling = Layer<trixy::LayerType::MaxPooling, Net, LayerMode>;

template <class Net>
using XMaxPooling = MaxPooling<Net, LayerMode::Raw>;

template <class Net>
class Layer<trixy::LayerType::MaxPooling, Net, LayerMode::Raw>
    : public ILayer<Net>
{
    TRIXY_LAYER_BODY(ILayer<Net>)
    SERIALIZABLE(Layer<trixy::LayerType::MaxPooling, Net, LayerMode::Raw>)

protected:
    shape_type isize_;
    shape_type osize_;

    size_type vertical_stride_;
    size_type horizontal_stride_;

    IActivation* activation_;

protected:
    // cache
    Tensor value_;

public:
    Linear linear;

public:
    Layer() : activation_(nullptr) {}

    Layer(const set::Input& input,
          const set::Stride& stride = set::Stride(1),
          IActivation* activation = new Identity)
        : Layer(input.depth, input.height, input.width,
                stride.height, stride.width,
                activation)
    {
    }

public:
    Layer(size_type channel_depth, size_type in_height, size_type in_width,
          size_type vertical_stride, size_type horizontal_stride,
          IActivation* activation = new Identity)
        : Base()
        , isize_(channel_depth, in_height, in_width)
        , osize_(channel_depth,
                 in_height / vertical_stride,
                 in_width / horizontal_stride)
        , vertical_stride_(vertical_stride)
        , horizontal_stride_(horizontal_stride)
        , activation_(activation)
    {
        value_.resize(osize_).fill(0.f);

        prepare();
    }

protected:
    void prepare() { /*pass*/ }

public:
    virtual ~Layer() { delete activation_; }

    void connect(IActivation* activation) override
    {
        delete activation_;
        activation_ = activation;
    }

    void forward(const Tensor& input) noexcept override
    {
        for (size_type d = 0; d < isize_.depth; ++d)
        {
            for (size_type i = 0; i < isize_.height; i += vertical_stride_)
            {
                for (size_type j = 0; j < isize_.width; j += horizontal_stride_)
                {
                    precision_type max = input(d, i, j);

                    for (size_type y = i; y < i + vertical_stride_; ++y)
                    {
                        for (size_type x = j; x < j + horizontal_stride_; ++x)
                        {
                            precision_type value = input(d, y, x);
                            if (value > max) max = value;
                        }
                    }

                    value_(d, i / vertical_stride_, j / horizontal_stride_) = max;
                }
            }
        }

        activation_->f(value_, value_);
    }

    const Tensor& value() const noexcept override { return value_; }

    const shape_type& isize() const noexcept override { return isize_; }
    const shape_type& osize() const noexcept override { return osize_; }
};

template <class Net>
class Layer<trixy::LayerType::MaxPooling, Net, LayerMode::Train>
    : public ITrainLayer<Net>
{
    TRIXY_LAYER_BODY(ITrainLayer<Net>)
    SERIALIZABLE(Layer<trixy::LayerType::MaxPooling, Net, LayerMode::Train>)

protected:

    shape_type isize_;
    shape_type osize_;

    size_type vertical_stride_;
    size_type horizontal_stride_;

    IActivation* activation_;

protected:
    // cache
    Tensor value_;
    Tensor buff_;
    Tensor mask_;

    Tensor delta_;

public:
    Linear linear;

public:
    Layer() : activation_(nullptr) {}

    Layer(const set::Input& input,
          const set::Stride& stride = set::Stride(1),
          IActivation* activation = new Identity)
        : Layer(input.depth, input.height, input.width,
                stride.height, stride.width,
                activation)
    {
    }

public:
    Layer(size_type channel_depth, size_type in_height, size_type in_width,
          size_type vertical_stride, size_type horizontal_stride,
          IActivation* activation = new Identity)
        : Base()
        , isize_(channel_depth, in_height, in_width)
        , osize_(channel_depth,
                 in_height / vertical_stride,
                 in_width / horizontal_stride)
        , vertical_stride_(vertical_stride)
        , horizontal_stride_(horizontal_stride)
        , activation_(activation)
    {
        value_.resize(osize_).fill(0.f);

        prepare();
    }

protected:
    void prepare()
    {
        delta_.resize(isize_).fill(0.f);
        mask_.resize(isize_).fill(0.f);
        buff_.resize(osize_).fill(0.f);
    }

public:
    virtual ~Layer() { delete activation_; }

    void connect(IActivation* activation) override
    {
        delete activation_;
        activation_ = activation;
    }

    void init(Generator&) noexcept override { /*pass*/ }

    void forward(const Tensor& input) noexcept override
    {
        mask_.fill(0.f);

        for (size_type d = 0; d < isize_.depth; ++d)
        {
            for (size_type i = 0; i < isize_.height; i += vertical_stride_)
            {
                for (size_type j = 0; j < isize_.width; j += horizontal_stride_)
                {
                    size_type imax = i;
                    size_type jmax = j;

                    precision_type max = input(d, i, j);

                    for (size_type y = i; y < i + vertical_stride_; ++y)
                    {
                        for (size_type x = j; x < j + horizontal_stride_; ++x)
                        {
                            precision_type value = input(d, y, x);
                            mask_(d, y, x) = 0.f;

                            if (value > max)
                            {
                                max = value;
                                imax = y;
                                jmax = x;
                            }
                        }
                    }

                    value_(d, i / vertical_stride_, j / horizontal_stride_) = max;
                    mask_(d, imax, jmax) = 1.f;
                }
            }
        }

        activation_->f(value_, buff_);
    }

    void backward(const Tensor& /*input*/, const Tensor& idelta, bool full = true/*unused*/) noexcept override
    {
        activation_->df(buff_, buff_);
        linear.mul(buff_, idelta);

        for (size_type d = 0; d < isize_.depth; ++d)
            for (size_type i = 0; i < isize_.height; ++i)
                for (size_type j = 0; j < isize_.width; ++j)
                    delta_(d, i, j) = buff_(d, i / vertical_stride_, j / horizontal_stride_) * mask_(d, i, j);
    }

    const Tensor& value() const noexcept override { return value_; }
    const Tensor& delta() const noexcept override { return delta_; }

    const shape_type& isize() const noexcept override { return isize_; }
    const shape_type& osize() const noexcept override { return osize_; }
};

} // namespace layer

namespace meta
{

template <typename T> struct is_max_polling_layer : std::false_type {};
template <class Net, typename LayerMode>
struct is_max_polling_layer<layer::Layer<LayerType::MaxPooling, Net, LayerMode>> : std::true_type {};

} // namespace meta

} // namespace trixy

CONDITIONAL_SERIALIZATION(SaveLoad, trixy::meta::is_max_polling_layer<T>::value)
{
    archive & self.isize_ & self.osize_
            & self.vertical_stride_ & self.horizontal_stride_
            & self.activation_;

    if (trixy::meta::is_iarchive(archive)) self.prepare();
}

namespace trixy
{

namespace train
{

TRIXY_TRAINING_TEMPLATE()
using UnifiedNetTraining
    = Training<Trainable, TRWITH(Trainable, meta::is_unified_net)>;

TRIXY_TRAINING_TEMPLATE()
class Training<Trainable, TRWITH(Trainable, meta::is_unified_net)>
{
public:
    using Net = Trainable;

    template <class T>
    using Container                 = typename Net::template Container<T>;

    using Vector                    = typename Net::Vector;
    using Matrix                    = typename Net::Matrix;
    using Tensor                    = typename Net::Tensor;

    template <class T>
    using XContainer                = typename Net::template XContainer<T>;

    using XVector                   = typename Net::XVector;
    using XMatrix                   = typename Net::XMatrix;
    using XTensor                   = typename Net::XTensor;

    using precision_type            = typename Net::precision_type;
    using size_type                 = typename Net::size_type;

    using ITrainLayer               = typename Net::ITrainLayer;

    using ILoss                     = functional::loss::ILoss<precision_type>;
    using IOptimizer                = train::IOptimizer<Net>;

private:
    Net& net;                       ///< reference to network prevent her copying

    Tensor delta;                   ///< back propogation delta tensor

    ILoss* loss_;

public:
    explicit Training(Net& network);
    ~Training();

    // operator= for copy and move Training object will not implicit generate
    Training(const Training&) = default;
    Training(Training&&) noexcept = default;

    template <class GeneratorInteger>
    void stochastic(const Container<Tensor>& idata,
                    const Container<Tensor>& odata,
                    IOptimizer& optimizer,
                    size_type iteration_scale,
                    GeneratorInteger generator) noexcept;

    void batch(const Container<Tensor>& idata,
               const Container<Tensor>& odata,
               IOptimizer& optimizer,
               size_type number_of_epochs) noexcept;

    void mini_batch(const Container<Tensor>& idata,
                    const Container<Tensor>& odata,
                    IOptimizer& optimizer,
                    size_type number_of_epochs,
                    size_type mini_batch_size) noexcept;

    void feedforward(const Tensor& sample) noexcept;

    void backprop(const Tensor& sample,
                  const Tensor& target) noexcept;

    void loss(ILoss* loss);

    bool update();

    long double loss(const Container<Tensor>& idata,
                     const Container<Tensor>& odata) const noexcept;

private:
    ITrainLayer& layer(size_type i) noexcept;

private:
    // only for model
    void updating(IOptimizer& optimizer, precision_type alpha) noexcept;

    void reseting() noexcept;
    void accumulating() noexcept;
};

TRIXY_TRAINING_TEMPLATE()
UnifiedNetTraining<Trainable>::Training(Trainable& network)
    : net(network), delta(network.inner().back()->osize()), loss_(nullptr)
{
}

TRIXY_TRAINING_TEMPLATE()
UnifiedNetTraining<Trainable>::~Training()
{
    delete loss_;
}

TRIXY_TRAINING_TEMPLATE()
void UnifiedNetTraining<Trainable>::loss(ILoss* loss)
{
    delete loss_;
    loss_ = loss;
}

TRIXY_TRAINING_TEMPLATE()
bool UnifiedNetTraining<Trainable>::update()
{
    auto& shape = net.inner.back()->osize();

    bool is_changing = delta.shape().size != shape.size;

    if (is_changing) delta.resize(shape);
    else delta.reshape(shape);

    return is_changing;
}

TRIXY_TRAINING_TEMPLATE()
template <class GeneratorInteger>
void UnifiedNetTraining<Trainable>::stochastic(
    const Container<Tensor>& idata,
    const Container<Tensor>& odata,
    IOptimizer& optimizer,
    size_type iteration_scale,
    GeneratorInteger generator) noexcept
{
    for (size_type iteration = 0, sample; iteration < iteration_scale; ++iteration)
    {
        sample = generator() % idata.size();

        feedforward(idata[sample]);
        backprop(idata[sample], odata[sample]);

        // Updating the model with dynamic gradients, without their accumulation
        updating(optimizer, 1.f);
    }
}

TRIXY_TRAINING_TEMPLATE()
void UnifiedNetTraining<Trainable>::batch(
    const Container<Tensor>& idata,
    const Container<Tensor>& odata,
    IOptimizer& optimizer,
    size_type number_of_epochs) noexcept
{
    precision_type alpha = 1. / static_cast<precision_type>(idata.size());

    for (size_type epoch = 0, sample; epoch < number_of_epochs; ++epoch)
    {
        reseting();

        for (sample = 0; sample < idata.size(); ++sample)
        {
            feedforward(idata[sample]);
            backprop(idata[sample], odata[sample]);

            accumulating();
        }

        updating(optimizer, alpha);
    }
}

TRIXY_TRAINING_TEMPLATE()
void UnifiedNetTraining<Trainable>::mini_batch(
    const Container<Tensor>& idata,
    const Container<Tensor>& odata,
    IOptimizer& optimizer,
    size_type number_of_epochs,
    size_type mini_batch_size) noexcept
{
    precision_type alpha = 1. / static_cast<precision_type>(mini_batch_size);

    // number of iterations per full batch
    size_type iteration_scale = idata.size() / mini_batch_size; // implicit drop floating part

    size_type sample;
    size_type sample_limit;

    for (size_type epoch = 0, iteration; epoch < number_of_epochs; ++epoch)
    {
        sample = 0;
        sample_limit = 0;

        for (iteration = 0; iteration < iteration_scale; ++iteration)
        {
            sample_limit += mini_batch_size;

            reseting();

            // accumulating deltas for one mini-batch
            while (sample < sample_limit)
            {
                feedforward(idata[sample]);
                backprop(idata[sample], odata[sample]);

                accumulating();

                ++sample;
            }
            // averaging deltas for one mini-batch
            updating(optimizer, alpha);
        }
    }
}

TRIXY_TRAINING_TEMPLATE()
void UnifiedNetTraining<Trainable>::feedforward(
    const Tensor& sample) noexcept
{
    net.feedforward(sample);
}

TRIXY_TRAINING_TEMPLATE()
void UnifiedNetTraining<Trainable>::backprop(
    const Tensor& sample,
    const Tensor& target) noexcept
{
    const size_type N = net.size();

    loss_->df(delta, target, layer(N - 1).value());

    layer(N - 1).backward(layer(N - 2).value(), delta);

    for (size_type i = N - 2; i > 0; --i)
        layer(i).backward(layer(i - 1).value(), layer(i + 1).delta());

    layer(0).backward(sample, layer(1).delta(), false);
}

TRIXY_TRAINING_TEMPLATE()
long double UnifiedNetTraining<Trainable>::loss(
    const Container<Tensor>& idata,
    const Container<Tensor>& odata) const noexcept
{
    precision_type result = 0.;
    precision_type error  = 0.;

    for (size_type i = 0; i < odata.size(); ++i)
    {
        loss_->f(error, odata[i], net.feedforward(idata[i]));
        result += error;
    }

    return result / static_cast<long double>(odata.size());
}

TRIXY_TRAINING_TEMPLATE()
typename UnifiedNetTraining<Trainable>::ITrainLayer&
    UnifiedNetTraining<Trainable>::layer(size_type i) noexcept
{
    // Provides access to the layer's training interface
    return static_cast<ITrainLayer&>(net.layer(i));
}

TRIXY_TRAINING_TEMPLATE()
void UnifiedNetTraining<Trainable>::updating(IOptimizer& optimizer, precision_type alpha) noexcept
{
    for (size_type i = 0; i < net.size(); ++i) layer(i).update(optimizer, alpha);
}

TRIXY_TRAINING_TEMPLATE()
void UnifiedNetTraining<Trainable>::reseting() noexcept
{
    for (size_type i = 0; i < net.size(); ++i) layer(i).reset();
}

TRIXY_TRAINING_TEMPLATE()
void UnifiedNetTraining<Trainable>::accumulating() noexcept
{
    for (size_type i = 0; i < net.size(); ++i) layer(i).accumulate();
}

} // namespace train

} // namespace trixy

namespace trixy
{

namespace train
{

TRIXY_TRAINING_TEMPLATE()
using LinearRegressionTraining
    = Training<Trainable, TRWITH(Trainable, meta::is_linear_regression)>;

TRIXY_TRAINING_TEMPLATE()
class Training<Trainable, TRWITH(Trainable, meta::is_linear_regression)>
{
public:
    using Vector          = typename Trainable::Vector;
    using Matrix          = typename Trainable::Matrix;

    using precision_type  = typename Trainable::precision_type;
    using size_type       = typename Trainable::size_type;

private:
    Trainable& reg;

public:
    explicit Training(Trainable& regression) : reg(regression) {}

    void train(const Matrix& idata,
               const Vector& odata);

    long double loss(const Matrix& idata,
                     const Vector& odata) const;
};

TRIXY_TRAINING_TEMPLATE()
void LinearRegressionTraining<Trainable>::train(
    const Matrix& idata,
    const Vector& odata)
{
    Matrix X(idata.shape().height, reg.N);

    for (size_type i = 0; i < X.shape().height; ++i)
    {
        X(i, 0) = 1.;
        for (size_type j = 1; j < reg.N; ++j)
            X(i, j) = idata(i, j - 1);
    }

    Matrix X_T = reg.linear.transpose(X);
    Matrix X_T_X = reg.linear.dot(X_T, X);

    // W = (X^T . X)^(-1) . X^T . Y
    reg.linear.dot(
        reg.W,
        // (X^T . X)^(-1) . X^T
        reg.linear.dot(reg.linear.inverse(X_T_X), X_T),
        odata
    );
}

TRIXY_TRAINING_TEMPLATE()
long double LinearRegressionTraining<Trainable>::loss(
    const Matrix& idata,
    const Vector& odata) const
{
    return reg.loss(idata, odata);
}

} // namespace train

} // namespace trixy

namespace trixy
{

namespace train
{

TRIXY_TRAINING_TEMPLATE()
using PolynomialRegressionTraining
    = Training<Trainable, TRWITH(Trainable, meta::is_polynomial_regression)>;

TRIXY_TRAINING_TEMPLATE()
class Training<Trainable, TRWITH(Trainable, meta::is_polynomial_regression)>
{
public:
    using Vector          = typename Trainable::Vector;
    using Matrix          = typename Trainable::Matrix;

    using precision_type  = typename Trainable::precision_type;
    using size_type       = typename Trainable::size_type;

private:
    Trainable& reg;

public:
    explicit Training(Trainable& regression) : reg(regression) {}

    void train(const Vector& idata,
               const Vector& odata);

    long double loss(const Vector& idata,
                     const Vector& odata) const;
};

TRIXY_TRAINING_TEMPLATE()
void PolynomialRegressionTraining<Trainable>::train(
    const Vector& idata,
    const Vector& odata)
{
    Matrix X(idata.size(), reg.N);

    precision_type sample;
    precision_type power;

    for (size_type i = 0; i < idata.size(); ++i)
    {
        sample = idata(i);
        power  = 1.;

        for (size_type j = 0; j < reg.N; ++j)
        {
            X(i, j) = power;
            power  *= sample;
        }
    }

    Matrix X_T = reg.linear.transpose(X);
    Matrix X_T_X = reg.linear.dot(X_T, X);

    // W = (X^T . X)^(-1) . X^T . Y
    reg.linear.dot(
        reg.W,
        // (X^T . X)^(-1) . X^T
        reg.linear.dot(reg.linear.inverse(X_T_X), X_T),
        odata
    );
}

TRIXY_TRAINING_TEMPLATE()
long double PolynomialRegressionTraining<Trainable>::loss(
    const Vector& idata,
    const Vector& odata) const
{
    return reg.loss(idata, odata);
}

} // namespace train

} // namespace trixy

// This file contains all internal macro definitions
// You MUST include MacroUnscope.hpp at the end of *.hpp to undef all of them

#define TRIXY_ACCURACY_TEMPLATE(...)                                                                    \
    TRIXY_TEMPLATE(template <typename, typename...> class Container, class Sample, class Target)

#define TRIXY_ACCURACY_GUIDE_TEMPLATE(...)                                                              \
    TRIXY_TEMPLATE(class Target, class Prediction)

namespace trixy
{

template <class Checkable>
class Accuracy
{
public:
    class Guide;

public:
    using Net = Checkable;

    using precision_type        = typename Net::precision_type;
    using size_type             = typename Net::size_type;

private:
    Net& net;

public:
    explicit Accuracy(Net& network) : net(network) {}

    // operator= for copy and move Accuracy object will not implicit generate
    Accuracy(const Accuracy&) = default;
    Accuracy(Accuracy&&) noexcept = default;

    TRIXY_ACCURACY_TEMPLATE()
    long double normal(const Container<Sample>& idata,
                       const Container<Target>& odata) noexcept
    {
        size_type count = 0;

        for (size_type i = 0; i < odata.size(); ++i)
            if (Guide::normal(odata[i], net.feedforward(idata[i])))
                ++count;

        return static_cast<long double>(count) / odata.size();
    }

    TRIXY_ACCURACY_TEMPLATE()
    long double full(const Container<Sample>& idata,
                     const Container<Target>& odata,
                     precision_type range_rate) noexcept
    {
        size_type count = 0;

        for (size_type i = 0; i < odata.size(); ++i)
            if (Guide::full(odata[i], net.feedforward(idata[i]), range_rate))
                ++count;

        return static_cast<long double>(count) / odata.size();
    }

    TRIXY_ACCURACY_TEMPLATE()
    long double global(const Container<Sample>& idata,
                       const Container<Target>& odata,
                       precision_type range_rate) noexcept
    {
        size_type count = 0;

        for (size_type i = 0; i < odata.size(); ++i)
            count += Guide::global(odata[i], net.feedforward(idata[i]), range_rate);

        return static_cast<long double>(count) / (odata.size() * odata.front().size());
    }

    TRIXY_ACCURACY_TEMPLATE()
    long double operator() (const Container<Sample>& idata,
                            const Container<Target>& odata) noexcept
    {
        return normal(idata, odata);
    }
};

template <class Checkable>
class Accuracy<Checkable>::Guide
{
public:
    TRIXY_ACCURACY_GUIDE_TEMPLATE()
    static bool normal(const Target& target,
                       const Prediction& prediction) noexcept
    {
        size_type max_true_out;
        size_type max_pred_out;

        max_true_out = 0;
        max_pred_out = 0;

        for (size_type j = 1; j < target.size(); ++j)
            if (target(max_true_out) < target(j))
                max_true_out = j;

        for (size_type j = 1; j < target.size(); ++j)
            if (prediction(max_pred_out) < prediction(j))
                max_pred_out = j;

        return max_true_out == max_pred_out;
    }

    TRIXY_ACCURACY_GUIDE_TEMPLATE()
    static bool full(const Target& target,
                     const Prediction& prediction,
                     precision_type range_rate) noexcept
    {
        for (size_type j = 0; j < target.size(); ++j)
            if (std::fabs(target(j) - prediction(j)) > range_rate)
                return false;

        return true;
    }

    TRIXY_ACCURACY_GUIDE_TEMPLATE()
    static size_type global(const Target& target,
                            const Prediction& prediction,
                            precision_type range_rate) noexcept
    {
        size_type count = 0;
        for (size_type i = 0; i < target.size(); ++i)
            if (std::fabs(target(i) - prediction(i)) < range_rate)
                ++count;

        return count;
    }

    TRIXY_ACCURACY_GUIDE_TEMPLATE()
    bool operator() (const Target& target,
                     const Prediction& prediction) const noexcept
    {
        return normal(target, prediction);
    }
};

} // namespace trixy

namespace trixy
{

template <class Checkable>
class Checker
{
public:
    using Net = Checkable;

    using precision_type        = typename Net::precision_type;
    using size_type             = typename Net::size_type;

private:
    using Accuracy              = Accuracy<Net>;
    using Guide                 = typename Accuracy::Guide;

private:
    Checkable& net;

public:
    Accuracy accuracy;
    Guide guide;

public:
    explicit Checker(Net& network)
    : net(network), accuracy(network), guide() {}

    // operator= for copy and move Checker object will not implicit generate
    Checker(const Checker&) = default;
    Checker(Checker&&) noexcept = default;

    template <template <typename, typename...> class Container,
              class Sample, class Target, class LossFunction>
    long double loss(const Container<Sample>& idata,
                     const Container<Target>& odata,
                     LossFunction loss_function) noexcept
    {
        precision_type result = 0.;
        precision_type error  = 0.;

        for (size_type i = 0; i < odata.size(); ++i)
        {
            loss_function(error, odata[i], net.feedforward(idata[i]));
            result += error;
        }

        return result / static_cast<long double>(odata.size());
    }

    template <class Sample, class Target, class LossFunction>
    long double loss(const Sample& sample,
                     const Target& target,
                     LossFunction loss_function) noexcept
    {
        precision_type error = 0.;

        loss_function(error, target, net.feedforward(sample));

        return error;
    }
};

} // namespace trixy

namespace trixy
{

namespace functional
{

namespace loss
{

template <typename Precision, class Target, class Prediction>
void categorical_cross_entropy(Precision& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    static constexpr Precision epsilon = 1e-9;

    auto target = y_true.data();
    auto end    = y_true.data() + y_true.size();

    auto pred   = y_pred.data();

    result = Precision{};
    while (target != end)
    {
        result -= (*target) * std::log(*pred + epsilon);

        ++target;
        ++pred;
    }
}

template <class Buffer, class Target, class Prediction>
void categorical_cross_entropy_derived(Buffer& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    static constexpr auto epsilon = 1e-9;

    auto first  = result.data();
    auto last   = result.data() + result.size();

    auto target = y_true.data();
    auto pred   = y_pred.data();

    while (first != last)
    {
        *first++ = -(*target) / (*pred + epsilon);

        ++target;
        ++pred;
    }
}

template <typename Precision, class Target, class Prediction>
void mean_squared_error(Precision& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    static Precision f;

    auto target = y_true.data();
    auto end    = y_true.data() + y_true.size();

    auto pred   = y_pred.data();

    result = Precision{};
    while (target != end)
    {
        f = *target - *pred;
        result += f * f;

        ++target;
        ++pred;
    }

    result *= 0.5;
}

template <class Buffer, class Target, class Prediction>
void mean_squared_error_derived(Buffer& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    auto first  = result.data();
    auto last   = result.data() + result.size();

    auto target = y_true.data();
    auto pred   = y_pred.data();

    while (first != last)
    {
        *first++ = *pred - *target;

        ++target;
        ++pred;
    }
}

template <typename Precision, class Target, class Prediction>
void mean_absolute_error(Precision& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    auto target = y_true.data();
    auto end    = y_true.data() + y_true.size();

    auto pred   = y_pred.data();

    result = Precision{};
    while (target != end)
    {
        result += std::fabs(*pred - *target);

        ++target;
        ++pred;
    }
}

template <class Buffer, class Target, class Prediction>
void mean_absolute_error_derived(Buffer& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    auto first  = result.data();
    auto last   = result.data() + result.size();

    auto target = y_true.data();
    auto pred   = y_pred.data();

    while (first != last)
    {
        *first = *target - *pred;
        *first = *first < 0.
                 ? -1.
                 : (*first > 0. ? 1. : 0.);

        ++first;
        ++target;
        ++pred;
    }
}

template <typename Precision, class Target, class Prediction>
void mean_squared_log_error(Precision& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    static Precision f;

    auto target = y_true.data();
    auto end    = y_true.data() + y_true.size();

    auto pred   = y_pred.data();

    result = Precision{};
    while (target != end)
    {
        f = (*pred + 1.) / (*target + 1.);
        f = std::log(f);

        result += f * f;

        ++target;
        ++pred;
    }

    result *= 0.5;
}

template <class Buffer, class Target, class Prediction>
void mean_squared_log_error_derived(Buffer& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    auto first  = result.data();
    auto last   = result.data() + result.size();

    auto target = y_true.data();
    auto pred   = y_pred.data();

    while (first != last)
    {
        *first = *pred + 1.;
        *first = std::log(*first / (*target + 1.)) / (*first);

        ++first;
        ++target;
        ++pred;
    }
}

template <typename Precision, class Target, class Prediction>
void binary_cross_entropy(Precision& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    static constexpr Precision epsilon = 1e-9;

    auto target = y_true.data();
    auto end    = y_true.data() + y_true.size();

    auto pred   = y_pred.data();

    result = Precision{};
    while (target != end)
    {
        result -= (*target) * std::log(*pred + epsilon) +  (1. - *target) * std::log1p(epsilon - *pred);

        ++target;
        ++pred;
    }
}

template <class Buffer, class Target, class Prediction>
void binary_cross_entropy_derived(Buffer& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    static constexpr auto epsilon = 1e-9;
    static constexpr auto alpha   = epsilon - 1.0;

    auto first  = result.data();
    auto last   = result.data() + result.size();

    auto target = y_true.data();
    auto pred   = y_pred.data();

    while (first != last)
    {
        *first++ = (*target - 1.) / (*pred + alpha) - (*target) / (*pred + epsilon);

        ++target;
        ++pred;
    }
}

template <class Buffer, class Target, class Prediction>
void binary_cross_entropy_derived_sigmoid(Buffer& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    auto first  = result.data();
    auto last   = result.data() + result.size();

    auto target = y_true.data();
    auto pred   = y_pred.data();

    while (first != last)
    {
        *first++ = (*target) * (*pred - 1.) + (*pred) * (1. - *target);

        ++target;
        ++pred;
    }
}

template <class Precision, class Target, class Prediction>
void negative_log_likelihood(Precision& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    auto target = y_true.data();
    auto end    = y_true.data() + y_true.size();

    auto pred   = y_pred.data();

    result = Precision{};
    while (target != end)
    {
        result += (*target) * (*pred);

        ++target;
        ++pred;
    }
    // negative logarithm
    result = -std::log(result);
}

template <class Buffer, class Target, class Prediction>
void negative_log_likelihood_derived_softmax(Buffer& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    auto first  = result.data();
    auto last   = result.data() + result.size();

    auto target = y_true.data();
    auto pred   = y_pred.data();

    while (first != last)
    {
        *first++ = *pred - *target;

        ++target;
        ++pred;
    }
}

template <typename Precision, class Target, class Prediction>
void logcosh(Precision& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    auto target = y_true.data();
    auto end    = y_true.data() + y_true.size();

    auto pred   = y_pred.data();

    result = Precision{};
    while (target != end)
    {
        result += std::log(std::cosh(*pred - *target));

        ++target;
        ++pred;
    }
}

template <class Buffer, class Target, class Prediction>
void logcosh_derived(Buffer& result, const Target& y_true, const Prediction& y_pred) noexcept
{
    auto first  = result.data();
    auto last   = result.data() + result.size();

    auto target = y_true.data();
    auto pred   = y_pred.data();

    while (first != last)
    {
        *first++ = std::tanh(*pred - *target);

        ++target;
        ++pred;
    }
}

TRIXY_FUNCTION_GENERIC_LOSS_HELPER(MSE, mean_squared_error, mean_squared_error_derived);
TRIXY_FUNCTION_GENERIC_LOSS_HELPER(MAE, mean_absolute_error, mean_absolute_error_derived);
TRIXY_FUNCTION_GENERIC_LOSS_HELPER(CCE, categorical_cross_entropy, mean_squared_error_derived);
TRIXY_FUNCTION_GENERIC_LOSS_HELPER(BCE, binary_cross_entropy, binary_cross_entropy_derived_sigmoid);
TRIXY_FUNCTION_GENERIC_LOSS_HELPER(MSLE, mean_squared_log_error, mean_squared_log_error_derived);
TRIXY_FUNCTION_GENERIC_LOSS_HELPER(NLL, negative_log_likelihood, negative_log_likelihood_derived_softmax);
TRIXY_FUNCTION_GENERIC_LOSS_HELPER(LC, logcosh, logcosh_derived);

} // namespace loss

} // namespace functional

} // namespace trixy

namespace trixy
{

namespace utility
{

template <typename T>
struct Range<T, RangeType::Unified>
{
public:
    using pointer           = T*;
    using const_pointer     = const T*;

    using value_type        = T;
    using size_type         = std::size_t;
    using difference_type   = std::ptrdiff_t;

private:
    pointer first_;
    size_type size_;

public:
    Range() : first_(nullptr), size_(0) {}

    Range(size_type size)
        : first_(new value_type [size]), size_(size)
    {
    }

    Range(size_type size, value_type value)
        : Range(size)
    {
        fill(first_, first_ + size_);
    }

    ~Range()
    {
        delete[] first_;
    }

    void fill(value_type value)
    {
        auto first = first_;
        auto last  = first_ + size_;

        while (first != last) *first++ = value;
    }

    void resize(size_type size)
    {
        delete[] first_;

        first_ = new value_type [size];
        size_  = size;
    }

    void resize(size_type size, value_type value)
    {
        resize(size);
        fill(value);
    }

    pointer data() noexcept { return first_; }
    const_pointer data() const noexcept { return first_; }

    difference_type size() const noexcept { return size_; }

    pointer first() noexcept { return size_; }
    pointer last() noexcept { return first_ + size_; }

    const_pointer first() const noexcept { return first_; }
    const_pointer last() const noexcept { return first_ + size_; }
};

} // namespace utility

} // namespace trixy

namespace trixy
{

namespace train
{

template <class Optimizeriable>
class IOptimizer<Optimizeriable,
    meta::when<meta::is_trixy_net<Optimizeriable>::value>>
{
public:
    using Net               = Optimizeriable;

    using precision_type    = typename Net::precision_type;
    using size_type         = typename Net::size_type;

    using Range             = utility::Range<precision_type>; // default view range
    using RangeUnified      = utility::Range<precision_type, RangeType::Unified>;

private:
    template <typename Ret, typename... Args>
    using Func = Ret (*)(void* const, Args...);

private:
    Func<void, precision_type> f_set_learning_rate = nullptr;
    Func<precision_type> f_get_learning_rate = nullptr;

    Func<void, Range, Range> f_update = nullptr;

protected:
    template <class Derived>
    void initialize() noexcept
    {
        f_set_learning_rate = [](void *const self, precision_type value)
        { static_cast<Derived*>(self)->learning_rate(value); };

        f_get_learning_rate = [](void *const self) -> precision_type
        { return static_cast<Derived*>(self)->learning_rate(); };

        f_update = [](void *const self, Range param, Range grad)
        { static_cast<Derived*>(self)->update(param, grad); };
    }

public:
    virtual ~IOptimizer() = default;

    void learning_rate(precision_type value) noexcept
    {
        f_set_learning_rate(this, value);
    }

    precision_type learning_rate() const noexcept
    {
        return f_get_learning_rate(this);
    }

    void update(Range param, Range grad) noexcept
    {
        f_update(this, param, grad);
    }

protected:
    template <class Table>
    static RangeUnified& get(Table& table, Range range)
    {
        auto key = reinterpret_cast<typename Table::key_type>(range.data());
        auto& buff = table[key];

        if (buff.data() == nullptr)
            buff.resize(range.size(), precision_type{});

        return buff;
    }
};

} // namespace train

} // namespace trixy

namespace trixy
{

namespace train
{

template <class Optimizeriable, class TypeSet = OptimizerTypeSet>
using GradDescent
    = TRIXY_OPTIMIZER_TEMPLATE_CLASS(meta::is_trixy_net, OptimizerType::grad_descent);

TRIXY_OPTIMIZER_TEMPLATE()
class TRIXY_OPTIMIZER_TEMPLATE_CLASS(meta::is_trixy_net, OptimizerType::grad_descent)
    : public IOptimizer<Optimizeriable>
{
public:
    using Net  = Optimizeriable;
    using Base = IOptimizer<Net>;

public:
    using typename Base::precision_type;
    using typename Base::size_type;

    using typename Base::Range;

private:
    Net& net;
    precision_type learning_rate_;

public:
    Optimizer(Net& network,
              precision_type learning_rate)
        : Base()
        , net(network)
        , learning_rate_(learning_rate)
    {
        this->template initialize<Optimizer>();
    }

    precision_type learning_rate() const noexcept { return learning_rate_; }
    void learning_rate(precision_type value) noexcept { learning_rate_ = value; }

    void update(Range param, Range grad) noexcept
    {
        // w = w - learning_rate * grad
        net.linear.join(grad, learning_rate_);
        net.linear.sub(param, grad);
    }
};

template <class TypeSet = OptimizerTypeSet, class Net, typename... Args>
GradDescent<Net, TypeSet> GradDescentOptimizer(Net& net, Args&&... args)
{
    return GradDescent<Net, TypeSet>(net, std::forward<Args>(args)...);
}

} // namespace train

} // namespace trixy

namespace trixy
{

namespace train
{

template <class Optimizeriable, class TypeSet = OptimizerTypeSet>
using StoGradDescent
    = TRIXY_OPTIMIZER_TEMPLATE_CLASS(meta::is_trixy_net, OptimizerType::stograd_descent);

TRIXY_OPTIMIZER_TEMPLATE()
class TRIXY_OPTIMIZER_TEMPLATE_CLASS(meta::is_trixy_net, OptimizerType::stograd_descent)
    : public IOptimizer<Optimizeriable>
{
public:
    using Net  = Optimizeriable;
    using Base = IOptimizer<Net>;

public:
    using typename Base::precision_type;
    using typename Base::size_type;

    using typename Base::Range;

private:
    Net& net;

    precision_type learning_rate_;
    precision_type alpha_;

public:
    Optimizer(Net& network,
              precision_type learning_rate,
              precision_type decay = 0.e-6)
        : Base()
        , net(network)
        , learning_rate_(learning_rate)
        , alpha_(1. - learning_rate * decay)
    {
        this->template initialize<Optimizer>();
    }

    precision_type learning_rate() const noexcept { return learning_rate_; }
    void learning_rate(precision_type value) noexcept { learning_rate_ = value; }

    void update(Range param, Range grad) noexcept
    {
        // w = alpha * w - learning_rate * grad
        net.linear.join(grad, learning_rate_);
        net.linear.join(param, alpha_);

        net.linear.sub(param, grad);
    }
};

template <class TypeSet = OptimizerTypeSet, class Net, typename... Args>
StoGradDescent<Net, TypeSet> StoGradDescentOptimizer(Net& net, Args&&... args)
{
    return StoGradDescent<Net, TypeSet>(net, std::forward<Args>(args)...);
}

} // namespace train

} // namespace trixy

namespace trixy
{

namespace train
{

template <class Optimizeriable, class TypeSet = OptimizerTypeSet>
using Momentum
    = TRIXY_OPTIMIZER_TEMPLATE_CLASS(meta::is_trixy_net, OptimizerType::momentum);

TRIXY_OPTIMIZER_TEMPLATE()
class TRIXY_OPTIMIZER_TEMPLATE_CLASS(meta::is_trixy_net, OptimizerType::momentum)
    : public IOptimizer<Optimizeriable>
{
public:
    using Net  = Optimizeriable;
    using Base = IOptimizer<Net>;

public:
    using typename Base::precision_type;
    using typename Base::size_type;

    using typename Base::Range;
    using typename Base::RangeUnified;

private:
    using Table = OptimizerTypeSet::template Table<std::uintptr_t, RangeUnified>;

private:
    Net& net;

    Table buff_table_;
    Table optimized_table_;

    precision_type learning_rate_;
    precision_type momentum_;

public:
    Optimizer(Net& network,
              precision_type learning_rate,
              precision_type momentum = 0.9)
        : Base()
        , net(network)
        , buff_table_()
        , optimized_table_()
        , learning_rate_(learning_rate)
        , momentum_(momentum)
    {
        this->template initialize<Optimizer>();
    }

    Optimizer& reset() noexcept
    {
        auto first = optimized_table_.begin();
        auto last  = optimized_table_.end();

        while (first != last)
        {
            first->fill(0.);
            ++first;
        }

        return *this;
    }

    precision_type learning_rate() const noexcept { return learning_rate_; }
    void learning_rate(precision_type value) noexcept { learning_rate_ = value; }

    void update(Range param, Range grad) noexcept
    {
        auto& buff = Base::get(buff_table_, param);
        auto& optimized = Base::get(optimized_table_, param);

        // velocity = momentum * velocity - learning_rate * g
        // w = w + velocity

        net.linear.join(optimized, momentum_);
        net.linear.join(buff, learning_rate_, grad);
        net.linear.sub(optimized, buff);

        net.linear.add(param, optimized);
    }
};

template <class TypeSet = OptimizerTypeSet, class Net, typename... Args>
Momentum<Net, TypeSet> MomentumOptimizer(Net& net, Args&&... args)
{
    return Momentum<Net, TypeSet>(net, std::forward<Args>(args)...);
}

} // namespace train

} // namespace trixy

namespace trixy
{

namespace train
{

template <class Optimizeriable, class TypeSet = OptimizerTypeSet>
using Nestorov
    = TRIXY_OPTIMIZER_TEMPLATE_CLASS(meta::is_trixy_net, OptimizerType::nestorov);

TRIXY_OPTIMIZER_TEMPLATE()
class TRIXY_OPTIMIZER_TEMPLATE_CLASS(meta::is_trixy_net, OptimizerType::nestorov)
    : public IOptimizer<Optimizeriable>
{
public:
    using Net  = Optimizeriable;
    using Base = IOptimizer<Net>;

public:
    using typename Base::precision_type;
    using typename Base::size_type;

    using typename Base::Range;
    using typename Base::RangeUnified;

private:
    using Table = OptimizerTypeSet::template Table<std::uintptr_t, RangeUnified>;

private:
    Net& net;

    Table buff_table_;
    Table optimized_table_;

    precision_type learning_rate_;
    precision_type momentum_;

public:
    Optimizer(Net& network,
              precision_type learning_rate,
              precision_type momentum = 0.9)
        : Base()
        , net(network)
        , buff_table_()
        , optimized_table_()
        , learning_rate_(learning_rate)
        , momentum_(momentum)
    {
        this->template initialize<Optimizer>();
    }

    Optimizer& reset() noexcept
    {
        auto first = optimized_table_.begin();
        auto last  = optimized_table_.end();

        while (first != last)
        {
            first->fill(0.);
            ++first;
        }

        return *this;
    }

    precision_type learning_rate() const noexcept { return learning_rate_; }
    void learning_rate(precision_type value) noexcept { learning_rate_ = value; }

    void update(Range param, Range grad) noexcept
    {
        auto& buff = Base::get(buff_table_, param);
        auto& optimized = Base::get(optimized_table_, param);

        // velocity = momentum * velocity - learning_rate * g
        // w = w + momentum * velocity - learning_rate * g

        net.linear.join(optimized, momentum_);
        net.linear.join(buff, learning_rate_, grad);
        net.linear.sub(optimized, buff);

        net.linear.sub(param, buff);
        net.linear.join(buff, momentum_, optimized);
        net.linear.add(param, buff);
    }
};

template <class TypeSet = OptimizerTypeSet, class Net, typename... Args>
Nestorov<Net, TypeSet> NestorovOptimizer(Net& net, Args&&... args)
{
    return Nestorov<Net, TypeSet>(net, std::forward<Args>(args)...);
}

} // namespace train

} // namespace trixy

namespace trixy
{

namespace train
{

template <class Optimizeriable, class TypeSet = OptimizerTypeSet>
using AdaGrad
    = TRIXY_OPTIMIZER_TEMPLATE_CLASS(meta::is_trixy_net, OptimizerType::ada_grad);

TRIXY_OPTIMIZER_TEMPLATE()
class TRIXY_OPTIMIZER_TEMPLATE_CLASS(meta::is_trixy_net, OptimizerType::ada_grad)
    : public IOptimizer<Optimizeriable>
{
public:
    using Net  = Optimizeriable;
    using Base = IOptimizer<Net>;

public:
    using typename Base::precision_type;
    using typename Base::size_type;

    using typename Base::Range;
    using typename Base::RangeUnified;

private:
    using Table = OptimizerTypeSet::template Table<std::uintptr_t, RangeUnified>;

private:
    Net& net;

    Table buff_table_;
    Table optimized_table_;

    precision_type learning_rate_;

public:
    Optimizer(Net& network,
              precision_type learning_rate)
        : Base()
        , net(network)
        , buff_table_()
        , optimized_table_()
        , learning_rate_(learning_rate)
    {
        this->template initialize<Optimizer>();
    }

    Optimizer& reset() noexcept
    {
        auto first = optimized_table_.begin();
        auto last  = optimized_table_.end();

        while (first != last)
        {
            first->fill(0.);
            ++first;
        }

        return *this;
    }

    precision_type learning_rate() const noexcept { return learning_rate_; }
    void learning_rate(precision_type value) noexcept { learning_rate_ = value; }

    void update(Range param, Range grad) noexcept
    {
        auto& buff = Base::get(buff_table_, param);
        auto& optimized = Base::get(optimized_table_, param);

        // velocity = velocity + g * g
        // w = w - learning_rate * g / sqrt(velocity)

        net.linear.mul(buff, grad, grad);
        net.linear.add(optimized, buff);

        net.linear.apply(buff, &detail::invert_sqrt<precision_type>, optimized);
        net.linear.mul(buff, grad);
        net.linear.join(buff, learning_rate_);

        net.linear.sub(param, buff);
    }
};

template <class TypeSet = OptimizerTypeSet, class Net, typename... Args>
AdaGrad<Net, TypeSet> AdaGradOptimizer(Net& net, Args&&... args)
{
    return AdaGrad<Net, TypeSet>(net, std::forward<Args>(args)...);
}

} // namespace train

} // namespace trixy

namespace trixy
{

namespace train
{

template <class Optimizeriable, class TypeSet = OptimizerTypeSet>
using RMSProp
    = TRIXY_OPTIMIZER_TEMPLATE_CLASS(meta::is_trixy_net, OptimizerType::rms_prop);

TRIXY_OPTIMIZER_TEMPLATE()
class TRIXY_OPTIMIZER_TEMPLATE_CLASS(meta::is_trixy_net, OptimizerType::rms_prop)
    : public IOptimizer<Optimizeriable>
{
public:
    using Net  = Optimizeriable;
    using Base = IOptimizer<Net>;

public:
    using typename Base::precision_type;
    using typename Base::size_type;

    using typename Base::Range;
    using typename Base::RangeUnified;

private:
    using Table = OptimizerTypeSet::template Table<std::uintptr_t, RangeUnified>;

private:
    Net& net;

    Table buff_table_;
    Table optimized_table_;

    precision_type learning_rate_;
    precision_type beta, rbeta;

public:
    Optimizer(Net& network,
              precision_type learning_rate,
              precision_type beta = 0.9)
        : Base()
        , net(network)
        , buff_table_()
        , optimized_table_()
        , learning_rate_(learning_rate)
        , beta(beta)
    {
        this->template initialize<Optimizer>();

        rbeta = 1. - beta;
    }

    Optimizer& reset() noexcept
    {
        auto first = optimized_table_.begin();
        auto last  = optimized_table_.end();

        while (first != last)
        {
            first->fill(0.);
            ++first;
        }

        return *this;
    }

    precision_type learning_rate() const noexcept { return learning_rate_; }
    void learning_rate(precision_type value) noexcept { learning_rate_ = value; }

    void update(Range param, Range grad) noexcept
    {
        auto& buff = Base::get(buff_table_, param);
        auto& optimized = Base::get(optimized_table_, param);

        // velocity = beta * velocity + (1 - beta) * g * g
        // w = w - learning_rate * g / sqrt(velocity)

        net.linear.join(optimized, beta);
        net.linear.mul(buff, grad, grad);
        net.linear.join(buff, rbeta);
        net.linear.add(optimized, buff);

        net.linear.apply(buff, &detail::invert_sqrt<precision_type>, optimized);
        net.linear.mul(buff, grad);
        net.linear.join(buff, learning_rate_);

        net.linear.sub(param, buff);
    }
};

template <class TypeSet = OptimizerTypeSet, class Net, typename... Args>
RMSProp<Net, TypeSet> RMSPropOptimizer(Net& net, Args&&... args)
{
    return RMSProp<Net, TypeSet>(net, std::forward<Args>(args)...);
}

} // namespace train

} // namespace trixy

namespace trixy
{

namespace train
{

template <class Optimizeriable, class TypeSet = OptimizerTypeSet>
using Adam
    = TRIXY_OPTIMIZER_TEMPLATE_CLASS(meta::is_trixy_net, OptimizerType::adam);

TRIXY_OPTIMIZER_TEMPLATE()
class TRIXY_OPTIMIZER_TEMPLATE_CLASS(meta::is_trixy_net, OptimizerType::adam)
    : public IOptimizer<Optimizeriable>
{
public:
    using Net  = Optimizeriable;
    using Base = IOptimizer<Net>;

public:
    using typename Base::precision_type;
    using typename Base::size_type;

    using typename Base::Range;
    using typename Base::RangeUnified;

private:
    using Table = OptimizerTypeSet::template Table<std::uintptr_t, RangeUnified>;

private:
    Net& net;

    Table buff_table_;
    Table optimized_m_table_;
    Table optimized_s_table_;

    precision_type learning_rate_;

    precision_type beta1, beta2;
    precision_type rbeta1, rbeta2;

    precision_type tbeta1, tbeta2;

public:
    Optimizer(Net& network,
              precision_type learning_rate,
              precision_type beta1 = 0.9,
              precision_type beta2 = 0.999)
        : Base()
        , net(network)
        , buff_table_()
        , optimized_m_table_()
        , optimized_s_table_()
        , learning_rate_(learning_rate)
        , beta1(beta1)
        , beta2(beta2)
    {
        this->template initialize<Optimizer>();

        rbeta1 = 1. - beta1;
        rbeta2 = 1. - beta2;

        tbeta1 = 1.;
        tbeta2 = 1.;
    }

    Optimizer& reset() noexcept
    {
        auto first_m = optimized_m_table_.begin();
        auto last_m  = optimized_m_table_.end();

        while (first_m != last_m)
        {
            first_m->fill(0.);
            ++first_m;
        }

        auto first_s = optimized_s_table_.begin();
        auto last_s  = optimized_m_table_.end();

        while (first_s != last_s)
        {
            first_s->fill(0.);
            ++first_s;
        }

        return *this;
    }

    precision_type learning_rate() const noexcept { return learning_rate_; }
    void learning_rate(precision_type value) noexcept { learning_rate_ = value; }

    void update(Range param, Range grad) noexcept
    {
        auto& buff = this->get(buff_table_, param);

        auto& optimized_m = Base::get(optimized_m_table_, param);
        auto& optimized_s = Base::get(optimized_s_table_, param);

        // m = beta1 * m + (1 - beta1) * g
        // s = beta2 * m + (1 - beta2) * g * g

        // xm = m / (1 - beta1 ^ t)
        // xs = x / (1 - beta2 ^ t)

        // w = w - learning_rate * xm / sqrt(xs)

        // where: t - is number of calls this function (or number of iteration in train)

        tbeta1 *= beta1;
        tbeta2 *= beta2;

        net.linear.join(optimized_m, beta1);
        net.linear.join(buff, rbeta1, grad);
        net.linear.add(optimized_m, buff);

        net.linear.join(optimized_s, beta2);
        net.linear.mul(buff, grad, grad);
        net.linear.join(buff, rbeta2);
        net.linear.add(optimized_s, buff);

        net.linear.join(buff, 1. / (1. - tbeta2), optimized_s);
        net.linear.apply(buff, &detail::invert_sqrt<precision_type>);
        net.linear.mul(buff, optimized_m);
        net.linear.join(buff,  learning_rate_ / (1. - tbeta1));

        net.linear.sub(param, buff);
    }
};

template <class TypeSet = OptimizerTypeSet, class Net, typename... Args>
Adam<Net, TypeSet> AdamOptimizer(Net& net, Args&&... args)
{
    return Adam<Net, TypeSet>(net, std::forward<Args>(args)...);
}

} // namespace train

} // namespace trixy

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

#include <ctime> // time

namespace trixy
{

namespace utility
{

struct RandomType
{
    template <typename T = long long,
              typename = meta::when<std::is_integral<T>::value>>
    struct Integral { using type = T; };

    template <typename T = double,
              typename = meta::when<std::is_floating_point<T>::value>>
    struct Floating { using type = T; };
};

} // namespace utility

namespace meta
{

template <typename>
struct is_integral_random_type : std::false_type {};
template <typename T>
struct is_integral_random_type<utility::RandomType::Integral<T>> : std::true_type {};

template <typename>
struct is_floating_random_type : std::false_type {};
template <typename T>
struct is_floating_random_type<utility::RandomType::Floating<T>> : std::true_type {};

} // namespace meta

namespace utility
{

class DefaultGenerator
{
public:
    using size_type = std::size_t;
    using Generator = int (*)();

public:
    DefaultGenerator() noexcept
    {
        std::srand(DefaultGenerator::seed());
    }

    DefaultGenerator(size_type seed) noexcept { std::srand(seed); }

    void seed(size_type seed) noexcept { std::srand(seed); }

    int operator() () noexcept { return std::rand(); }

    static std::size_t seed() noexcept
    {
        return static_cast<std::size_t>(std::time(nullptr));
    }

    static constexpr int min() noexcept { return 0; }
    static constexpr int max() noexcept { return RAND_MAX; }
};

template <typename RandomType, class Generator = DefaultGenerator, typename enable = void>
class Random;

template <typename RandomType, class Generator>
class Random<RandomType, Generator,
    TRWHEN(meta::is_integral_random_type<RandomType>::value and
           trixy::meta::is_callable<Generator>::value)>
{
public:
    using integral_type = typename RandomType::type;
    using size_type = std::size_t;

private:
    Generator gen;

public:
    Random() noexcept : gen(DefaultGenerator::seed()) {}
    Random(size_type seed) noexcept : gen(seed) {}

    void seed(size_type seed) noexcept { gen.seed(seed); }

    integral_type operator() () noexcept
    {
        return static_cast<integral_type>(gen());
    }

    integral_type operator() (integral_type min, integral_type max) noexcept
    {
        return (*this)() % (max - min + 1) + min;
    }
};

template <typename RandomType, class Generator>
class Random<RandomType, Generator,
    TRWHEN(meta::is_floating_random_type<RandomType>::value and
           trixy::meta::is_callable<Generator>::value)>
{
public:
    using floating_type = typename RandomType::type;
    using size_type = std::size_t;

private:
    Generator generator_;

public:
    Random() noexcept : generator_(DefaultGenerator::seed()) {}
    Random(size_type seed) noexcept : generator_(seed) {}

    void seed(size_type seed) noexcept { generator_.seed(seed); }

    floating_type operator() () noexcept
    {
        return floating_type(generator_()) / floating_type(generator_.max());
    }

    floating_type operator() (floating_type min, floating_type max) noexcept
    {
        return (max - min) * (*this)() + min;
    }
};

template <typename T = RandomType::Integral<>::type, class Generator = DefaultGenerator>
using RandomIntegral = Random<RandomType::Integral<T>, Generator>;

template <typename T = RandomType::Floating<>::type, class Generator = DefaultGenerator>
using RandomFloating = Random<RandomType::Floating<T>, Generator>;

} // namespace utility

} // namespace trixy

namespace trixy
{

namespace let
{

using i8   = std::int8_t;
using i16  = std::int16_t;
using i32  = std::int32_t;
using i64  = std::int64_t;

using u8   = std::uint8_t;
using u16  = std::uint16_t;
using u32  = std::uint32_t;
using u64  = std::uint64_t;

using f32  = float;
using f64  = double;
using f128 = long double;

} // namespace let

// Special struct for types alias
template <typename Precision>
struct TypeSet
{
    template <typename T>
    using Container         = utility::Container<T>;

    using Vector            = lique::Vector<Precision>;
    using Matrix            = lique::Matrix<Precision>;
    using Tensor            = lique::Tensor<Precision>;

    using Linear            = lique::Linear<Precision>;

    using precision_type    = Precision;
    using size_type         = std::size_t;
};

} // namespace trixy

#endif // TRIXY_NET_HPP
