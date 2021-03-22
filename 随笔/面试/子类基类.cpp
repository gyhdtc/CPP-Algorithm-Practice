#include <vector>
#include <iostream>
using namespace std;

class base {
public:
    virtual void a() {
        cout << "a\n";
    }
};
class g : public base {
public:
    virtual void a() {
        cout << "b\n";
    }
};

int main() {
    base b;
    g c;
    base * t = &c;
    t->a();
    t = &b;
    t->a();
    return 0;
}
