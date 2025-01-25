#include <iostream>
#include <thread>
#include <vector>

#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

void worker(vector<int>::iterator start, vector<int>::iterator end, int* result)
{
    int sum = 0;
    for (auto itr = start; itr < end; ++itr) {
        sum += *itr;
    }
    *result = sum;

    thread::id this_id = this_thread::get_id();
    printf("쓰레드 %x 에서 %d 부터 %d 까지 계산한 결과 : %d \n", 
        this_id, *start, *(end - 1), sum);
}

int main()
{
    //fastip; sws;

    vector<int> datas(10000);
    for (int i = 0; auto & data : datas) {
        data = i++;
    }

    vector<int> partial_sums(4);

    vector<thread> workers;
    for (int i = 0; i < 4; i++) {
        workers.emplace_back(worker, datas.begin() + i * 2500,
            datas.begin() + (i + 1) * 2500, &partial_sums[i]);
    }

    for (int i = 0; i < 4; i++) {
        workers[i].join();
    }

    int total = 0;
    for (int i = 0; i < 4; i++) {
        total += partial_sums[i];
    }
    std::cout << "전체 합 : " << total << endl;
}