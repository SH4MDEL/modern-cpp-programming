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
void is_exist(std::unordered_set<K>& s, K key)
{
	auto itr = s.find(key);
	if (itr != s.end()) {
		std::cout << key << " 가 존재" << std::endl;
	}
	else {
		std::cout << key << " 가 없다" << std::endl;
	}
}

template <typename K, typename V>
void print_unordered_map(const std::unordered_map<K, V>& m) {
	for (const auto& elm : m) {
		std::cout << elm.first << " " << elm.second << std::endl;
	}
}

int main()
{
	std::unordered_set<std::string> s;

	s.insert("hi");
	s.insert("my");
	s.insert("name");
	s.insert("is");
	s.insert("psi");
	s.insert("welcome");
	s.insert("to");
	s.insert("c++");

	print_unordered_set(s);
	is_exist(s, std::string("c++"));
	is_exist(s, std::string("c"));

	s.erase(s.find("hi"));
	is_exist(s, std::string("hi"));
}
