#include <vector>
#include <iostream>
using namespace std;

int defen(vector<int> a, vector<int> b) {
    int s = 0;
    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i]) s++;
    }
    return s;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> Am(3);
        vector<int> Aw(3);
        vector<int> Bm(3);
        vector<int> Bw(3);
        vector<vector<int>> Asocre;
        vector<vector<int>> Bsocre;
        // 输入
        for (int i = 0; i < 3; i++) {
            cin >> Am[i];
        }
        for (int i = 0; i < 3; i++) {
            cin >> Aw[i];
        }
        for (int i = 0; i < 3; i++) {
            cin >> Bm[i];
        }
        for (int i = 0; i < 3; i++) {
            cin >> Bw[i];
        }
        // ---------------------------
        // 计算，每个队的 9 种结果
        // 分别是：
        // MM MW WW
        // 01 20 12
        // 01 21 02
        // 01 22 01
        Asocre.push_back({Am[0]+Am[1], Am[2]+Aw[0], Aw[1]+Aw[2]});
        Asocre.push_back({Am[0]+Am[1], Am[2]+Aw[1], Aw[0]+Aw[2]});
        Asocre.push_back({Am[0]+Am[1], Am[2]+Aw[2], Aw[0]+Aw[1]});
        // 02 10 12
        // 02 11 02
        // 02 12 01
        Asocre.push_back({Am[0]+Am[2], Am[1]+Aw[0], Aw[1]+Aw[2]});
        Asocre.push_back({Am[0]+Am[2], Am[1]+Aw[1], Aw[0]+Aw[2]});
        Asocre.push_back({Am[0]+Am[2], Am[1]+Aw[2], Aw[0]+Aw[1]});
        // 12 00 12
        // 12 01 02
        // 12 02 01
        Asocre.push_back({Am[2]+Am[1], Am[0]+Aw[0], Aw[1]+Aw[2]});
        Asocre.push_back({Am[2]+Am[1], Am[0]+Aw[1], Aw[0]+Aw[2]});
        Asocre.push_back({Am[2]+Am[1], Am[0]+Aw[2], Aw[0]+Aw[1]});
        // B
        Bsocre.push_back({Bm[0]+Bm[1], Bm[2]+Bw[0], Bw[1]+Bw[2]});
        Bsocre.push_back({Bm[0]+Bm[1], Bm[2]+Bw[1], Bw[0]+Bw[2]});
        Bsocre.push_back({Bm[0]+Bm[1], Bm[2]+Bw[2], Bw[0]+Bw[1]});
        Bsocre.push_back({Bm[0]+Bm[2], Bm[1]+Bw[0], Bw[1]+Bw[2]});
        Bsocre.push_back({Bm[0]+Bm[2], Bm[1]+Bw[1], Bw[0]+Bw[2]});
        Bsocre.push_back({Bm[0]+Bm[2], Bm[1]+Bw[2], Bw[0]+Bw[1]});
        Bsocre.push_back({Bm[2]+Bm[1], Bm[0]+Bw[0], Bw[1]+Bw[2]});
        Bsocre.push_back({Bm[2]+Bm[1], Bm[0]+Bw[1], Bw[0]+Bw[2]});
        Bsocre.push_back({Bm[2]+Bm[1], Bm[0]+Bw[2], Bw[0]+Bw[1]});
        // -------------------------------------------------------
        int res = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (defen(Bsocre[j], Asocre[i]) >= 2) res ++;
            }
        }
        cout << res << endl;
    }
}