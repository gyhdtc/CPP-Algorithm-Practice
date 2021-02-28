#include <stack>
#include <unordered_map>
#include <iostream>
using namespace std;
bool shiliu(char x) {
    if ((x >= '0' && x <= '9') || (x >= 'A' && x <= 'F'))
        return true;
    return false;
}
int shiliuzhuanshi(char x) {
    if ((x >= '0' && x <= '9'))
        return x-'0';
    else {
        char t = 'A';
        switch (x)
        {
        case 'A':
            return x-t+10;
            break;
        case 'B':
            return x-t+10;
            break;
        case 'C':
            return x-t+10;
            break;
        case 'D':
            return x-t+10;
            break;
        case 'E':
            return x-t+10;
            break;
        case 'F':
            return x-t+10;
            break;
        default:
            return 0;
            break;
        }
    }
}
int main() {
    
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        stack<char> baifenhao;
        stack<char> qita;
        for (int i = 0; i < str.size(); ++ i) {
            if (str[i] == '%')
                baifenhao.push(str[i]);
        }
        for (int i = str.size()-1; i >= 0; -- i) {
            if (str[i] != '%')
                qita.push(str[i]);
        }
        string res;
        while (qita.size() >= 2 && !baifenhao.empty())
        {
            char c1 = qita.top();
            if (!shiliu(c1)) break;
            qita.pop();
            char c2 = qita.top();
            if (!shiliu(c1)) {
                qita.push(c1);
                break;
            }
            qita.pop();
            baifenhao.pop();
            char t = char(shiliuzhuanshi(c1)*16+shiliuzhuanshi(c2));
            qita.push(t);
        }
        while (!baifenhao.empty()) {
            res = res + baifenhao.top();
            baifenhao.pop();
        }
        while (!qita.empty()) {
            res = res + qita.top();
            qita.pop();
        }
        cout << res << endl;
    }
}