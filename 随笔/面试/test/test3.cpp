#include <string>
#include <iostream>  
using namespace std; 

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr& hp) :ps(new std::string(*hp.ps)), i(hp.i) {}

	std::string *ps;
	int i;
};
int main() {
    string s = "gyh";
    HasPtr h1(s);
    HasPtr h2 = h1;
    cout << *h2.ps;
    return 0;
}