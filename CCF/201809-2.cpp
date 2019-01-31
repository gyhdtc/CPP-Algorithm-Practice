#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int h[n][2], w[n][2];
    for (int i = 0; i < n; i++) cin >> h[i][0] >> h[i][1];
    for (int i = 0; i < n; i++) cin >> w[i][0] >> w[i][1];
    // 用两个人中最先完成得时间做数组长度没毛病吧
    int m = min(h[n-1][1], w[n-1][1]);
    int t[m];
    // 置 0
    for(int i = 0; i < m; i++){
        t[i] = 0;
    }
    // 统计时间
    for (int j = 0; j < n; j++) {
        for (int k = h[j][0]; k <= h[j][1]; k++) t[k]++;
        for (int k = w[j][0]; k <= w[j][1]; k++) t[k]++;
    }
    // 统计出现了多少个 2 ，表示重合的时间点
    int count = 0;
    for (int i = 0; i < m; i++) {
        if (t[i] == 2) count++;
    }
    // 统计出现了多少个重合时间段，因为 1 2 时间点重合，只交流了 1 秒，一个时间段有 n 个点重合，交流了 n-1 秒
    int s = 0;
    for (int i = 0; i < m; i++) {
        if (t[i] == 2) {
            while(t[i] == 2 && i < m) {
                i++;
            }
            s++;
        }
    }
    cout << count-s;
    return 0;
}