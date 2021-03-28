#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
struct node {
    int num;
    int c;
};
int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<node> v;
    queue<node> q;
    unordered_map<int, int> ma;
    for (int i = 0; i < N; i++) {
        node a;
        cin >> a.num >> a.c;
        v.push_back(a);
        ma[a.num] = i;
    }
    q.push(v[0]);
    int m = v[0].c;
    for (int i = 1; i <= K; i++) {
        int len = q.size();
        if (len == 0) break;
        for (int i = 0; i < len; i++) {
            node x = q.front();
            q.pop();
            int k = x.num;
            if (m < x.c) m = x.c;
            for (int l = ma[k] + 1; l < N; l++) {
                if (k + M >= v[l].num) {
                    node y;
                    y.num = v[l].num;
                    y.c = x.c + v[l].c;
                    q.push(y);
                }
                else {
                    break;
                }
            }
        }
    }
    while (!q.empty()) {
        node y = q.front();
        if (m < y.c) m = y.c;
        q.pop();
    }
    cout << m << endl;
    return 0;
}