/*
输入描述:
第一行两个正整数，教授人数 n，以及认可关系总数 m ；
接下来 m 行，每行两个正整数 x 和 y，表示教授 x 认可教授 y（x , y可能相等且可能出现重复）

输出描述:
一行一个数字表示答案，即互相认可的教授有多少对。

输入例子1:
5 6
1 3
2 1
3 2
3 5
4 5
5 4
*/
/*
输入描述:
一行包括一个字符串。

输出描述:
一行包括一个字符串，代表答案。
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void dfs()

int main()
{
    int people;
    int guanxi;
    cin >> people >> guanxi;
    vector<vector<int>> a(people+1);
    vector<bool> onstack(people+1, false);
    while (guanxi--)
    {
        int i , j;
        cin >> i >> j;
        a[i].push_back(j);
    }
    int res = 0;
    dfs(res, a, onstack);
    return 0;
}