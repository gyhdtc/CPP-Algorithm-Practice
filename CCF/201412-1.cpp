#include <iostream>
using namespace std;
int main(){
    int n, t;
    cin >> n;
    int a[n+1] = {0};
    for (int i = 0; i < n; i++) {
        cin >> t;
        a[t]++;
        cout << a[t] << " ";
    }
    // cin >> t;
    // a[t]++;
    // cout << a[t];
    return 0;
}