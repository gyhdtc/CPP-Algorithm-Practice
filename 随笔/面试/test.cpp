#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int debug = 0;
template <typename T> class myQueue;
// template <typename T> ostream& operator<< (ostream&, myQueue<T>& );

template <typename T>
class myQueue : public queue<T> {
    public:
        myQueue() : queue<T>() {};

        // friend ostream& operator<<<T> (ostream& output, myQueue<T>& q);
        template<typename t>
        friend ostream& operator<< (ostream& output, myQueue<t>& q);
        T xx = 0;
};
template <typename T>
ostream& operator<< (ostream& output, myQueue<T>& q) {
    while (!q.empty()) {
        output << q.front() << " ";
        q.pop();
    }
    cout << q.xx;
    output << endl;
    return output;
}

int main() {
    myQueue<int> q1;
    myQueue<double> q2;
    myQueue<char> q3;
    for (int i = 0; i < 10; i++) {
        q1.push(i);
        q2.push(i/2.0);
        q3.push(char(int('a')+i));
    }
    cout << q1;
    cout << q2;
    cout << q3;
    return 0;
}

/*
友元函数 模板类
三种方式
1、一般函数，和普通非友元没区别；
2、加上 template<typename T> void fun(base<T> base_class)，之后的友元。它可以访问各种类型int，double的类成员；
3、在文件头就声明友元函数模板，在类中只加入 void fun<T> ...
   他只能访问同样类型的模板类的成员。

*/