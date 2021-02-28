#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        a.push_back(0);
        cin >> a[i];
    }
    vector<int> b(n+1, 0);
    int mint = 0, minnum = 0;
    int maxt = 0, maxnum = 0;
    int amin = 0, amax = 0;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < 1) {
            mint += a[i];
            ++ minnum;
        }
        else if (a[i] > n) {
            maxt += a[i];
            ++ maxnum;
        }
        else b[a[i]] += 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (b[i] == 0) {
            if (minnum != 0) {
                amin += i;
                b[i] = 1;
                -- minnum;
            }
        }
    }
    for (int i = n; i >= 1; --i) {
        if (b[i] == 0) {
            if (maxnum != 0) {
                amax += i;
                b[i] = 1;
                -- maxnum;
            }
        }
    }
    res += maxt-mint+amin-amax;
    vector<int> duode;
    vector<int> quede;
    for (int i = 1; i <= n; ++i) {
        if (b[i] == 0) {
            quede.push_back(i);
        }
        else {
            while (b[i] != 1) {
                duode.push_back(i);
                -- b[i];
            }
        }
    }
    for (int i = 0; i < quede.size(); ++i) {
        res += abs(duode[i] - quede[i]);   
    }
    cout << res << endl;
}