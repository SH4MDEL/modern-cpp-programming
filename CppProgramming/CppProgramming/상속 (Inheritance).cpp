#include <iostream>
#include <string>

class Base {
public:
	std::string parant_string;
	Base() : parant_string("기반") { std::cout << "기반 클래스" << std::endl; }

	void what() { std::cout << parant_string << std::endl; }
};
class Derived : private Base {					// private 선언
	std::string child_string;

public:
	Derived() : child_string("파생"), Base() {
		std::cout << "파생 클래스" << std::endl;
	}
};

int main()
{
	Base p;
	std::cout << p.parant_string << std::endl;		// 가능

	Derived c;
	//std::cout << c.parant_string << std::endl;	// 불가
	
	return 0;
}