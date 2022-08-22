/* 컴파일 타임 팩토리얼 계산 */
#include <iostream>

template <int N>
struct Factorial {
	static const long long result = N * Factorial<N - 1>::result;
};

template <>
struct Factorial<1> {
	static const long long result = 1;
};

int main()
{
	std::cout << "6! = 1*2*3*4*5*6 = " << Factorial<20>::result << std::endl;
}