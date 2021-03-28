#include <iostream>
using std::cout;
using std::endl;
 
class BASE
{ 
public:
    // BASE(int n):m_b(n){}
    // virtual ~BASE(){
    //      print();
    //     cout << "b" << endl;
    // }
    virtual void print(){cout<<"BASE : m_b = "<<m_b<<endl;}
    void func(){
        cout << "func\n";
    }
    int m_b;
};
 
class DERIVED : public BASE
{
public:
    // DERIVED(int n):m_d(n),BASE(2*n){
    //     print();
    //     func();
    // }
    // ~DERIVED(){
    //     print();
    //     cout << "d" << endl;
    // }
     void print1(int a){
        if (a == 0) {
            cout << 9 << endl;
            return;
        }
        cout<<"DERIVED : m_d= "<<m_d<<endl;
        print1(0);
    }
    static void func(int a) {
        cout << "sb\n";
    }
    int m_d;
};
void func(int a) {
    cout << "s\n";
}
int main()
{
    BASE* b = new DERIVED;
    b->print();
    DERIVED* d = new DERIVED;
    d->print1(1);
    d->print();

    BASE* base = new BASE;
    base->func();
    b->func();
    d->func(1);

    cout << sizeof(DERIVED) << endl;

    delete b;
    cout << "-------------\n";
    delete d;

    return 0;
}