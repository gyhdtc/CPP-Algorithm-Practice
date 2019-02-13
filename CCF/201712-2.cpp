#include <iostream>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;

    int a[n] = {0};

    int num = n;
    int temp = 1;
    int p = 0;
    
    while (num != 1) {
        if (temp % k == 0) {
            temp++;
            a[p] = 1;
            num--;
            p = (p == n-1 ? 0 : p+1);
            while (a[p] == 1) {
                p = p == n-1 ? 0 : p+1;
            }
        }
        else {
            temp++;
            p = (p == n-1 ? 0 : p+1);
            while (a[p] == 1) {
                p = p == n-1 ? 0 : p+1;
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (a[i] == 0) {
            cout << i+1;
            break;
        }
    return 0;
}