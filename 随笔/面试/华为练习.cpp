#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    stack<string> st;
    int state = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            state = 0;
            continue;
        }
        else if (str[i] != '(' && str[i] != ')'){
            if (!st.empty() && state == 1) {
                string t = st.top();
                t += str[i];
                st.pop();
                st.push(t);
            }
            else {
                string t = "";
                t += str[i];
                st.push(t);
            }
            state = 1;
        }
        // ）
        else {
            if (!st.empty()) {
                string t = st.top();
                st.pop();
                reverse(t.begin(), t.end());
                if (!st.empty()) {
                    string t2 = st.top();
                    st.pop();
                    t2 += t;
                    st.push(t2);
                }
                else {
                    st.push(t);
                }
            }
            else {
                continue;
            }
            state = 1;
        }
        // cout << st.top() << endl;
    }
    cout << st.top() << endl;
}