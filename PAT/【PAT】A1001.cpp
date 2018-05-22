#include <iostream>
//#include <cstdio>
//using namespace std;
int main(){
	int a, b, sum;
	char out[10];
	int len = 0;
	int flag = 0;
	cin>>a>>b;
	sum = a + b;
	if(sum < 0){
		flag = 1;
		sum = 0 - sum;
	}

	do{
		if(len == 3||len == 7){
			out[len] = ',';
			len ++;	
		}
		out[len] = sum%10 + '0';
		len ++;
		sum = sum/10;
	}while(sum > 0);
	
	if(flag == 1){
		out[len] = '-';
		len ++;
	}
	for(int i = len-1; i >= 0; i --){
		cout<<out[i];
	}
	return 0;
}

