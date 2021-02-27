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

bool huiwen(string shit)
{
    int len = shit.size();
    int i = 0, j = len - 1;
    while (i <= j)
    {
        if (shit[i] != shit[j]) return false;
        ++ i;
        -- j;
    }
    return true;
}
int main()
{
    string gyh;
    cin >> gyh;
    int index = 0;
    for (; index < gyh.size(); ++index)
    {
        if (huiwen(gyh.substr(index))) break;
    }
    for (int i = 0; i < gyh.size(); ++ i) cout << gyh[i];
    for (int i = index-1; i >= 0; -- i) cout << gyh[i];
    cout << endl;
    return 0;
}