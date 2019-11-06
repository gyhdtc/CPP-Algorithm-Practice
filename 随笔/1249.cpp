#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> zuokuohao;
        string::iterator it;
        string res;
        int len = s.size();
        for (int i = 0; i < len; i ++) {
            if (s[i] == ')' && zuokuohao.size() == 0)
                s[i] = ' ';
            
            if (s[i] == ')' && zuokuohao.size() != 0)
                zuokuohao.pop_back();
            
            if (s[i] == '(')
                zuokuohao.push_back(i);
        }
        cout << s << endl;
        for (int i = 0; i < zuokuohao.size(); i ++) {
            s[i] = ' ';
        }
        for (it = s.begin(); it != s.end(); it ++) {
            if (*it == ' ')
                s.erase(it);
        }
        res.append(s);
        return res;
    }
};
int main() {
    string gyh = "lee(t(c)o)de)shit";
    cout << gyh << endl;
    Solution a;
    gyh = a.minRemoveToMakeValid(gyh);
    cout << gyh << endl;
    return 0;
}