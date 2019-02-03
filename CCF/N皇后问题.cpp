#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;
#define N 1000
bool flagTable[N];// 第n列有没有
int P[N];// 第N个在P[n]列
int count = 0;

void generateP(int index, int n){ // index 行
    if (index == n + 1) {
        count ++;
        return;
    }
    for (int x = 1; x <= n; x++) { // 列
        if (flagTable[x] == false) {
            bool flag = true;
            for (int pre = 1; pre < index; pre++) { // 行
                if (abs(index - pre) == abs(x - P[pre])) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                P[index] = x;
                flagTable[x] = true;
                generateP(index+1, n);
                flagTable[x] = false;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        flagTable[i] = false;
        P[i] = 0;
    }
    generateP(1, n);
    printf("%d\n", count);
    return 0;
}