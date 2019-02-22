#include <iostream>
#include <vector>
using namespace std;
struct gyh
{
    int num;
};

int main(){
    int n;
    int k;
    int p, q;
    cin >> n;
    vector<gyh> a(n);
    for (int i = 0; i < n; i++) a[i].num = i + 1;
    cin >> k;
    while (k--) {
        cin >> p >> q;
        int i;
        for (i = 0; i < n; i++) {
            if (a[i].num == p) break;
        }
        gyh t = a[i];
        a.erase(a.begin()+i);
        a.insert(a.begin()+i+q,t);
    }
    for (int i = 0; i < n; i++) cout << a[i].num << " ";
    return 0;
}