#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

int chang;
int kuan;
int boxchang;
int boxkuan;
vector<vector<int>> CK;

struct box {
    int x;
    int y;
    vector<vector<int>> CKnow;
};

vector<box> panduansxzy(box b) {
    CK = b.CKnow;
    vector<box> res;
    
    // cout << 2 << endl;
    // up
    if (b.x-1 >= 0) {
        int i = b.x - 1;
        int j = b.y;
        int flag = 0;
        for (int k = j ; k < j + boxkuan; k++) {
            if (CK[i][k] == 1) {
                flag = 1;
                break;
            }
        }
        box t;
        t.CKnow = CK;
        t.x = i;
        t.y = j;
        if (flag == 0) {
            for (int k = j ; k < j + boxkuan; k++) {
                t.CKnow[i+boxchang][k] = 0;
                t.CKnow[i][k] = 1;
            }
            res.push_back(t);
        }
    }
    // cout << 3 << endl;
    // down
    if (b.x+boxchang < chang) {
        int i = b.x + 1;
        int j = b.y;
        int flag = 0;
        for (int k = j ; k < j + boxkuan; k++) {
            if (CK[i-1+boxchang][k] == 1) {
                flag = 1;
                break;
            }
        }
        box t;
        t.CKnow = CK;
        t.x = i;
        t.y = j;
        if (flag == 0) {
            for (int k = j ; k < j + boxkuan; k++) {
                t.CKnow[i-1][k] = 0;
                t.CKnow[i-1+boxchang][k] = 1;
            }
            res.push_back(t);
        }
    }
    // cout << 4 << endl;
    // zuo
    if (b.y-1 >= 0) {
        int i = b.x;
        int j = b.y - 1;
        int flag = 0;
        for (int k = i ; k < i + boxchang; k++) {
            if (CK[k][j] == 1) {
                flag = 1;
                break;
            }
        }
        box t;
        t.CKnow = CK;
        t.x = i;
        t.y = j;
        if (flag == 0) {
            for (int k = i ; k < i + boxchang; k++) {
                t.CKnow[k][j+boxkuan] = 0;
                t.CKnow[k][j] = 1;
            }
            res.push_back(t);
        }
    }
    // cout << 5 << endl;
    // you
    if (b.y-1+boxkuan < kuan) {
        int i = b.x;
        int j = b.y + 1;
        int flag = 0;
        for (int k = i ; k < i + boxchang; k++) {
            if (CK[k][j-1+boxkuan] == 1) {
                flag = 1;
                break;
            }
        }
        box t;
        t.CKnow = CK;
        t.x = i;
        t.y = j;
        if (flag == 0) {
            for (int k = i ; k < i + boxchang; k++) {
                t.CKnow[k][j-1] = 0;
                t.CKnow[k][j-1+boxkuan] = 1;
            }
            res.push_back(t);
        }
    }
    return res;
}
bool kaojinqiangmian(box b) {
    if (b.x == 0 || b.y+boxkuan == kuan || b.x+boxchang == chang || b.y == 0) return true;
    return false;
}
int main() {
    int res = 0;
    box b;
    cin >> chang >> kuan >> boxchang >> boxkuan >> b.x >> b.y;
    b.x--;
    b.y--;
    CK.resize(chang);
    for (int i = 0; i < chang; i++) CK[i].resize(kuan);
    for (int i = 0; i < chang; i++) 
        for (int j = 0; j < kuan; j++)
            cin >> CK[i][j];
    b.CKnow = CK;
    queue<box> qnmd;
    qnmd.push(b);

    set<pair<int, int>> gyh;
    gyh.insert({b.x, b.y});

    while (!qnmd.empty()) {
        vector<box> temp;
        while (!qnmd.empty()) {
            temp.push_back(qnmd.front());
            qnmd.pop();
        }
        res ++;
        for (auto b : temp) {
            // cout << 1 << endl;
            vector<box> keyiyidong = panduansxzy(b);
            for (auto g : keyiyidong) {
                if (kaojinqiangmian(g)) {
                    cout << res;
                    return 0;
                }
                if (gyh.count({g.x, g.y}) == 0) {
                    // cout << g.x << " " << g.y << endl;
                    qnmd.push(g);
                    gyh.insert({g.x, g.y});
                }
            }
        }
    }
    return 0;
}