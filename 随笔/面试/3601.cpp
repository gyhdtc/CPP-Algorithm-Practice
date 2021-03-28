#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include <math.h>
using namespace std;
int32_t x[18];
vector<int32_t> meiyiweiqingkuang(int a) {
    vector<int32_t> wei(18);
    int h = 0x00001;
    for (int i = 0; i < 18; ++i) {
        if ((a & h) > 0) wei[i] = 1;
        h = h << 1; 
    }
    return wei;
}
void addvector(vector<int>& wei, vector<int>& t) {
    for (int i = 0; i < 18; ++i) {
        wei[i] += t[i];
    }
}
int main(){
    for (int i = 0; i < 18; ++i) x[i] = pow(2,i);
    int n;
    cin >> n;
    vector<int32_t> a(n);
    vector<int32_t> wei(18);
    int sum = 0;
    for (int i = 0 ; i < n; ++i) {
        cin >> a[i];
    }
    for (auto i : a) {
        vector<int32_t> t = meiyiweiqingkuang(i);
        addvector(wei, t);
    }
    for (int i = 0; i < 18; ++i) {
        if (wei[i] > 0)
        sum += (wei[i]*n-(wei[i]*(wei[i]-1))/2)*x[i];
    }
    cout << sum << endl;
    return 0;
}
