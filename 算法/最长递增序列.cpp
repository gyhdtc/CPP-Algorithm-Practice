#include <iostream>
#include <vector>
using namespace std;
int main() {
    int x,len=0;
    vector<int> a;
    cin>>x;
    While(x != -1){
        a.append(x);
        len++;
    }
    int i=1;
    int start=0;
    int lent=1;
    while(i<len){
        if(a[i]<=a[i-1])start=i;
        if(lent<i-start+1)lent=i-start+1;
        i++;
    }
    cout<<lent;
    return 0;
}
