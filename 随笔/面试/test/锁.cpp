#include <thread>
#include <mutex>
#include <iostream>
using namespace std;

mutex g_mtx1;
mutex g_mtx2;
char c1 = 'A';
int a2 = 1;

void w1() {
    while (c1 <= 'Z') {
        g_mtx1.lock();
        cout << c1;
        ++c1;
        g_mtx2.unlock();
    }
}
void w2() {
    while (a2 <= 26) {
        g_mtx2.lock();
        cout << a2;
        ++a2;
        g_mtx1.unlock();
    }
}

int main() {
    g_mtx2.lock();
    thread t1(w1);
    thread t2(w2);
    t1.join();
    t2.join();
    return 0;
}