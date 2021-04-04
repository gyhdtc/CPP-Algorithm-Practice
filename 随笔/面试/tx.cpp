#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int res = 1000000;

void find10(string a, vector<int>& t) {
    for (int i = 0; i < a.size()-1; i++) {
        if ( (a[i]-'0' + a[i+1] - '0') == 10) t.push_back(i);
    }
}

void dfs(string a) {
    vector<int> index10;
    find10(a, index10);
    if (res > a.size()) res = a.size();
    for (int i = 0; i < index10.size(); i++) {
        string t = a.substr(index10[i], 2);
        a.erase(index10[i], 2);
        dfs(a);
        if (a.size()-1 < index10[i]) a += t;
        else a.insert(index10[i], t);
    }
}

int main() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    dfs(a);
    cout << res << endl;
}