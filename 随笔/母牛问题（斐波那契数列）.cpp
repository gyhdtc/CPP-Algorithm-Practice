// Problem //
/* ĸţ�ӵ�4�꿪ʼ��ÿһ������1ͷĸţ;һ��ʼֻ��1ͷţ��N����м�ͷ; */
// Solution //
/* 1(1) 1(2) 1(3) 2(4.1) 3(5.2.1) 4(6.3.2.1) 6(6.4.3.2.1.1) 쳲���������*/ 
/* F(N) = F(N-1) + F(N-3) */
#include <iostream>
#include <GYH_INIT.h>
#define N 100
using namespace std;
int main(){
	GYH_init();
	int Bull[N]={0};
	for(int i = 0; i < N; i ++){
		if(i < 4){
			Bull[i] = 1;
		}else{
			Bull[i] = Bull[i-1] + Bull[i-3];
		}
	}
	cout<<N<<"����У� "<<Bull[N-1]<<" ͷţ��"<<endl;
	return 0;
}

