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
typedef struct
{
    string s;
    int a[5] = {0};
    int ds;
    int xs;
    long int x;
}IP;

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

void chuli(IP ip) {
    int h = 0;
    int i = 0;
    int sum = 0;
    if (ip.xs == 1) {
        // 一定有斜杠
        for (i = 0; ip.s[i] != '/'; i++) {
            if (ip.s[i] != '.') sum = sum * 10 + ip.s[i] - 48;
            else {
                ip.a[h] = sum;
                sum = 0;
                h++;
            }
        }
        ip.a[h] = sum;
        i++;
        sum = 0;
        for ( ; i < ip.s.length(); i++) {
            sum = sum * 10 + ip.s[i] - 48;
        }
        ip.a[4] = sum;
    }
    else {
        // 没有斜杠
        for (i = 0; i < ip.s.length(); i++) {
            if (ip.s[i] != '.') sum = sum * 10 + ip.s[i] - 48;
            else {
                ip.a[h] = sum;
                sum = 0;
                h++;
            }
        }
        ip.a[h] = sum;
        for (i = 0; i < 4; i++)
            if (ip.a[i] != 0) ip.a[4] += 8;
    }
}

void get_10(IP ip) {
    for (int i = 0; i < 4; i++) ip.x = ip.x * 256 + ip.a[i];
}

int main()
{
    int n;
    cin >> n;
    IP ip[n];
    for (int i = 0; i < n; i++) {
        cin >> ip[i].s;
        ip[i].ds = dianshu(ip[i].s);
        ip[i].xs = xieshu (ip[i].s);
        chuli(ip[i]);
        get_10(ip[i]);
    }

    return 0;
}