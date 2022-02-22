#include <iostream>
#include <string>

int main()
{
	int t;
	while (true) {
		std::cin >> t;
		std::cout << "입력 :: " << t << std::endl;
		if (std::cin.fail()) {
			std::cout << "int 자료형 내의 숫자를 입력해주세요. " << std::endl;
			std::cin.clear();				// 플래그를 초기화한다.
			std::cin.ignore(100, '\n');		// 개행문자가 나올 때 까지 무시한다.
		}
		if (t == 1) {
			break;
		}
	}
}