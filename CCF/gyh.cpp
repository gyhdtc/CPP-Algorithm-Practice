#include <iostream>
using namespace std;
int main(){
    int s = 0;
    int t[10] = {0,1,1,1,1,1,1,1,1,0};
    for (int i = 0; i < 10; i++) {
        if (t[i] == 1) {
            while(t[i] == 1 && i < 10) {
                i++;
            }
            s++;
        }
    }
    cout << s;
    return 0;
}