#include <iostream>  
using namespace std;  
  
class A{  
public:  
    void action(){  
        cout << "Action in class A!" << endl;  
    }  
};  
  
class B{  
    A a;  
public:  
    A* operator->(){  //返回指针
        return &a;  
    }  
    void action(){  
        cout << "Action in class B!" << endl;  
    }  
};  
  
class C{  
    B b;  
public:  
    B* operator->(){  //返回对象
        return &b;  
    }  
    void action(){  
        cout << "Action in class C!" << endl;  
    }  
};  
  
int main(int argc, char *argv[])  
{  
    C* pc = new C;  
    pc->action();  //指针调用(使用默认语义)
    C c;  
    c->action();   //对象调用（使用重载语义） 
    return 0;  
}