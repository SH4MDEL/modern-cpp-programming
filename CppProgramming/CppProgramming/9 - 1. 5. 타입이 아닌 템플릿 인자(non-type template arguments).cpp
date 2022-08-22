#include <iostream>
#include <array>

// 함수에 전달하기 위해선 그냥 std::array를 전달하면 안된다.
void print_array(std::array<int, 5>& _arr)
{
	for (int i = 0; i < _arr.size(); i++) {
		std::cout << _arr[i] << " ";
	}
	std::cout << std::endl;
}

// 물론 이렇게도 가능하다.
template <typename T>
void print_array(const T& _arr)
{
	for (int i = 0; i < _arr.size(); i++) {
		std::cout << _arr[i] << " ";
	}
	std::cout << std::endl;
}


// C에서 배열의 가장 큰 문제는 함수에 배열을 전달할 때 
// 배열의 크기에 대한 정보를 잃어버린다는 점이다.

int main()
{
	std::array<int, 5> arr = { 1, 2, 3, 4, 5 };
	std::array<int, 7> arr2 = { 1, 2, 3, 4, 5, 6, 7 };
	std::array<int, 3> arr3 = { 1, 2, 3 };

	print_array(arr);
	print_array(arr2);
	print_array(arr3);
}

// 이는 런타임에서 동적으로 크기가 할당되지 않는다.
// 배열 처럼 컴파일 시에 int 5개를 가지는 메모리를 가지고 스택에 할당된다.