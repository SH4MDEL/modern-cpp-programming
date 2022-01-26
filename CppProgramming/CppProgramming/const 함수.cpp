#include <iostream>

class Marine {
	static int total_marine_num;
	const static int i = 0;

	int hp;
	int coord_x, coord_y;
	bool is_dead;

	const int default_damage;

public:
	Marine();
	Marine(int x, int y);
	Marine(int x, int y, int default_damage);

	int attack() const;	// 다른 변수의 값을 바꾸지 않는 함수
	Marine& be_attacked(int damage_earn);
	void move(int x, int y);

	void show_status();
	static void show_total_marine();
	~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine()
{
	std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}
Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) { total_marine_num++; }

Marine::Marine(int x, int y)
	: coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
	total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
	: coord_x(x), coord_y(y), hp(50), default_damage(default_damage), is_dead(false) {
	total_marine_num++;
}

void Marine::move(int x, int y)
{
	coord_x = x;
	coord_y = y;
}
int Marine::attack() const { return default_damage; }
Marine& Marine::be_attacked(int damage_earn) {
	this->hp -= damage_earn;
	if (this->hp <= 0) this->is_dead = true;

	return *this;
}
void Marine::show_status() {
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
		<< std::endl;
	std::cout << " HP : " << hp << std::endl;
	std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

int main()
{
	Marine* marines[100];

	marines[0] = new Marine(2, 3, 5);		// new는 객체를 동적으로 생성하면서 동시에 생성자도 호출해준다.
	marines[0]->show_status();

	marines[1] = new Marine(3, 5, 10);
	marines[1]->show_status();

	std::cout << std::endl << "마린 1 이 마린 2 를 두 번 공격! " << std::endl;
	marines[1]->be_attacked(marines[0]->attack()).be_attacked(marines[0]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	delete marines[0];
	delete marines[1];
}