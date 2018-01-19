#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void bubblesort(int n[],int len){
	int i = 0, j;
	for(;i < len; i++){
		for(j = len -1; j > i; j--){
			if(n[j] < n[j-1])swap(n[j],n[j-1]);
		}
	} 
}
int main(){
	int a[20]={1,4,-6,7,5,-9,-6,0,4,5,3,6,10,6,7,-10,1,2,4,-6};
	
	bubblesort(a,20);
	
	for(int i = 0; i < 20; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}


