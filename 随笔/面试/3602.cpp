#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
int res;

void func(int i) {
    cout << &i << endl;
    int a1 = 1;
    // int a2 = 2;
    // int a3 = 3;
    // int a4 = 4;
    int a5;
    int a6;
    int a7;
    int a8;
    int a9;
    int a10;
    func(i+1);
    return;
}
int main(){
    // int a;
    // cout << sizeof(a);
    func(0);
    return 0;
}
