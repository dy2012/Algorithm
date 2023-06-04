#include <iostream>
#include <pthread.h>
#include <thread>

using namespace std;

std::mutex mutex1;
std::condition_variable cv;

volatile int g_v = 0;

void printNum(int num, int thread_cnt, int nth) {
    for (int i = 1; i <= num; ++i) {
        std::unique_lock<std::mutex> lock(mutex1);
        while (g_v == 0) {
            cv.wait(lock);
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (i % 2 == 0) {
            cout << i << endl;
        }
        g_v = 1;
        cv.notify_all();
    }
}

void printNum2(int num, int thread_cnt, int nth) {
    for (int i = 1; i <= num; ++i) {
        std::unique_lock<std::mutex> lock(mutex1);
        while (g_v == 1) {
            cv.wait(lock);
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (i % 2 != 0) {
            cout << i << endl;
        }
        g_v = 0;
        cv.notify_all();
    }
}

int main(int argc, char* argv[]) {
    std::thread thread1(printNum, 100, 1, 1);
    std::thread thread2(printNum2, 100, 1, 1);
    thread1.join();
    thread2.join();
    return 0;
}
