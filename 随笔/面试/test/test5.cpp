#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::cin;
using std::endl;

vector<int>* alloca_v() {
    return new vector<int>();
}
void vcout(vector<int>* p) {
    for (auto i : *p) {
        cout << i << " ";
    }
    cout << endl;
}
void vcin(vector<int>* p) {
    int i;
	while (cin >> i)
	{
		p->push_back(i);
	}
}
int main() {
    auto *p = alloca_v();
    vcin(p);
    vcout(p);
    delete p;
    return 0;
}