#include<iostream>
using namespace std;
int main(){   
	int n,a = 0,b = 0;
    for(int i=1;i<=100;++i){
    	cin>>n;
        while(n%2 == 0)a++,n /= 2;
        while(n%5 == 0)b++,n /= 5;
    }
    cout<<min(a,b)<<endl;
    return 0;
}
