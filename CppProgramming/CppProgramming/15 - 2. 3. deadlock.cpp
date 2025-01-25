#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

void worker1(mutex& m1, mutex& m2)
{
    for (volatile int i = 0; i < 10000; ++i) {
        unique_lock<mutex> lock1(m1);
        unique_lock<mutex> lock2(m2);
    }
}

void worker2(mutex& m1, mutex& m2)
{
    for (volatile int i = 0; i < 10000; ++i) {
        unique_lock<mutex> lock2(m1);
        unique_lock<mutex> lock1(m2);
    }
}

int main()
{
    mutex m1, m2;

    thread t1(worker1, ref(m1), ref(m2));
    thread t2(worker2, ref(m1), ref(m2));

    t1.join();
    t2.join();

    cout << "Á¾·á" << endl;
}