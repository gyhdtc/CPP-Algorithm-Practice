#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int n50 = n/50;
    int n30 = (n%50)/30;
    cout << n/10 + n50*2 + n30;
    return 0;
}