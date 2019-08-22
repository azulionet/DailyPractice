#pragma once



template<size_t BinaryNum>
struct Bit
{
	static int GetNum()
	{
		static_assert((BinaryNum % 10) == 0 || (BinaryNum % 10) == 1);

		return Bit<BinaryNum%2>::GetNum() + 2*(Bit<(BinaryNum/10)>::GetNum());
	}
};

template<> struct Bit<0> { static int GetNum() { return 0; } };
template<> struct Bit<1> { static int GetNum() { return 1; } };

#define CheckFunc( T, fpFuncName ) \
template<typename, typename = void> struct has_func##fpFuncName : std::false_type { }; \
template<typename T> struct has_func##fpFuncName <T, std::void_t<decltype(std::declval<T>().fpFuncName())>> : std::true_type { };\
static_assert(has_func##fpFuncName<T>::value);

#define CheckMember( T, memberName ) \
template<typename, typename = void> struct has_member##memberName : std::false_type { }; \
template<typename T> struct has_member##memberName <T, std::void_t<decltype(std::declval<T>().memberName)>> : std::true_type { };\
static_assert(has_member##memberName<T>::value);

// #define Friend_FuncCheck(T); friend struct has_func<T>;
