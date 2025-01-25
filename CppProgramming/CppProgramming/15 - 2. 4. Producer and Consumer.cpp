#include <chrono>  // std::chrono::miliseconds
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

void producer(queue<std::string>* downloaded_pages, mutex* m,
    int index) {
    for (int i = 0; i < 5; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100 * index));
        std::string content = "웹사이트 : " + std::to_string(i) + " from thread(" +
            std::to_string(index) + ")\n";

        m->lock();
        downloaded_pages->push(content);
        m->unlock();
    }
}

void consumer(std::queue<std::string>* downloaded_pages, std::mutex* m,
    int* num_processed) {
    while (*num_processed < 25) {
        m->lock();
        if (downloaded_pages->empty()) {
            m->unlock();

            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            continue;
        }

        string content = downloaded_pages->front();
        downloaded_pages->pop();

        (*num_processed)++;
        m->unlock();

        cout << content;
        this_thread::sleep_for(std::chrono::milliseconds(80));
    }
}

int main() {
    queue<std::string> downloaded_pages;
    mutex m;

    vector<std::thread> producers;
    for (int i = 0; i < 5; i++) {
        producers.push_back(std::thread(producer, &downloaded_pages, &m, i + 1));
    }

    int num_processed = 0;
    vector<std::thread> consumers;
    for (int i = 0; i < 3; i++) {
        consumers.push_back(
            std::thread(consumer, &downloaded_pages, &m, &num_processed));
    }

    for (int i = 0; i < 5; i++) {
        producers[i].join();
    }
    for (int i = 0; i < 3; i++) {
        consumers[i].join();
    }
}