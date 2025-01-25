#include <iostream>
#include <thread>

#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

void func1() {
    for (int i = 0; i < 10; ++i) {
        cout << "������ 1 �۵���" << endl;
    }
 }

void func2() {
    for (int i = 0; i < 10; ++i) {
        cout << "������ 2 �۵���" << endl;
    }
}

void func3() {
    for (int i = 0; i < 10; ++i) {
        cout << "������ 3 �۵���" << endl;
    }
}

int main()
{
    fastip; sws;

    thread t1(func1);
    thread t2(func2);
    thread t3(func3);

    t1.detach();
    t2.detach();
    t3.detach();
}