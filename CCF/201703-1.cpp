#include <iostream>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int num = 0;
    int t = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum >= k) {
            sum = 0;
            num++;
        }
    }
    if (sum != 0) num++;
    cout << num;
    return 0;
}