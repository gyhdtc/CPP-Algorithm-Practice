/*
第一行输入一个整数 T，代表有 T 组测试数据。

对于每一组测试数据，一行输入一个整数 n ，代表物品的个数。

接下来 n 个数，a[i] 代表每一个物品的价值。

1<= T <= 10
1 <= n <= 15
1 <= a[i] <= 100000
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void out(vector<int>& a)
{
    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void dfs(int& res, int h1, int h2, int start, int sum, vector<int>& nums)
{
    if (h1 == h2) res = min(res, sum - h1- h2);
    if (start == nums.size()) return;
    dfs(res, h1+nums[start], h2, start+1, sum, nums);
    dfs(res, h1, h2+nums[start], start+1, sum, nums);
    dfs(res, h1, h2, start+1, sum, nums);
}
int main() 
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int res = 0;
        int sum = 0;
        vector<int> shit(n, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> shit[i];
            sum += shit[i];
        }
        // sort(shit.begin(), shit.end());
        // out(shit);
        res = sum;
        dfs(res, 0, 0, 0, sum, shit);
        cout << res << endl;
    }
}