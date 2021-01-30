#include <vector>
#include <memory>
#include <iostream>
using namespace std;

shared_ptr<vector<int>> alloca_v() {
    return make_shared<vector<int>>();
}
void vcout(shared_ptr<vector<int>> p) {
    for (auto i : *p) {
        cout << i << " ";
    }
    cout << endl;
}
void vcin(shared_ptr<vector<int>> p) {
    int i;
	while (cin >> i)
	{
		p->push_back(i);
	}
}
void fun(unique_ptr<int>& p) {
    cout << *p << endl;
    unique_ptr<int> p2(p.get());
    cout << *p2 << endl;
    return;
}
int main() {
    // shared_ptr<vector<int>> p = alloca_v();
    // vcin(p);
    // vcout(p);
    unique_ptr<int> p1(new int(10));
    fun(p1);
    return 0;
}