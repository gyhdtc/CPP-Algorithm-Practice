#include <iostream>
using namespace std;
unsigned long long fbnq(int n) {
    unsigned long long num1 = 1;
    unsigned long long num2 = 1;
    if (n < 1) return -1;
    if (n == 1 || n == 2) return 1;
    n = n - 2;
    while (n--) {
        unsigned long long t = num2;
        num2 = num1 + num2;
        num1 = t;
    }
    return num2;
}
int main() {
    int n;
    cout << fbnq(10) << endl;
    cout << fbnq(100) << endl;
    cout << fbnq(1000) << endl;
    cout << fbnq(10000) << endl;
}