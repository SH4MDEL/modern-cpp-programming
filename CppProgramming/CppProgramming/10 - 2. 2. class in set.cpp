#include <iostream>
#include <set>
#include <string>

template <typename T>
void print_set(std::set<T>& s) {
	for (const auto& elem : s) {
		std::cout << elem << " " << std::endl;
	}
}

class Todo {
	int priority;
	std::string job_desc;

public:
	Todo(int priority, std::string job_desc) : priority(priority), job_desc(job_desc) {}

	// set은 내부적으로 정렬 시 상수 반복자를 사용하기 때문에
	// 상수 인자를 받는 상수 함수로 operator<를 선언해야 한다.
	bool operator<(const Todo& t) const {
		if (priority == t.priority) return job_desc < t.job_desc;
		return priority > t.priority;
	}
	friend std::ostream& operator<<(std::ostream& o, const Todo& td);
};

std::ostream& operator<<(std::ostream& o, const Todo& td) {
	o << "[ 중요도 : " << td.priority << "] " << td.job_desc;
	return o;
}

int main()
{
	std::set<Todo> todos;

	todos.insert(Todo(1, "농구 하기"));
	todos.insert(Todo(2, "수학 숙제 하기"));
	todos.insert(Todo(1, "프로그래밍 프로젝트"));
	todos.insert(Todo(3, "친구 만나기"));
	todos.insert(Todo(2, "영화 보기"));

	print_set(todos);

	std::cout << "영화 보기 끝" << std::endl;
	todos.erase(todos.find(Todo(2, "영화 보기")));
	print_set(todos);
}