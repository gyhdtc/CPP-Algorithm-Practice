#include <iostream>
#include <vector>
using namespace std;

int compare(vector<int>& a, vector<int>& b) {
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) continue;
        else if (abs(a[i] - b[i]) == 1 ) res++;
        else return a.size()+1;
    }
    return res;
}
vector<int> getdengcha(int a, int b, int cha, int n) {
    vector<int> c(n);
    for (int i = 0; i < n; i++) c[i] = a - i * cha;
    return c;
}
int main() {
    int n;
    cin >> n;
    int res = n+1;
    vector<int> a(n);
    int z[3] = {-1, 0, +1};
    for (int i = 0; i < n; i++) cin >> a[i];
    if ((abs(a[n-1] - a[0]) + 2)%(n-1) != 0 && 
    (abs(a[n-1] - a[0]) - 2)%(n-1) != 0 && 
    (abs(a[n-1] - a[0]) + 1)%(n-1) != 0 && 
    (abs(a[n-1] - a[0]) - 1)%(n-1) != 0 && 
    (abs(a[n-1] - a[0]))%(n-1) != 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            vector<int> c(n);
            if ((a[0]+z[i] - a[n-1]-z[j])%(n-1) == 0) {
                c = getdengcha(a[0]+z[i], a[n-1]+z[j], (a[0]+z[i] - a[n-1]-z[j])/(n-1), n);
                res = min(compare(a, c), res);
            }
        }
    }
    if (res != n+1) cout << res << endl;
    else cout << -1 << endl;
    return 0;
}