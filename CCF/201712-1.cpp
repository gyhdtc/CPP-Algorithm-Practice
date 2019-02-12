#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int cha = -1;
    int cmin = 20000;
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            cha = a[i] < a[j]? a[j] - a[i] : a[i] - a[j];
            if (cha < cmin) cmin = cha;
            if (cmin == 0) {
                cout << cmin;
                return 0;
            }
        }
    }
    cout << cmin;
}