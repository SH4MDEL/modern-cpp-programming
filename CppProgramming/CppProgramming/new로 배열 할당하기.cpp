#include <iostream>

using std::cout;
using std::cin;

int main()
{
	int arr_size;
	cout << "array size : ";
	cin >> arr_size;
	int* list = new int[arr_size];
	for (int i = 0; i < arr_size; i++) {
		cin >> list[i];
	}
	for (int i = 0; i < arr_size; i++) {
		if (i == 1) {
			cout << i << "st element of list : " << list[i] << std::endl;
		}
		else if (i == 2) {
			cout << i << "ed element of list : " << list[i] << std::endl;
		}
		else if (i == 3) {
			cout << i << "rd element of list : " << list[i] << std::endl;
		}
		else {
			cout << i << "th element of list : " << list[i] << std::endl;
		}
	}
	delete[] list;
	return 0;
}