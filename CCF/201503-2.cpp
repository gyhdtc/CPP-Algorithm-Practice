#include <iostream>
using namespace std;
int main(){
    int n;
    int t;
    int num = 0;
    int a[1001] = {0};
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> t;
        a[t] ++;
    }
    for(int i = 0; i < 1001; i++) {
        if(a[i] != 0) num++;
    }
    for(int i = 0; i < num; i++) {
        int max = 0;
        for(int j = 0; j < 1001; j++) {
            if(a[j] > a[max]) max = j;
            else if(a[j] == a[max] && j < max) max = j; 
        }
        cout << max << " " << a[max] << endl;
        a[max] = 0;
    }
    return 0;
}