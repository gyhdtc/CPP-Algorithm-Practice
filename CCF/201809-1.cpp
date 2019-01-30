#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n], cunzuo;
    for (int i = 0; i < n; i++) cin >> a[i];
    cunzuo = a[0];
    for (int i = 0; i < n; i++) {
        if (i == 0) a[i] = (a[i] + a[i+1]) / 2;
        else if (i == n-1) a[n-1] = (cunzuo + a[n-1]) / 2;
        else {
            int t = a[i];
            a[i] = (cunzuo + a[i] + a[i+1]) / 3;
            cunzuo = t;
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}