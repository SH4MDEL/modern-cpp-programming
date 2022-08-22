#include <iostream>
#include <array>

// �Լ��� �����ϱ� ���ؼ� �׳� std::array�� �����ϸ� �ȵȴ�.
void print_array(std::array<int, 5>& _arr)
{
	for (int i = 0; i < _arr.size(); i++) {
		std::cout << _arr[i] << " ";
	}
	std::cout << std::endl;
}

// ���� �̷��Ե� �����ϴ�.
template <typename T>
void print_array(const T& _arr)
{
	for (int i = 0; i < _arr.size(); i++) {
		std::cout << _arr[i] << " ";
	}
	std::cout << std::endl;
}


// C���� �迭�� ���� ū ������ �Լ��� �迭�� ������ �� 
// �迭�� ũ�⿡ ���� ������ �Ҿ�����ٴ� ���̴�.

int main()
{
	std::array<int, 5> arr = { 1, 2, 3, 4, 5 };
	std::array<int, 7> arr2 = { 1, 2, 3, 4, 5, 6, 7 };
	std::array<int, 3> arr3 = { 1, 2, 3 };

	print_array(arr);
	print_array(arr2);
	print_array(arr3);
}

// �̴� ��Ÿ�ӿ��� �������� ũ�Ⱑ �Ҵ���� �ʴ´�.
// �迭 ó�� ������ �ÿ� int 5���� ������ �޸𸮸� ������ ���ÿ� �Ҵ�ȴ�.