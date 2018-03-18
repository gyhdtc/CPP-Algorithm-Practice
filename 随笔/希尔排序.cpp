#include <iostream>
#include <GYH_INIT.h>
using namespace std;
void shellsort(int x, int a[]);
void charge(int &a,int &b);
void outgyh(int a[]);

void shellsort(int x, int a[]){
	cout<<x<<":"<<endl;
	for(int i = x; i < 10; i ++){
		for(int j = i; j >= x; j -= x){
			if(a[j] < a[j-x])
			charge(a[j],a[j-x]);
		}
		outgyh(a);
	}
}
void charge(int &a,int &b){
	int t;
	t = a;
	a = b;
	b = t;
}
void outgyh(int a[]){
	for(int i = 0; i < 10; i ++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main(){
	GYH_init();
	int g[3] = {5,3,1};
	int a[10] = {4,8,9,1,10,6,2,5,3,7};
	for(int i = 0; i < 3; i ++){
		shellsort(g[i],a);
	}
	return 0;
}
