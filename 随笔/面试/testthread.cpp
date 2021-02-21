// #include <iostream>
// #include <thread>

// using namespace std;

// class A {
// public:
//     int ai;
//     A (int i) : ai(i)
//     {
//         cout << "make " << this << endl;
//     }

//     A (const A& a) :ai(a.ai) {
//         cout << "copy make " << this << endl;
//     }

//     ~A()
//     {
//         cout << "dismake " << this << endl;
//     }
// };

// void test(const A& a)
// {
//     int b;
//     cin >> b;
//     cout << "child start" << endl;
//     cout << "child end" << endl;
//     return;
// }


// int main()
// {
//     cout << "main start" << endl;
//     int i = 4;
//     A a(4);
//     thread t(test, a);
//     t.join();
//     cout << "main end" << endl;
//     return 0;
// }
#include <iostream>
#include <thread>

using namespace std;

class A{
public:
     int ai;
     A (int i): ai(i) { }
     void out(){
         ai++;
         cout << &ai << endl;
         cout << this << endl;
     }
};

//这种情况必须在引用前加const，否则会出错。目前本人的觉得可能是因为临时对象具有常性
void test(int &ti, const A &t)
{
    cout << "子线程开始" << endl;
    //ti的内存地址0x0126d2ec {4}，t.ai的内存地址0x0126d2e8 {ai=5 }
    cout << ti << " " << t.ai << endl;
    cout << "子线程结束" << endl;
    return;
}


int main()
{
    cout << "主线程开始" << endl;
    //i的内存地址0x010ff834 {4}，a的内存地址0x010ff828 {ai=5 }
    int i = 4;
    A a(5);
    A* b = new A(5);
    a.out();
    b->out();
    cout << a.ai << endl;
    cout << &i;
    // thread t(test, ref(i), a);
    // t.join();
    cout << "主线程结束！" << endl;
    return 0;
}