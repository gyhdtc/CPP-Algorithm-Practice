#include <cstdio>
#include <iostream>
using namespace std;

void shuchu(int a[], int n) {
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void SelectSort(int a[], int n) {
    cout << "-------Chosen-------" << endl;
    int k = 0;
    int temp;
    for (int i = 1; i <= n; i++) {
        temp = a[i];
        k = i;
        for (int j = i; j <= n; j++) {
            if (a[k] > a[j]) k = j;
        }
        a[i] = a[k];
        a[k] = temp;
        shuchu(a, n); 
    }
}
void InsertSort(int a[], int n) {
    cout << "-------Insert-------" << endl;
    for (int i = 2; i <= n; i++) {
        int temp = a[i], j = i;
        while (j > 1 && temp < a[j-1]) {
            a[j] = a[j-1];
            j --;
        }
        a[j] = temp;
        shuchu(a, n);
    }
}
int main(){
    int x;
    int n = 1;
    int a[1000] = {0};
    char c = '\0';
    while (c != '\n') {
        scanf("%d%c", &x, &c);
        a[n] = x;
        n ++;
    }
    n --;
    InsertSort(a, n);
    return 0;
}