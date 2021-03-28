#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int state = -1;
        string str;
        cin >> str;
        vector<int> res;
        stack<int> stk;
        // stk.push('&');
        for (int i = 0; i < str.size(); i++) {
            // cout << state << endl;
            if (str[i] <= '9' && str[i] >= '0') {
                if (state == 0) {
                    int t = stk.top()*10+str[i]-'0';
                    stk.pop();
                    stk.push(t);
                }
                else {
                    stk.push(str[i]-'0');
                }
                state = 0;
            }
            if (str[i] == '(') {
                stk.push(str[i]);
                state = 1;
            }
            if (str[i] == ',') {
                if (stk.top() != '(')
                    stk.push(str[i]);
                else {
                    stk.pop();
                    // res.push_back(stk.top());
                    cout << stk.top() << " ";
                    stk.pop();
                    stk.push('(');
                    state = 1;
                    continue;
                }
                state = 2;
            }
            if (str[i] == ')') {
                if (state == 2) {
                    stk.pop(); // '
                    cout << stk.top() << " ";
                    stk.pop(); // shuzi
                    stk.pop(); // (
                    if (stk.top() == '(') {
                        // state = 1;
                        continue;
                    }
                    else {
                        cout << stk.top() << " ";
                        stk.pop();
                        // state = 1;
                    }
                }
                if (state == 0) {
                    int you,zuo;
                    int youflag = 0, zuoflag = 0;
                    you = stk.top();
                    youflag = 1;
                    stk.pop(); // you
                    if (stk.top() == ',') {
                        stk.pop(); // ,
                        zuo = stk.top();
                        zuoflag = 1;
                        stk.pop(); // zuo
                        stk.pop(); // (
                    }
                    if (zuoflag == 1) cout << zuo << " ";
                    if (stk.top() == '(') {
                        // state = 1;
                    }
                    else {
                        cout << stk.top() << " ";
                        stk.pop(); // geng
                        // state = 1;
                    }
                    if (youflag == 1) cout << you << " ";
                }
                if (state == 1) {
                    stk.pop();
                    if (stk.top() == '(')
                        continue;
                    else {
                        cout << stk.top() << " ";
                        stk.pop();
                    }
                }
                state = 3;
            }
        }
    }
}