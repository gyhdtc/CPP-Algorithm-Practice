// Problem //
/* 母牛从第4年开始，每一年生下1头母牛;一开始只有1头牛，N年后有几头; */
// Solution //
/* 1(1) 1(2) 1(3) 2(4.1) 3(5.2.1) 4(6.3.2.1) 6(6.4.3.2.1.1) 斐波那契数列*/ 
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
	cout<<N<<"年后有： "<<Bull[N-1]<<" 头牛！"<<endl;
	return 0;
}

