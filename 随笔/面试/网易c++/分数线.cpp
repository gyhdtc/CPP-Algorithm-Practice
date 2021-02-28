#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int t, x, y;
    vector<int> a;
    cin >> t >> x >> y;
    for (int i = 0; i < t; ++i) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    if (!(y*2 >= t && x*2 <= t))
        cout << -1 << endl;
    else{
        int i;
        for (i = 0; i < t-1; ++i) {
            if (a[i] < a[i+1] && ((i+1)>=x && (i+1)<=y) && (t-i-1)>=x && (t-i-1)<=y) {
                cout << a[i] << endl;
                break;
            }
            if (a[i] == a[i+1])
                continue; 
        }
        if (i == t-1)
            cout << -1 << endl;
    }
}