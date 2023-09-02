#include <iostream>
#include <list>
#include <array>
#include <algorithm>
using namespace std;

void Testint(int number)
{
	cout << number << endl;
}

template<typename T>	// �ڷ����� ������ �� ����.
void TestTemplate(T number)
{
	cout << number << endl;
}

// 1) Requires Clause(��)
template<typename T>
requires std::integral<T>
void TestConcept1(T number)
{
	cout << number << endl;
}

// 2) Trailing Requires Clause (�ڿ� �ٴ�-)
template<typename T>	// �ڷ����� ������ �� ����.
void TestConcept2(T number)	requires std::integral<T>
{
	cout << number << endl;
}

// 3) Constrained Template Parameter (�����)
template<std::integral T>	// �ڷ����� ������ �� ����.
void TestConcept3(T number) 
{
	cout << number << endl;
}

// 4) Abbreviated Function Template
void TestConcept4(std::integral auto number)
{
	cout << number << endl;
}

class Object
{
public:
	int id;
};

class Character : public Object
{

};

class Monster : public Object
{

};

template<typename T>
requires std::derived_from<T, Object>
void TestDerivedFrom(T object)
{
	cout << object.id << endl;
}

template<typename T, typename U>
requires std::random_access_iterator<T> and std::random_access_iterator<U>
void concept_sort(T begin, U end)
{
	sort(begin, end);
}

template<typename T>
concept MyConcept = !std::is_integral_v<T> and derived_from<T, Object>;

template<typename T>
concept Addable = requires(T a, T b)
{
	a + b;
}; // a + b�� �����ؾ� ��

template<typename T>
concept Equality = requires(T a, T b)
{
	{a == b} -> std::convertible_to<bool>;
	{a != b} -> std::convertible_to<bool>;
};

template<typename T>
concept Integral = std::is_integral_v<T>;

template<typename T>
concept SignedInt = Integral<T> and std::is_signed_v<T>;

int main()
{
	TestConcept4(3);

	constexpr bool check = _Is_any_of_v<int, short, float, long long>;

	Character character;
	character.id = 5;
	TestDerivedFrom(character);
	
	array<int, 3> a;
	concept_sort(a.begin(), a.end());

	list<int> l;
	//concept_sort(l.begin(), l.end());
}