#include <iostream>
using namespace std;
int r, y, g;
int a[200000][2];
void gengxin(int j, int t) {
    if (a[j][1] > t) a[j][1] -= t;
    else 
    {    
        int temp = t;
        temp = (t - a[j][1]) % (r + y + g);
        switch (a[j][0])
        {
            // 1-red 2-yello 3-green
            // 3-2-1-3-2-1
            case 1:
                if (temp < g) {
                    a[j][0] = 3;
                    a[j][1] = g - temp;
                }
                if (temp < g + y && temp >= g) {
                    a[j][0] = 2;
                    a[j][1] = g + y - temp;
                }
                if (temp < g + y + r && temp >= g + y) {
                    a[j][0] = 1;
                    a[j][1] = g + y + r - temp;
                }
                break;
            // 1-red 2-yello 3-green
            // 3-2-1-3-2-1
            case 2:
                if (temp < r) {
                    a[j][0] = 1;
                    a[j][1] = r - temp;
                }
                if (temp < r + g && temp >= r) {
                    a[j][0] = 3;
                    a[j][1] = r + g - temp;
                }
                if (temp < g + y + r && temp >= g + r) {
                    a[j][0] = 2;
                    a[j][1] = g + y + r - temp;
                }
                break;
            // 1-red 2-yello 3-green                   
            // 3-2-1-3-2-1
            case 3:
                if (temp < y) {
                    a[j][0] = 2;
                    a[j][1] = y - temp;
                }
                if (temp < r + y && temp >= y) {
                    a[j][0] = 1;                            
                    a[j][1] = r + y - temp;
                }
                if (temp < g + y + r && temp >= y + r) {
                    a[j][0] = 3;
                    a[j][1] = g + y + r - temp;
                }
                break;
            default:
               break;
        }
    }
}

int main() {
    int i;
    cin >> r >> y >> g;
    cin >> i;
    int t = 0;
    for (int j = 0; j < i; j++) {
        cin >> a[j][0] >> a[j][1];
    }
    // 1-red 2-yello 3-green
    // 3-2-1-3-2-1
    for (int j = 0; j < i; j++) {
        if (a[j][0] == 0) t += a[j][1];
        if (a[j][0] != 0) {
            gengxin(j, t);
            if (a[j][0] == 1) {
                t += a[j][1];
            }
            if (a[j][0] == 2) {
                t += a[j][1] + r;
            }
        }
    }
    cout << t;
    return 0;
}