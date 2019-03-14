#include <iostream>
using namespace std;
int main(){
    int n;
    int max = 0;
    int index = 0;
    int a[10001] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a[t]++;
    }
    for (int i = 0; i < 10001; i++) {
        if (a[i] > index) {
            max = i;
            index = a[i];
        }
        if (a[i] == index && max > i) {
            max = i;
            index = a[i];
        }
    }
    cout << max;
    return 0;
}