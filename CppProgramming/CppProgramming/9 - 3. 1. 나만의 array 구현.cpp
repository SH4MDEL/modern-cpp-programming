#include <iostream>

template <typename T, unsigned int N>
class Array {
	T data[N];

public:
	// 배열을 받는 레퍼런스 arr
	Array(T(&arr)[N]) {
		for (int i = 0; i < N; i++) {
			data[i] = arr[i];
		}
	}

	T* get_array() { return data; }

	unsigned int size() { return N; }

	void print_all() {
		for (int i = 0; i < N; i++) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
};

int main()
{
	int arr[3] = { 1, 2, 3 };

	// 배열 wrapper 클래스
	Array<int, 3> arr_w(arr);

	arr_w.print_all();
}