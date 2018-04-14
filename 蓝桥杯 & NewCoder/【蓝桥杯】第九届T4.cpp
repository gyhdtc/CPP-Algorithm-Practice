#include <iostream>
using namespace std;
int main(){
	int res=0;
	for(long long  i=3;i<=59084709587505;++i){
		long long temp=i;
		bool flag=false;
		while(temp%3==0){temp/=3;flag=true;}
		while(temp%5==0){temp/=5;flag=true;}
		while(temp%7==0){temp/=7;flag=true;}
		if(temp==1&&flag)++res;
	}
	cout<<res;
	return 0;
}

