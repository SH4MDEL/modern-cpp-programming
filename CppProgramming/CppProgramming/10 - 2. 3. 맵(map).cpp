#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(std::map<K, V>& m)
{
	for (const auto& elm : m) {
		std::cout << elm.first << ", " << elm.second << std::endl;
	}
}

int main()
{
	std::map<std::string, double> pitcher_list;

	pitcher_list.insert(std::make_pair<std::string, double>("¹Ú¼¼¿õ", 2.23));
	pitcher_list.insert(std::make_pair<std::string, double>("ÇØÄ¿", 2.93));
	pitcher_list.insert(std::make_pair<std::string, double>("ÇÇ¾î¹êµå", 2.95));

	pitcher_list.insert(std::make_pair("Â÷¿ìÂù", 3.04));
	pitcher_list.insert(std::make_pair("Àå¿øÁØ", 3.05));
	pitcher_list.insert(std::make_pair("ÇíÅÍ", 3.09));

	pitcher_list["´ÏÆÛÆ®"] = 3.56;
	pitcher_list["¹ÚÁ¾ÈÆ"] = 3.76;
	pitcher_list["ÄÌ¸®"] = 3.90;

	print_map(pitcher_list);
}