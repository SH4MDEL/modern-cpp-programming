#include <iostream>

class Date {
	int year_;
	int month_;
	int day_;

public:
	void ShowDate();

	Date() {
		std::cout << "�⺻ ������ ȣ��!" << std::endl;
		year_ = 2022;
		month_ = 1;
		day_ = 25;
	}

	Date(int year, int month, int day) {
		std::cout << "���� 3 ���� ������ ȣ��!" << std::endl;
		year_ = year;
		month_ = month;
		day_ = day;
	}
};

void Date::ShowDate() {
	std::cout << "������" << year_ << " �� " << month_ << " �� " << day_
		<< " �� �Դϴ�. " << std::endl;
}

int main()
{
	Date day = Date();
	Date day2(2012, 10, 31);

	day.ShowDate();
	day2.ShowDate();

	return 0;
}