#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

struct player
{
    /* data */
    int id;
    int num;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        // set<int> allplayers;
        unordered_map<int, int> id2sc;
        set<int> id2liwu;
        int res = 0;
        int n;
        cin >> n;
        while (n--) {
            // 输入玩家 id 和 分数
            int flag = 0;
            player newplay;
            cin >> newplay.id >> newplay.num;
            // 新玩家直接接入，老玩家更新分数
            if (id2sc.count(newplay.id) == 0) {
                id2sc.insert({newplay.id, newplay.num});
            }
            else {
                // 分数低于旧分数，不更新
                if (newplay.num <= id2sc[newplay.id]) {
                    flag = 1;
                }
                else {
                    id2sc[newplay.id] = newplay.num;
                }
            }
            // 能加入排行榜才有奖励
            if (flag == 0) {
                // 排行榜
                vector<int> ph;
                for (auto i : id2sc) ph.push_back(i.second);
                sort(ph.begin(), ph.end());
                double zhongweishu = ph.size() % 2 == 0 ? (ph[ph.size()/2-1] + ph[ph.size()/2])/2 : ph[ph.size()/2];
                // 计算中位数
                if (zhongweishu == (double)newplay.num && id2liwu.count(newplay.id) == 0) {
                    res ++;
                    id2liwu.insert(newplay.id);
                }
            }
        }
        cout << res << endl;
    }
}