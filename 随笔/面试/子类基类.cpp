#include <vector>
#include <iostream>
using namespace std;

class base {
public:
void func() {
    // func1();
    cout << 2 << endl;
}
    virtual void a() {
        cout << "a\n";
    }
};
class g : public base {
public:
g() {
    cout << "shit" << endl;
    func();
    func1();
}
    static void func1() {
        cout << 1 << endl;
    }
    virtual void a() {
        cout << "b\n";
    }
};

int main() {
    g c;
    return 0;
}
