#include <iostream>
#include <deque>

template <typename T>
void print_deque(std::deque<T>& dq) {
	std::cout << "[ ";
	// 전체 덱을 출력하기
	for (const auto& elem : dq) {
		std::cout << elem << " ";
	}
	std::cout << "]";
}

int main()
{
	std::deque<int> dq;
	dq.push_back(10);
	dq.push_back(20);
	dq.push_front(30);
	dq.push_front(40);

	std::cout << "초기 dq 상태 : ";
	print_deque(dq);
	std::cout << std::endl << "맨 앞의 원소 제거" << std::endl;
	dq.pop_front();
	print_deque(dq);
}