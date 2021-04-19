#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        string hand;
        // 输入
        cin >> n >> m;
        cin >> hand;
        // 遍历每一个位置
        int res = 0;
        for (int i = 0; i < n; i++) {

            string t = hand;
            int a = m;
            int cur = i;
            int next;
            
            // m次猜拳
            while (a--) {
                if (t.size() == 1) break;
                if (cur == t.size()-1) next = 0;
                else next = cur + 1;
                // 比较
                // 第一个 win
                // cout << cur << " --- " << next << endl;
                if ( (t[cur] == 'R' && t[next] == 'S') || (t[cur] == 'S' && t[next] == 'C') || (t[cur] == 'C' && t[next] == 'R') ) {
                    t.erase(next, 1);
                    if (cur > t.size()-1) cur = t.size()-1;
                }
                // 第二个 win
                else if ( (t[cur] == 'S' && t[next] == 'R') || (t[cur] == 'C' && t[next] == 'S') || (t[cur] == 'R' && t[next] == 'C') ) {
                    t.erase(cur, 1);
                    // 删除了 cur ，cur就指向了 next
                    if (next == 0)
                        cur = next;
                    else
                        cur = next-1;
                    
                }
                // 平手
                else {
                    cur = next;
                }
            }
            res = res < t.size() ? t.size() : res;
        }
        cout << res << endl;
    }
}