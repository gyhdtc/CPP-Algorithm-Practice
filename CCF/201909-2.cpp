#include <iostream>
using namespace std;
int main() {
    int n;
    int sum = 0;
    int D = 0;
    int E = 0;
    cin >> n;
    int drop[n] = {0};
    for (int j = 0; j < n; ++j) {
        int t;
        int shit = 0;
        cin >> t;
        for (int i = 0; i < t; ++i) {
            int a;
            cin >> a;
            int comp = shit;
            if (a > 0) {
                if (a < shit)
                drop[j] = 1;
                shit = a;
            }
            else {
                shit += a; 
            }
        }
        sum += shit;
    }
    cout << sum << " ";

    for (int j = 0; j < n; ++j) {
        if (drop[j] == 1) ++D;
    }
    cout << D << " ";

    for (int j = 0; j < n; ++j) {
        if (j == n-2) {
            if (drop[j] == 1 && drop[j+1] == 1 && drop[0] == 1) ++E;
        }
        else if (j == n-1) {
            if (drop[j] == 1 && drop[0] == 1 && drop[1] == 1) ++E;
        }
        else {
            if (drop[j] == 1 && drop[j+1] == 1 && drop[j+2] == 1) ++E;
        }
    }
    cout << E;
    return 0;
}
/*
4
4 74 -7 -12 -5
5 73 -8 -6 59 -4
5 76 -5 -10 60 -2
5 80 -6 -15 59 0
*/
/*
5
4 10 0 9 0
4 10 -2 7 0
2 10 0
4 10 -3 5 0
4 10 -1 8 0
*/