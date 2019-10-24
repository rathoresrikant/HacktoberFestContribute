#include <iostream>
#include <thread>
#include <mutex>

int sum = 0;
std::mutex m;

void add(int num) {
    m.lock();
    sum += num;
    m.unlock();
}

int main() {
    const int NO_THREADS = 200;
    std::thread *threads[NO_THREADS];

    for (auto &th : threads)
        th = new std::thread(add, 20);

    for (auto &th : threads)
        th->join();

    for (auto &th : threads)
        delete th;

    std::cout << sum << '\n';

    return 0;
}