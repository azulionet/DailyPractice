#include "pch.h"

using namespace std;

#include "Day0026.h"
#include <numeric>


#include <type_traits>

// size() 검사 
template<typename T, typename _Void>
struct has_length : std::false_type {};

template<typename T>
struct has_length<T, void_t<decltype(std::declval<T>().size())>> : std::true_type {};

template<typename T>
using use_length = has_length<T, void>;

template<typename T>
using use_length_t = typename use_length<T>::type;


template<typename T>
inline int GetVal_Impl(const std::false_type&, T val)
{
	cout << "int" << endl;
	return (int)val;

}
template<typename T>
inline int GetVal_Impl(const std::true_type&, T val)
{
	cout << "size" << endl;
	return val.size();
}

template<typename T>
int GetVal(T val)
{
	return GetVal_Impl<T>(use_length_t<T>{}, val);
}


// 특정 클래스 함수 검사 ( public 이어야함 )

#ifdef _DEBUG

	#define CheckFunc( T, fpFuncName ) \
	template<typename, typename = void> struct has_func##fpFuncName : std::false_type { }; \
	template<typename T> struct has_func##fpFuncName <T, std::void_t<decltype(std::declval<T>().fpFuncName())>> : std::true_type { };\
	static_assert(has_func##fpFuncName<T>::value);

	// 특정 클래스 변수 검사 ( public 이어야함 )
	#define CheckMember( T, memberName ) \
	template<typename, typename = void> struct has_member##memberName : std::false_type { }; \
	template<typename T> struct has_member##memberName <T, std::void_t<decltype(std::declval<T>().memberName)>> : std::true_type { };\
	static_assert(has_member##memberName<T>::value);

#else

	#define CheckFunc( T, fpFuncName )
	#define CheckMember( T, memberName )

#endif


class AAA
{
public:
	void EE()
	{

	}

	void AA()
	{

	}

	int nNum = 0;
};

// 사용 예
CheckMember(AAA, nNum);
CheckFunc(AAA, AA);

int main()
{
	cout << GetVal(10) << endl;
	cout << GetVal(10.3) << endl;

	std::vector<int> a{ 1,3,5,6,4 };

	cout << GetVal(a) << endl;

	



	getchar();
	return 0;
}

