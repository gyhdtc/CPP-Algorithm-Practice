#include <iostream>
using namespace std;

int main(){
    int numB, L, T;
    int chu = 0;
    cin >> numB >> L >> T;
    int a[numB][2];
    for (int i = 0; i < numB; i++) {
        cin >> a[i][0];
        a[i][1] = 1; // 1 右 2 左
    }
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < numB; j++) {
            if (a[j][0] == 0) a[j][1] = 1;
            if (a[j][0] == L) a[j][1] = 2; 
        }
        for (int m = 0; m < numB-1; m++) {
            for (int n = m+1; n < numB; n++) {
                if (a[m][0] == a[n][0]) {
                    int temp = a[m][1];
                    a[m][1] = a[n][1];
                    a[n][1] = temp;
                }
            }
        }
        for (int j = 0; j < numB; j++) {
            if (a[j][1] == 1) a[j][0] ++;
            if (a[j][1] == 2) a[j][0] --;
        }
    }
    for (int i = 0; i < numB; i++) {
        cout << a[i][0];
        if (i != numB-1) cout << " ";
    }
    return 0;
}