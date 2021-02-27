#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    cin >> str;
    int len = str.size();
    int a[len+1];
    a[0] = 0;
    int b[len+1];
    b[0] = 0;
    int res = 0;
    for (int i = 0; i < len; ++i) a[i+1] = a[i] + (str[i] == '0' ? 2 : 1);
    for (int i = len-1; i >= 0; --i) b[len - i] = b[len - 1- i] + (str[i] == '0' ? 1 : 2);
    for (int i = 0; i <= len; ++i) res = max(a[i]+b[len-i], res);
    cout << res << endl;
}