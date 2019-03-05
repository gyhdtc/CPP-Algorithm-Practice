#include <iostream>
using namespace std;
int main(){
    string a;
    cin >> a;
    int i = 0;
    int sum = 0;
    while (a[i] != '\0') {
        sum += a[i] - '0';
        i++;
    }
    cout << sum;
    return 0;
}