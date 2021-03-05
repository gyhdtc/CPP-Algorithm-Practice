#include <iostream>
#include <vector>
#include <string>
using namespace std;

void CreatNext(string pat, vector<int>& next) {
    int len = pat.size();
    if (len > 0) next.resize(len);
    next[0] = 0;
    int t = 0;
    for (int i = 1; i < len; ++i) {
        while (t > 0 && pat[t]/*这里就相当于是上一次匹配到的字符的后一个，因为序号从0开始*/ != pat[i])
            t = next[t-1];
        if (pat[t] == pat[i])
            ++ t;
        next[i] = t;
    }
}
int getindex(string txt, string pat, vector<int> next) {
    int txtlen = txt.size();
    int patlen = pat.size();
    for (int i = 0, j = 0; i < txtlen; ++i) {
        while (j > 0 && txt[i] != pat[j]) {
            j = next[j-1];
        }
        if (txt[i] == pat[j])
            ++j;
        if (j == patlen)
            return i-j+1;
    }
    return -1;
}
void print(vector<int> v) {
    for (int i = 0; i < v.size(); ++i) cout << v[i] << " ";
    cout << endl;
}
int main() {
    string txt = "ABABACCABABAACCAB";
    string pat = "ABABAA";
    vector<int> next;
    vector<int> dp;
    CreatNext(pat, next);
    print(next);
    int index = getindex(txt, pat, next);
    cout << index << endl;
    return 0;
}