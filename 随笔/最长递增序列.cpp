#include <iostream>
#include <vector>
using namespace std;
int main() {
    int x,len=0;
    vector<int> a;
	cin>>x;
	while(x != -1){
		a.push_back(x);
        len++;
		cin>>x;
	}
	int i=1;
    int start=0;
    while(i<len){
        if(a[i]<=a[i-1])start=i;
        if(len<i-start+1)len=i-start+1;
        i++;
    }
    cout<<len;
	return 0;
}