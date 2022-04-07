#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
	// 전체 벡터를 출력하기
	std::cout << "[ ";
	// iterator는 포인터가 아니다. * 연산자를 오버로딩해서 포인터처럼 동작하게 하는 것.
	for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		// typename을 붙이는 이유는 iterator가 std::vector<>의 의존 타입이기 때문
		std::cout << *itr << " ";
	}
	std::cout << "]";
}

int main()
{
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	std::cout << "처음 벡터 상태" << std::endl;
	print_vector(vec);

	std::vector<int>::reverse_iterator r_iter = vec.rbegin();
	for (; r_iter != vec.rend(); ++r_iter) {
		std::cout << *r_iter << std::endl;
	}
}