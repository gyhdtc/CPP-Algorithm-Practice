#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 先还后取
// 小号先还

int n, k;

struct timeflag
{
    bool naflag;
    vector<int> nakey;
    bool huanflag;
    vector<int> huankey;
}a[10200];

void shuchu(vector<int> a){
    int len = a.size();
    for (int i = 0; i < len; i++) cout << a[i] << " ";
}

bool cmp(int x, int y) {
    return x < y;
}

void huan(int a[], vector<int> b){
    int len = b.size();
    int j = 1;
    sort(b.begin(), b.end(), cmp);
    for (int i = 0; i < len; i++) {
        while(a[j] != 0) j++;
        a[j] = b[i];
    }
}

void na(int a[], vector<int> b){
    int len = b.size();
    for (int i = 0; i < len; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j] == b[i]) {
                a[j] = 0;
                break;
            }
        }
    }
}

int main(){
    int w, s, c;
    cin >> n >> k;
    int key[n+1];
    for (int i = 0; i < n+1; i++) key[i] = i;
    for (int i = 0; i < 10200; i++) {
        a[i].naflag = a[i].huanflag = false;
    }
    while (k--) {
        cin >> w >> s >> c;
        a[s].naflag = true;
        a[s].nakey.push_back(w);
        a[s+c].huanflag = true;
        a[s+c].huankey.push_back(w);
    }
    // for (int i = 0; i < 10200; i++) {
    //     if (a[i].huanflag == true || a[i].naflag == true) {
    //         if (a[i].naflag == true) {
    //             cout << i << " time na:";
    //             shuchu(a[i].nakey);
    //             cout << endl;
    //         }
    //         if (a[i].huanflag == true) {
    //             cout << i << " time huan:";
    //             shuchu(a[i].huankey);
    //             cout << endl;
    //         }
    //     }
    // }
    for (int i = 0; i < 10200; i++) {
        if (a[i].huanflag == true || a[i].naflag == true) {
            if (a[i].huanflag == true) {
                huan(key, a[i].huankey);
            }
            if (a[i].naflag == true) {
                na(key, a[i].nakey);
            }
            // cout << i << " time : ";
            // for (int i = 1; i < n+1; i++) cout << key[i] << " ";
            // cout << endl;
        }
    }
    for (int i = 1; i < n; i++) cout << key[i] << " ";
    cout << key[n];
    return 0;
}