#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

template <typename K>
void print_unordered_set(const std::unordered_set<K>& s) {
	for (const auto& elm : s) {
		std::cout << elm << std::endl;
	}
}

template <typename K>
void is_exist(std::unordered_set<K>& s, K key) {
	auto itr = s.find(key);
	if (itr != s.end()) {
		std::cout << key << " 가 존재" << std::endl;
	}
	else {
		std::cout << key << " 가 없다" << std::endl;
	}
}

class Todo {
	int priority;
	std::string job_desc;

public:
	Todo(int priority, std::string job_desc)
		: priority(priority), job_desc(job_desc) {}

	bool operator==(const Todo& t) const {
		if (priority == t.priority && job_desc == t.job_desc) return true;
		return false;
	}

	friend std::ostream& operator<<(std::ostream& o, const Todo& t);
	friend struct std::hash<Todo>;
};

namespace std {
	template<>
	struct hash<Todo> {
		size_t operator()(const Todo& t) const {
			hash<string> hash_func;
			return t.priority ^ (hash_func(t.job_desc));
		}
	};
}
std::ostream& operator<<(std::ostream& o, const Todo& t) {
	o << "[중요도 : " << t.priority << "] " << t.job_desc;
	return o;
}

int main()
{
	std::unordered_set<Todo> todos;

	todos.insert(Todo(1, "농구 하기"));
	todos.insert(Todo(2, "수학 숙제 하기"));
	todos.insert(Todo(1, "프로그래밍 프로젝트"));
	todos.insert(Todo(3, "친구 만나기"));
	todos.insert(Todo(2, "영화 보기"));
	todos.insert(Todo(5, "일퀘 하기"));
	print_unordered_set(todos);
}