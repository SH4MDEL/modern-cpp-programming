#include <iostream>
#include <set>
#include <map>
#include <string>

template <typename K>
void print_set(const std::multiset<K>& s) {
	for (const auto& elm : s) {
		std::cout << elm << std::endl;
	}
}

template <typename K, typename V>
void print_map(const std::multimap<K, V>& m) {
	for (const auto& elm : m) {
		std::cout << elm.first << " " << elm.second << std::endl;
	}
}

int main()
{
	std::multiset<std::string> s;

	s.insert("a");
	s.insert("b");
	s.insert("c");
	s.insert("a");
	s.insert("b");
	s.insert("d");

	print_set(s);

	std::multimap<int, std::string> m;

	m.insert({ 1, "a" });
	m.insert({ 2, "b" });
	m.insert({ 1, "c" });
	m.insert({ 3, "a" });
	m.insert({ 4, "b" });
	m.insert({ 1, "d" });

	print_map(m);

	std::cout << "----------------" << std::endl;
	std::cout << m.find(1)->second << std::endl;

	auto range = m.equal_range(1);

	for (auto itr = range.first; itr != range.second; ++itr) {
		std::cout << itr->first << " : " << itr->second << std::endl;
	}
}