#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
int res;

vector<int> getjiangluodian(int chushiweizhi, int yicidejuli, vector<int>& jl) {
    vector<int> t;
    for (int i = 0; i < jl.size(); ++i) {
        if (jl[i] > chushiweizhi && jl[i] <= chushiweizhi+yicidejuli) t.push_back(i);
        if (jl[i] > chushiweizhi+yicidejuli) break;
    }
    return t;
}
void shit(int sum, int chushiweizhi, int yicidejuli, int cishu, vector<int>& jl, vector<int>& val) {
    if (cishu == 0) res = max(res, sum);
    else {
        vector<int> keyijiangluodian = getjiangluodian(chushiweizhi, yicidejuli, jl);
        for (int i = 0; i < keyijiangluodian.size(); ++i) {
            shit(sum+val[keyijiangluodian[i]], jl[keyijiangluodian[i]], yicidejuli, cishu-1, jl, val);
        }
    }
}
int main(){
    res = 0;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> jl(n);
    vector<int> val(n);
    for (int i = 0; i < n; ++i) {
        cin >> jl[i];
        cin >> val[i];
    }
    vector<int> dp(m*k);
    int sum = val[0];
    shit(sum, 0, m, k, jl, val);
    cout << res << endl;
    return 0;
}
