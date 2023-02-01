#include <iostream>

#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

struct S {
    void operator()(int a, int b) { cout << "a + b : " << a + b << endl; }
};

int main()
{
    fastip; sws;

    S s;

    s(3, 5);
}