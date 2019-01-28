#include <iostream>
using namespace std;
int main() {
    int r, y, g;
    cin >> r >> y >> g;
    int i;
    cin >> i;
    int a, b, t = 0;
    for (; i > 0; i--) {
        cin >> a >> b;
        if (a == 0 || a == 1) t += b;
        if (a == 2) t += b + r;
    }
    cout << t;
}