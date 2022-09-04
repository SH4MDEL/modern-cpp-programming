#include <iostream>
#include <cstring>

class A {
	int data_;

public:
	A(int data) : data_(data) { std::cout << "�Ϲ� ������ ȣ��!" << std::endl; }

	A(const A& a) : data_(a.data_) {
		std::cout << "���� ������ ȣ��!" << std::endl;
	}
};

class MyString {
	char* string_content;
	int string_length;

	int memory_capacity;

public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& str);

	~MyString();

	int length() const;
	int capacity();
	void reserve(int size);
	MyString operator+(const MyString& s);

	void print() const;
	void println() const;

	MyString& assign(const MyString& str);
	MyString& assign(const char* str);

	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);

	MyString& erase(int loc, int num);

	int find(int find_from, MyString& str) const;
	int find(int find_from, const char* str) const;
	int find(int find_from, char c) const;

	int compare(const MyString& str) const;

	char at(int i) const;

	bool operator==(MyString& str);

	char& operator[](const int index);

	friend std::ostream& operator<<(std::ostream& os, const MyString& str);
};

MyString::MyString()
{
	std::cout << "������ ȣ�� !" << std::endl;
	string_content = nullptr;
	memory_capacity = 0;
	string_length = 0;
}
MyString::MyString(const char* str)
{
	std::cout << "������ ȣ�� !" << std::endl;
	string_length = (int)strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++) {
		string_content[i] = str[i];
	}
}
MyString::MyString(const MyString& str)
{
	std::cout << "���� ������ ȣ�� !" << std::endl;
	string_length = str.string_length;
	memory_capacity = str.string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++) {
		string_content[i] = str.string_content[i];
	}
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void MyString::print() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
}
void MyString::println() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
	std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str)
{
	if (str.string_length > memory_capacity) {
		delete[] string_content;

		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	for (int i = 0; i != str.string_length; i++) {
		string_content[i] = str.string_content[i];
	}
	string_length = str.string_length;

	return *this;
}
MyString& MyString::assign(const char* str)
{
	int str_length = (int)strlen(str);
	if (str_length > memory_capacity) {
		delete[] string_content;

		string_content = new char[str_length];
		memory_capacity = str_length;
	}
	for (int i = 0; i != str_length; i++) {
		string_content[i] = str[i];
	}
	string_length = str_length;

	return *this;
}

int MyString::capacity() { return memory_capacity; }
void MyString::reserve(int size)
{
	if (size > memory_capacity) {
		char* prev_string_content = string_content;

		string_content = new char[size];
		memory_capacity = size;

		for (int i = 0; i != string_length; i++) {
			string_content[i] = prev_string_content[i];
		}

		delete[] prev_string_content;
	}
}

MyString MyString::operator+(const MyString& s)
{
	MyString str;
	str.reserve(string_length + s.string_length);
	for (int i = 0; i < string_length; ++i) {
		str.string_content[i] = string_content[i];
	}
	for (int i = 0; i < s.string_length; ++i) {
		str.string_content[string_length + i] = s.string_content[i];
	}
	str.string_length = string_length + s.string_length;
	return str;
}

char MyString::at(int i) const
{
	if (i >= string_length || i < 0) {
		return NULL;
	}
	else {
		return string_content[i];
	}
}

MyString& MyString::insert(int loc, const MyString& str)
{
	if (loc < 0 || loc > string_length) return *this;

	if (string_length + str.string_length > memory_capacity) {
		if (memory_capacity * 2 > string_length + str.string_length) {
			memory_capacity *= 2;
		}
		else {
			memory_capacity = string_length + str.string_length;
		}

		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];

		int i;
		for (i = 0; i < loc; i++) {
			string_content[i] = prev_string_content[i];
		}

		for (int j = 0; j != str.string_length; j++) {
			string_content[i + j] = str.string_content[j];
		}

		for (; i < string_length; i++) {
			string_content[str.string_length + i] = prev_string_content[i];
		}

		delete[] prev_string_content;

		string_length = string_length + str.string_length;
		return *this;
	}

	for (int i = string_length - 1; i >= loc; i--) {
		string_content[i + str.string_length] = string_content[i];
	}
	for (int i = 0; i < str.string_length; i++) {
		string_content[i + loc] = str.string_content[i];
	}
	string_length = string_length + str.string_length;
	return *this;
}
MyString& MyString::insert(int loc, const char* str)
{
	MyString temp(str);
	return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num)
{
	if (num < 0 || loc < 0 || loc > string_length) return *this;

	for (int i = loc + num; i < string_length; i++) {
		string_content[i - num] = string_content[i];
	}

	string_length -= num;
	return *this;
}

int MyString::find(int find_from, MyString& str) const
{
	int i, j;
	if (str.string_length == 0) return -1;
	for (i = find_from; i <= string_length - str.string_length; i++) {
		for (j = 0; j < str.string_length; j++) {
			if (string_content[i + j] != str.string_content[j]) break;
		}
		if (j == str.string_length) return i;
	}
	return -1;
}
int MyString::find(int find_from, const char* str) const
{
	MyString temp(str);
	return find(find_from, temp);
}

int MyString::compare(const MyString& str) const
{
	for (int i = 0; i < std::min(string_length, str.string_length); i++) {
		if (string_content[i] > str.string_content[i]) {
			return 1;
		}
		else if (string_content[i] < str.string_content[i]) {
			return -1;
		}
	}

	if (string_length == str.string_length) return 0;
	else if (string_length > str.string_length) return 1;
	return -1;
}

bool MyString::operator==(MyString& str)
{
	return !compare(str);
}

char& MyString::operator[](const int index)
{
	return string_content[index];
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	for (int i = 0; i != str.string_length; i++) {
		os << str.string_content[i];
	}
	return os;
}

int main()
{
	A a(1);
	A b(a);

	std::cout << "-------------------------" << std::endl;

	A c(A(2));

	std::cout << "-------------------------" << std::endl;

	MyString str1("abcdef");
	MyString str2("ghi");
	std::cout << "-------------------------" << std::endl;
	MyString str3 = str1 + str2;
	str3.println();
}