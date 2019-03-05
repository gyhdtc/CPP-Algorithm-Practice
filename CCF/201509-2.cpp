#include <iostream>
using namespace std;
int main(){
    int ye, d;
    cin >> ye >> d;
    int i;
    int a[13] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
    int b[13] = {0,31,60,91,121,152,182,213,244,274,305,335,366};
    if(ye % 4 == 0 && ye % 100 != 0 || ye % 400 == 0){
        for(i = 0; i < 12; i++)
            if(b[i] <= d && d <= b[i+1]) break;
        cout << i+1 << endl;
        cout << d - b[i] << endl;
    }
    else{
        for(i = 0; i < 12; i++)
            if(a[i] <= d && d <= a[i+1]) break;
        cout << i+1 << endl;
        cout << d - a[i] << endl;
    }
    return 0;
}