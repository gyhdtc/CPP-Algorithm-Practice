#include <iostream>
#include <string>
using namespace std;
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

void chuli(IP &ip) {
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

void get_10(IP &ip) {
    ip.x = 0;
    for (int i = 0; i < 4; i++) ip.x = ip.x * 256 + ip.a[i];
}

void swap(IP &ip1, IP &ip2) {
    IP t;
    t = ip1;
    ip1 = ip2;
    ip2 = t;
}

void std_out(IP ip) {
    cout << ip.a[0] << "." << ip.a[1] << "." << ip.a[2] << "." << ip.a[3] << "/" << ip.a[4] << endl;
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
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++) {
            if (ip[i].x > ip[j].x) swap(ip[i], ip[j]);
        }
    for (int i = 0; i < n; i++) {
        std_out(ip[i]);
    }
    return 0;
}