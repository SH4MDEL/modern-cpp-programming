#include <iostream>

template <typename T>
void print(T arg)
{
	std::cout << arg << std::endl;
}

template <typename T, typename... Types>
// typename �ڿ� ... ���� ���� ���� ���ø� �Ķ���� �� �̶�� �θ���.
// �̴� 0�� �̻��� ���ø� ���ڵ��� ��Ÿ����.
void print(T arg, Types... args)
// ���������� �Լ��� ���ڷ� ... �� ���� ���� �Լ� �Ķ���� ���̶�� �θ���.
{
	std::cout << arg << ", ";
	print(args...);
}

int main()
{
	print(1.1, 3.1, "abc");
	print(1, 2, 3, 4, 5, 6, 7);
}