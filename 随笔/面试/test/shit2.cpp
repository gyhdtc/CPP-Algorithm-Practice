
#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;
struct node
{
    int index;
    int num;
};
bool comparison(node a, node b) {
    return a.num < b.num;
}
int main() {
    int n;
    cin >> n;
    vector<node> a;
    set<int> h;
    for (int index = 1; index <= n; index++) {
        int t;
        cin >> t;
        for (int i = 0; i < t; ++i) {
            node shit;
            shit.index = index;
            cin >> shit.num;
            a.push_back(shit);
        }
    }
    sort(a.begin(), a.end(), comparison);
    // for (int i = 0; i < a.size(); i++) {
    //     cout << a[i].num << endl;
    // }
    
    int q;
    cin >> q;
    while (q--) {
        int gyh;
        cin >> gyh;
        while (gyh--) {
            int t2;
            cin >> t2;
            h.insert(t2);
        }
        int xiao;
        cin >> xiao;
        int k = 0;
        for (int i = 0; i < a.size(); ++i) {
            // cout << "-----------------------\n";
            if (h.count(a[i].index) == 1)
                k++;
            if (k == xiao) {
                // cout << "-----------------------" << a[i].num << endl;
                cout << a[i].num << endl;
                break;
            }
        }
        h.clear();
    }
}