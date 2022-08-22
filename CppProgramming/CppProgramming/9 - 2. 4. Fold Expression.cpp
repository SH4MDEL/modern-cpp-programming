#include <iostream>

template <typename... Ints>
int sum_all(Ints... nums)
{
	// 반드시 ()를 fold 내에 포함시켜줘야 한다.
	return (... + nums);
}

template <typename Int, typename... Ints>
int diff_from(Int start, Ints... nums)
{
	return (start - ... - nums);
}

class A {
public:
	void do_something(int x) const {
		std::cout << "Do something with " << x << std::endl;
	}
};

template <typename T, typename... Ints>
void do_many_things(const T& t, Ints... nums)
{
	(t.do_something(nums), ...);
}

int main()
{
	std::cout << sum_all(1, 4, 2, 3, 10) << std::endl;
	std::cout << diff_from(100, 1, 4, 2, 3, 10) << std::endl;
	A a;
	do_many_things(a, 1, 2, 3, 4);
}