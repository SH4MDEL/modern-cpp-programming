#include <iostream>

int& func1(int& a) { return a; }
int func2(int b) { return b; }

int main()
{
	int a = 3;
	int& l_a = a;		// 좌측값 레퍼런스 역시 좌측값.
	// int& r_b = 3;	// 안 된다.

	func1(a) = 4;
	std::cout << &func1(a) << std::endl;

	int b = 2;
	a = func2(b);
	// func2(b) = 5;	// 안 된다.
	// std::cout << &func2(b) << std::endl;
}