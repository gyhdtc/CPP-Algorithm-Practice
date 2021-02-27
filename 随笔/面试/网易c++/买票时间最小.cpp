/*
第一行输入一个整数 T，接下来有 T 组测试数据。

对于每一组测试数据：输入一个数 n，代表有 n 个人买票。

接下来n个数，代表每一个人单独买票的时间 a[i]。

接下来 n-1 个数，代表每一个人和他前面那个人一起买票需要的时间 b[i]
1<= T <=100
1<= n <=2000
1<= a[i] <=50
1<= b[i] <=50
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
void dfs(int& res, int sumtime,  int i, int num, vector<int>& one, vector<int>& two)
{
    if (i >= num)
    {
        res = min(res, sumtime);
        return;
    }
    dfs(res, sumtime+one[i], i+1, num, one, two);
    if (i <= num-2) dfs(res, sumtime+two[i], i+2, num, one, two);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int time = 0;
        vector<int> one(n, 0);
        vector<int> two(n-1, 0);

        for (int i = 0; i < n; ++i)
        {
            cin >> one[i];
            time += one[i];
        }
        for (int i = 0; i < n-1; ++i)
        {
            cin >> two[i];
        }
        vector<int> res(n, 0);
        switch (n)
        {
        case 1:
            time = one[0];
            break;
        case 2:
            time = min(one[0]+one[1], two[0]);
            break;
        default:
            res[0] = one[0];
            res[1] = min(one[0]+one[1], two[0]);
            for (int i = 2; i < n; ++ i)
            {
                res[i] = min(res[i-1]+one[i], res[i-2]+two[i-1]);
            }
            break;
        }
        time = res[n-1];
        int hour = ( int(time/3600) )%24;
        int min = ((time - hour * 3600)/60)%60;
        int miao = (time - hour * 3600 - min * 60);
        string flag = (hour+8) >= 12 ? "pm" : "am";
        printf("%02d:%02d:%02d %s\n", hour+8, min, miao, flag.c_str());
    }
}