#include <string>
#include <iostream>

int main()
{
	int t;
	while (true) {
		// std::cin >> std::hex >> t;
		std::cin.setf(std::ios_base::hex, std::ios_base::basefield);

		// std::hex와 같이 스트림을 조작하여 입력 또는 출력 방식을 바꿔주는 함수를 조작자라고 한다.
		// 반면 형식 플래그 std::ios_base::hex는 상수이다.


		std::cin >> t;
		std::cout << "입력 :: " << t << std::endl;
		if (std::cin.fail()) {
			std::cout << "제대로 입력해주세요. " << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		if (t == 0) break;
	}
}