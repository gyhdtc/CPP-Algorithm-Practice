#include <iostream>
using namespace std;
int main(){
    long long m, r, l;
    // m r l
    // Q = 998244353
    cin >> m >> r >> l;
    long long k[m+1];
    long long a[l+1] = {1};
    for (long long i = 1; i <= m; i++) cin >> k[i];
    for (long long i = 1; i <= l; i++) {
        long long t = i < m ? i : m; 
        a[i] = 0;
        for (long long j = 1; j <= t; j++) {
            a[i] += k[j] * a[i-j] % 998244353;
        }
    }
    for (long long i = r; i <= l; i++) cout << a[i] % 998244353 << endl;
    return 0;
}