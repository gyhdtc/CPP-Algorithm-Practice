#include <string>
#include <iostream>

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr& hp) :ps(new std::string(*hp.ps)), i(hp.i) {}
    HasPtr& operator= (const HasPtr& hp) {
        auto *pt = new std::string(*hp.ps);
        delete ps;
        ps = pt;
        i = hp.i;
        return *this;
        // 赋值运算符 应该：
        // 1. 先复制
        // 2. 再释放
    }
    ~HasPtr() {
        delete ps;
    }
	std::string *ps;
	int i;
};
int main() {
    std::string s = "gyh";
    HasPtr h1(s);
    HasPtr h2 = h1;
    std::cout << *h2.ps;
    return 0;
}