#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
void trace(int n[],int len){
	int i = 1;
	int j = 0;
	int t = 0;
	for(;i < len;i ++){
		j = i;
		while( j >= 0 && n[j-1] > n[j]){
			t = n[j-1];
			n[j-1] = n[j];
			n[j] = t;
			j--;
		}
	}
}

void outarray(int n[],int len){
	for(int i = 0; i < len; i ++)
	cout<<n[i]<<" ";
	cout<<endl;
}

int main(){
	int a[15]={1,2,6,1,8,7,9,6,5,10,25,3,26,95,100};
	trace(a,15);
	 outarray(a,15);
	return 0;
}


