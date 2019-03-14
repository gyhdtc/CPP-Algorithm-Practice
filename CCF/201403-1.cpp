#include <iostream>
using namespace std;
int main(){
    int n, sum = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] + a[j] == 0) sum ++;
        }
    }
    cout << sum/2;
    return 0;
}