#include<iostream>
using namespace std;

class ClxBase
{
    public:
        ClxBase() {};
        virtual ~ClxBase() { cout<<"delete ClxBase"<<endl; };

        virtual void DoSomething() { cout << "Do something in class ClxBase!" << endl;  };

};

class ClxDerived : public ClxBase
{
    public:
        ClxDerived() {};
        ~ClxDerived() { cout << "delete ClxDerived!" << endl;  };

        void DoSomething() { cout << "Do something in class ClxDerived!" << endl;  };

};
class ClxDerived2 : public ClxBase
{
    public:
        ClxDerived2() {};
        ~ClxDerived2() { cout << "delete ClxDerived-2!" << endl;  };

        void DoSomething() { cout << "Do something in class ClxDerived-2!" << endl;  };

};
int main()
{
    ClxBase *pTest = new ClxDerived;
    pTest->DoSomething();
    pTest = new ClxDerived2;
    pTest->DoSomething();
    delete pTest;
    return 0;
}