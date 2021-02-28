#include <iostream>
#include <string>
#include <vector>
using namespace std;
// class A {

// };
// class B : public A {
//     virtual void fun() {}
// };
// #define offset(type, member) ((size_t)&(((type*)0)->member))
// int main(){
//     // string str;
//     // cin >> str;
//     // int len = str.size();
//     // int a[len+1];
//     // a[0] = 0;
//     // int b[len+1];
//     // b[0] = 0;
//     // int res = 0;
//     // for (int i = 0; i < len; ++i) a[i+1] = a[i] + (str[i] == '0' ? 2 : 1);
//     // for (int i = len-1; i >= 0; --i) b[len - i] = b[len - 1- i] + (str[i] == '0' ? 1 : 2);
//     // for (int i = 0; i <= len; ++i) res = max(a[i]+b[len-i], res);
//     // cout << res << endl;
//     A a;
//     B b;
//     cout << sizeof(a) << endl;
//     cout << sizeof(b) << endl;
//     return 0;
// }
int main() {
    vector<int> a {1,2,3,4,5,6};
    vector<int> b(a.begin()+1, a.begin()+3);
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }
}