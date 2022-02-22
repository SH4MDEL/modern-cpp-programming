// istream을 상속 받은 것이 ifstream
// ostream을 상속 받은 것이 ofstream
// 이를 모두 포함하는 것이 fstream
#include <fstream>
#include <iostream>
#include <string>

int main()
{
	//파일 읽기 준비
	std::fstream in("test.txt");
	std::string s;

	if (in.is_open()) {
		in >> s;
		std::cout << "입력 받은 문자열 :: " << s << std::endl;
	}
	else {
		std::cout << "파일을 찾을 수 없습니다. " << std::endl;
	}
	// fclose()와 같은 함수는 필요 없는가? 그렇다.
	// ifstream 객체의 소멸자에서 자동으로 close를 해준다.

	//////////////////////////////////////////////////////////////
	in.close();
	in.open("other.txt");
	if (in.is_open()) {
		in >> s;
		std::cout << "입력 받은 문자열 :: " << s << std::endl;
	}
	else {
		std::cout << "파일을 찾을 수 없습니다. " << std::endl;
	}
	// 다만 이와 같이 같은 객체가 입력을 받기 위해서는 기존 파일 스트림과의 연결을 종료하고
	// 새로운 파일과 연결을 시켜줘야 한다.
}