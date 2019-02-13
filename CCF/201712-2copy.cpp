#include <iostream>
using namespace std;
void reap(int B[],int n) {
    int i,j,k,s,t;
    int *A = new int[n] ;
    j = 0;
    cin >> k;
    int temp = k;
    s = n;
    for (i = 0; i < n; i++)
        A[i] = i+1;
    while (j < n) {
        t = s;
        s = 0;
        for (i = 0; i < t; i++) {
            if (--k != 0)
            A[s++] = A[i];  /*未被收割的白菜*/
            else {
                B[j++] = A[i];
                k = temp;  /*被收割的白菜*/
            }
        }
    }
    delete A;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    reap(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}