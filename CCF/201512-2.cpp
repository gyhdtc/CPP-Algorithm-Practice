#include <iostream>
using namespace std;
struct qipan
{
    int shuru;
    int shuchu;
};
int n,m;

void jiancha(qipan game[30][30],int hang, int lie){
    // 检查这个 i j 左边两个，右边两个，上面两个，下面两个；
    // 左边右边一个，上下一个，不能大于等于 nm
    
        // if (lie - 2 >= 0 && game[hang][lie-1].shuru == game[hang][lie].shuru && game[hang][lie-2].shuru == game[hang][lie].shuru) {
        //     game[hang][lie-2].shuchu = 0;
        //     game[hang][lie-1].shuchu = 0;
        //     game[hang][lie].shuchu   = 0;
        //     game[hang][lie-2].shifoujiancha = true;
        //     game[hang][lie-1].shifoujiancha = true;
        //     game[hang][lie].shifoujiancha   = true;
        // }
        if (lie + 2 < m && game[hang][lie+1].shuru == game[hang][lie].shuru && game[hang][lie+2].shuru == game[hang][lie].shuru) {
            game[hang][lie+2].shuchu = 0;
            game[hang][lie+1].shuchu = 0;
            game[hang][lie].shuchu   = 0;
            // game[hang][lie+2].shifoujiancha = true;
            // game[hang][lie+1].shifoujiancha = true;
            // game[hang][lie].shifoujiancha   = true;
        }
        if (hang + 2 < n && game[hang+1][lie].shuru == game[hang][lie].shuru && game[hang+2][lie].shuru == game[hang][lie].shuru) {
            game[hang+2][lie].shuchu = 0;
            game[hang+1][lie].shuchu = 0;
            game[hang][lie].shuchu   = 0;
            // game[hang+2][lie].shifoujiancha = true;
            // game[hang+1][lie].shifoujiancha = true;
            // game[hang][lie].shifoujiancha   = true;
        }
        // if (hang - 2 < n && game[hang+1][lie].shuru == game[hang][lie].shuru && game[hang+2][lie].shuru == game[hang][lie].shuru) {
        //     game[hang][lie-2].shuchu = 0;
        //     game[hang][lie-1].shuchu = 0;
        //     game[hang][lie].shuchu   = 0;
        //     game[hang][lie-2].shifoujiancha = true;
        //     game[hang][lie-1].shifoujiancha = true;
        //     game[hang][lie].shifoujiancha   = true;
        // }
}
int main(){
    cin >> n >> m;
    qipan game[30][30];

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        cin >> game[i][j].shuru;
        game[i][j].shuchu = game[i][j].shuru;
    }

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
        jiancha(game, i, j);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << game[i][j].shuchu;
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}