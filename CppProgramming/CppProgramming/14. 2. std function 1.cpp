#include <iostream>
#include <string>
#include <functional>

#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int some_func1(const string& s) {
    cout << "Func1 ȣ�� " << s << endl;
    return 0;
}

struct S {
    void operator()(char c) { cout << "Func2 ȣ�� " << c << endl; }
};

int main()
{
    fastip; sws;

    function<int(const string& s)> f1 = some_func1;
    function<void(char c)> f2 = S();
    function<void(void)> f3 = []() {cout << "Func3 ȣ�� " << endl; };

    f1("asdf");
    f2('c');
    f3();
}