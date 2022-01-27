// 암시적으로 생성할 수 없게 만드는 키워드 : explicit
#include <iostream>
#include <string.h> // for strlen

class MyString {
	char* string_content;
	int string_length;
	int memory_capacity;

public:
	explicit MyString(int capacity);
	//MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str);

	~MyString();

	int length() const;
	
};

MyString::MyString(int capacity)
{
	string_content = new char[capacity];
	string_length = 0;
	memory_capacity = capacity;
	std::cout << "Capacity : " << capacity << std::endl;
}
//MyString::MyString(char c)
//{
//	string_content = new char[1];
//	string_content[0] = c;
//	memory_capacity = 1;
//	string_length = 1;
//}
MyString::MyString(const char* str)
{
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++) {
		string_content[i] = str[i];
	}
}
MyString::MyString(const MyString& str)
{
	string_length = str.string_length;
	memory_capacity = str.string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++) {
		string_content[i] = str.string_content[i];
	}
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void DoSomething(MyString s)
{
	return;
}

int main()
{
	//MyString s(3);
	//DoSomething(MyString("abc"));			// 가능
	//DoSomething("abc");					// 암시적 형변환을 통해 가능
	//DoSomething(3);						// 명백한 실수지만 암시적 형변환 실시
}