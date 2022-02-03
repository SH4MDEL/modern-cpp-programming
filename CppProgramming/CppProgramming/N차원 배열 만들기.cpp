#include <iostream>

class Array {
	const int dim;		// 몇 차원 배열인가
	int* size;

	struct Address {
		int level;
		// 맨 마지막 레벨(dim - 1 레벨)은 데이터 배열을 가리키고, 그 위 상위
		// 레벨에서는 다음 Address 배열을 가리킨다.
		void* next;
	};
	Address* top;

public:
	Array(int dim, int* array_size) : dim(dim) {
		size = new int[dim];
		for (int i = 0; i < dim; i++) size[i] = array_size[i];

		top = new Address;
		top->level = 0;
	}
};