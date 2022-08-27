#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

class Todo {
	int priority;
	std::string job_desc;

public:
	Todo(int priority, std::string job_desc)
		: priority(priority), job_desc(job_desc) {}
};

