#include <iostream>
#include <string>
using namespace std;
/*
长度为 8 16 24 32 时可以不用写：
    1.2.3.0 = 1.2.3.0/32
    1.2.3   = 1.2.3.0/24
    1.2     = 1.2.0.0/16
    1       = 1.0.0.0/8
子网掩码位数规定了的一定要匹配到
*/
// 从下到大排列，IP地址第一，子网掩码第二
// ip地址集能够串一起就可以合并
int dianshu(string a) {
    int len = a.length();
    int rout = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] == '.') rout++;
    }
    return rout;
}
int xieshu(string a) {
    int len = a.length();
    int rout = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] == '/') rout++;
    }
    return rout;
}
void chuli(int ds, int xs, string s, int a[][5], int k) {
    // 对第k个进行字符串处理 写入到 a[k][4],获得了字符串s 他的点数，他的斜杠数
    //cout << ds << xs << s << k << endl;
    int h = 0;
    int i = 0;
    int sum = 0;
    if (xs == 1) {
        // 一定有斜杠
        for (i = 0; s[i] != '/'; i++) {
            if (s[i] != '.') sum = sum * 10 + s[i] - 48;
            else {
                a[k][h] = sum;
                sum = 0;
                h++;
            }
        }
        a[k][h] = sum;
        i++;
        sum = 0;
        for ( ; i < s.length(); i++) {
            sum = sum * 10 + s[i] - 48;
        }
        a[k][4] = sum;
    }
    else {
        // 没有斜杠
        for (i = 0; i < s.length(); i++) {
            if (s[i] != '.') sum = sum * 10 + s[i] - 48;
            else {
                a[k][h] = sum;
                sum = 0;
                h++;
            }
        }
        a[k][h] = sum;
        for (i = 0; i < 5; i++)
            if (a[k][i] != 0) a[k][4] += 8;
    }
}

int main()
{
    int n;
    cin >> n;
    string s[n];
    int a[n][5];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < 5; j++) a[i][j] = 0;
    }
    // 要开始判断是否有省略之类的输入
    // 得到 。 和 / 是否存在
    for (int i = 0; i < n; i++) {
        chuli(dianshu(s[i]), xieshu(s[i]), s[i], a, i);
        for (int j = 0; j < 5; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}