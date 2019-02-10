#include <map>
#include <iostream>
using namespace std;

int main(){
    map<string, int> s;
    s["gyh"] = 1;
    s["zwh"] = 2;
    cout << s["gyh"];
    map<string, int>::iterator it;
    it = s.begin();
    cout << it -> first;
    return 0;
}