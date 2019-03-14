/*
计算器
有 数字 -操作字
有 +-/* -操作符
我们从左开始读取每个字符，现在有一个 操作符堆栈 stact<node> s 保存操作数, 有一个队列 queue<node> q 保存后缀表达式
—— 新操作符 大于栈顶的话，就直接压入栈
—— 新操作符 小于等于的话，就不断出栈，再进入后缀表达式的队列中，直到其新操作符大于栈顶
———— 可以用 map 键值对来表示优先级惹 （* == / > + == -）
—————— 如果是 （ 的话，就压入操作符栈；如果是 ） 就不断弹出操作符栈，直到栈顶是 （ 
—— 最后再全部入栈
计算后缀表达式
—— 从左开始扫描，操作数就入栈；操作符就连续弹出两个操作数；后出的时第一操作数，进行操作，计算新数之后再入栈
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
#include <queue>
#include <map>
using namespace std;

struct node
{
    double num;
    char op;
    bool flag; // true 表示 数字；false 表示 操作符；
};

string str;
stack<node> s;
queue<node> q;
map<char,int> op;

void Change(){
    double num;
    node temp;
    for (int i = 0; i < str.length();) {
        if (str[i] >= '0' && str[i] <= '9') {
            temp.flag = true;
            temp.num = str[i++] - '0';
            while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
                temp.num = temp.num * 10 + str[i] - '0';
                i ++;
            }
            q.push(temp);
        }
        else if (str[i] == '(') {
            temp.flag = false;
            temp.op = str[i];
            s.push(temp);
            i ++;
        }
        else if (str[i] == ')') {
            temp.flag = false;
            while (!s.empty() && s.top().op != '(') {
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i ++;
        }
        else {
            temp.flag = false;
            while (!s.empty() && op[str[i]] <= op[s.top().op]) {
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i ++;
        }
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

double Cal(){
    double temp1, temp2;
    node cur, temp;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur.flag == true || (cur.flag == false && (cur.op == '(' || cur.op == ')'))) s.push(cur);
        else {
            temp2 = s.top().num;
            s.pop();
            temp1 = s.top().num;
            s.pop();
            // 上面的保存到 temp 中
            temp.flag = true;       // 临时记录 temp 的 flag
            if (cur.op == '+') temp.num = temp1 + temp2; 
            if (cur.op == '-') temp.num = temp1 - temp2;
            if (cur.op == '*') temp.num = temp1 * temp2;
            if (cur.op == '/') temp.num = temp1 / temp2;
            s.push(temp);
        }
    }
    return s.top().num;
}

int main(){
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    op['('] = op[')'] = 0;
    getline(cin, str);
    for (string::iterator it = str.end(); it != str.begin(); it--) {
        if (*it == ' ') str.erase(it);
    }
    while(!s.empty()){      // 初始化栈
        s.pop();
    }
    Change();               // 读取的表达式变成后缀表达式
    printf("%.2lf \n", Cal());
}