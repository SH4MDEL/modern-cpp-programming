#include <iostream>
#include <string>
#include <functional>

#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

class A {
    int c;

public:
    A(int c) : c(c) {}
    int some_func() {
        cout << "비상수 함수 : " << ++c << endl;
        return c;
    }

    int some_const_function() const {
        cout << "상수 함수 : " << c << endl;
        return c;
    }

    static void st() {}
};
int main()
{
    fastip; sws;

    A a(5);
    function<int(A&)> f1 = &A::some_func;
    function<int(const A&)> f2 = &A::some_const_function;

    f1(a);
    f2(a);
}