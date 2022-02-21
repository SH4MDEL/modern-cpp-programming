#include <iostream>

// 추상 클래스
class Animal {
public:
	Animal() {}
	virtual ~Animal() {}
	virtual void speak() = 0;	
	// 순수 가상 함수를 한 개라도 포함하고 있는 클래스의 객체를 만들 수 없다.
};

class Dog : public Animal {
public:
	Dog() : Animal() {}
	~Dog() override { std::cout << "월..." << std::endl; }
	void speak() override { std::cout << "왈왈" << std::endl; }
};

class Cat : public Animal {
public:
	Cat() : Animal() {}
	~Cat() override { std::cout << "에..에옹..." << std::endl; }
	void speak() override { std::cout << "야옹야옹" << std::endl; }
};

int main()
{
	Animal* animal[2];
	animal[0] = new Dog();
	animal[1] = new Cat();

	for (int i = 0; i < 2; i++) {
		animal[i]->speak();
	}
	for (int i = 0; i < 2; i++) {
		delete animal[i];
	}
}