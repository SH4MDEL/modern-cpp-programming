#include <iostream>

class Int {
	int data;
	// some other data

public:
	Int(int data) : data(data) {}
	Int(const Int& i) : data(i.data) {}

	operator int() { return data; }
};

int main()
{
	Int a = 3;
	int b = 2;
	Int x = a + b;
	std::cout << x << std::endl;
}