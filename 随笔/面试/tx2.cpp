#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class A {
public:
void fun(bool a) {
    cout << "bool\n";
}
};

class B : public A {
public:
void fun(int a) {
    cout << a << endl;
    cout << "int\n";
}  
};

int main()
{
    B b;
    b.fun(false);
    // int T;
    // cin >> T;
    // while (T--)
    // {
    //     int n, ans, min, min2;
    //     cin >> n;
    //     int i;
    //     vector<int> seconds(n);
    //     for (i = 0; i < n; ++i) cin >> seconds[i];
    //     sort(seconds.begin(), seconds.end(), [](int a, int b){return a > b;});
    //     ans = 0;
    //     i = 0;
    //     min = seconds[n - 1];
    //     min2 = seconds[n - 2];
    //     while (i < n - 3)
    //     {
    //         if (2 * min2 >= min + seconds[i + 1])
    //             ans += seconds[i] + seconds[i + 1] + 2 * min;
    //         else
    //             ans += seconds[i] + min + 2 * min2;
    //         ++i;
    //         ++i;
    //     }
    //     if (i == n - 3)
    //         ans += seconds[n - 3] + seconds[n - 2] + seconds[n - 1];
    //     else if (i == n - 2)
    //         ans += seconds[n - 2];
    //     else if (i == n - 1) // 注意考虑输入n = 1的情况
    //         ans += seconds[n - 1];
    //     cout << ans << endl;
    // }
    // return 0;
}