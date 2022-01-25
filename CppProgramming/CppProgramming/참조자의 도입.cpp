#include <iostream>

int change_val(int* p) {
	*p = 3;

	return 0;
}

int change_val_by_reference(int& p) {
	p = 3;

	return 0;
}

int main()
{
	int number = 5;

	std::cout << number << std::endl;
	change_val(&number);
	std::cout << number << std::endl;


	int a = 3;
	int& another_a = a;

	another_a = 5;
	std::cout << "a : " << a << std::endl;
	std::cout << "another_a : " << another_a << std::endl;


	number = 5;

	std::cout << number << std::endl;
	change_val_by_reference(number);
	std::cout << number << std::endl;

	return 0;
}