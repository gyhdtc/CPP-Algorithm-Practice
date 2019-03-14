#include <iostream>
using namespace std;
int main(){
    int n, t, num = 0;
    int a[10001];
    cin >> n;
    for (int i = 0; i < 10001; i++) a[i] = -1;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a[t] = 1;
    }
    for (int i = 0; i < 10000; i++) {
        if (a[i] == 1 && a[i+1] == 1) num++;
    }
    cout << num;
    return 0;
}