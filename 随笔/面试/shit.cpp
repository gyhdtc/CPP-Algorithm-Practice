#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bianjijuli(string a, string b) {
    int n = a.size()+1;
    int m = b.size()+1;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 0;
    for (int i = 1; i < n; i++) dp[i][0] = i;
    for (int j = 1; j < m; j++) dp[0][j] = j;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1]+1, dp[i-1][j]+1));
            }
            else {
                dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i][j-1]+1, dp[i-1][j]+1));
            }
        }
    }
    for (auto i : dp) {
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return dp[n-1][m-1];
}

int main() {
    string a, b;
    while (cin >> a >> b) {
        cout << bianjijuli(b, a) << endl;
    }
    return 0;
}