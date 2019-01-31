#include <iostream>
#include <algorithm>
using namespace std;
int t[1000000] = {0};
int main()
{
    int n;
    cin >> n;
    int h[n][2], w[n][2];
    for (int i = 0; i < n; i++) cin >> h[i][0] >> h[i][1];
    for (int i = 0; i < n; i++) cin >> w[i][0] >> w[i][1];
    
    int m = min(h[n-1][1], w[n-1][1]);
    
    // 标记时间段 如果是 1 2， 就要标记 t[1]++
    for (int i = 0; i < n; i++) {
        for (int k = h[i][0]; k < h[i][1]; k++) t[k]++;
        for (int k = w[i][0]; k < w[i][1]; k++) t[k]++;
    }
    // 统计出现了多少个 2 ，表示重合的时间段
    int count = 0;
    for (int i = 0; i < m; i++) {
        if (t[i] > 1) count++;
    }
    cout << count;
    return 0;
}