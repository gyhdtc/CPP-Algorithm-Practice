#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        while (str.size() > 8) {
            cout << str.substr(0, 8) << endl;
            str = str.substr(8);
        }
        cout << str.append(8-str.size(), '0') << endl;
    }
}