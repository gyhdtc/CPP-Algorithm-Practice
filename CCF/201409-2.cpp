#include <iostream>
using namespace std;
int main(){
    int x1, y1, x2, y2;
    int a[101][101] = {0};
    int n;
    int sum = 0;
    cin >> n;
    while(n--){
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) {
            int t = x1;
            x1 = x2;
            x2 = t;
        }
        if (y1 > y2) {
            int t = y1;
            y1 = y2;
            y2 = t;
        }
        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                a[x][y] = 1;
            }
        }
    }
    for (int x = 0; x < 101; x++) {
        for (int y = 0; y < 101; y++) {
            if (a[x][y] == 1) sum ++;
        }
    }
    cout << sum;
    return 0;
}