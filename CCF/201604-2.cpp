/*
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 1 0 0 0
1 1 1 0 0 0 1 1 1 1
0 0 0 0 1 0 0 0 0 0
0 0 0 0
1 1 1 1
0 0 0 1
0 0 0 0
7
*/
#include <iostream>
using namespace std;
struct newin
{
    int type;
    int hangpy;
    int liepy;
};

int main(){
    int game[15][10] = {0};
    int b[15] = {0};
    newin newg[4][4];
    newin a[4];
    int k = 0;
    int n;
    for (int i = 0; i < 15; i++) 
        for (int j = 0; j < 10; j++)
            cin >> game[i][j];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> newg[i][j].type;
            if (newg[i][j].type == 1) {
                newg[i][j].hangpy = i;
                newg[i][j].liepy  = j;
                a[k++] = newg[i][j];
            }
        }
    }

    cin >> n;
    n--;// 列

    int i;
    for (i = 0; i < 15; i++) {
        // i 行
        int flag1 = 0;
        int flag2 = 0;
        for (int j = 0; j < 4; j++) {
            // 先看有没有超位
            if (a[j].hangpy + i >= 15 || a[j].liepy + n >= 10) {
                flag1 = 1;
                break;
            }
        }
        if (flag1 == 1) continue;
        for (int j = 0; j < 4; j++) {
            // 再看重合
            if (game[a[j].hangpy + i][a[j].liepy + n] == 1) {
                flag2 = 1;
                break;
            }
        }
        if (flag2 == 1) continue;
        else b[i] = 1;
    }
    for (i = 0; i < 14; i++) 
        if (b[i+1] == 0) break;

    for (int j = 0; j < 4; j++) {
        // 写入 game
        game[a[j].hangpy + i][a[j].liepy + n] = 1;
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++) cout << game[i][j] << " ";
        cout << endl;
    }
    return 0;
}