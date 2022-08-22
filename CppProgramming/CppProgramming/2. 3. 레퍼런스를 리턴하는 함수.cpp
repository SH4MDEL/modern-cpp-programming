#include <iostream>

int& function() {
	int a = 5;
	return a;
}

int main()
{
	int& c = function();
	std::cout << c << std::endl;
	return 0;
}