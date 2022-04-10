#include <iostream>
#include <set>
#include <string>

template <typename T>
void print_set(std::set<T>& s) {
	std::cout << "[ ";
	for (const auto& elem : s) {
		std::cout << elem << " ";
	}
	std::cout << "]" << std::endl;
}

class Todo {
	int priority;
	std::string job_desc;

public:
	Todo(int priority, std::string job_desc) : priority(priority), job_desc(job_desc) {}
	
};

int main()
{
	std::set<Todo> todos;

	todos.insert(Todo(1, "농구 하기"));
	todos.insert(Todo(2, "수학 숙제 하기"));
	todos.insert(Todo(1, "프로그래밍 프로젝트"));
	todos.insert(Todo(3, "친구 만나기"));
	todos.insert(Todo(2, "영화 보기"));
}