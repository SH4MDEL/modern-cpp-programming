#include <iostream>

template <typename T>
void print(T arg)
{
	std::cout << arg << std::endl;
}

template <typename T, typename... Types>
// typename 뒤에 ... 으로 오는 것을 템플릿 파라미터 팩 이라고 부른다.
// 이는 0개 이상의 템플릿 인자들을 나타낸다.
void print(T arg, Types... args)
// 마찬가지로 함수에 인자로 ... 로 오는 것을 함수 파라미터 팩이라고 부른다.
{
	std::cout << arg << ", ";
	print(args...);
}

int main()
{
	print(1.1, 3.1, "abc");
	print(1, 2, 3, 4, 5, 6, 7);
}