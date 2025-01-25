#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

void worker(int& result, mutex& m)
{
    lock_guard<mutex> lock(m);

    for (int i = 0; i < 10000; ++i) {
        result += 1;
    }
}

int main()
{
    //fastip; sws;

    int counter = 0;
    mutex m;

    vector<thread> workers;
    for (int i = 0; i < 4; ++i) {
        workers.push_back(thread(worker, ref(counter), ref(m)));
    }

    for (int i = 0; i < 4; ++i) {
        workers[i].join();
    }

    cout << counter << endl;
}