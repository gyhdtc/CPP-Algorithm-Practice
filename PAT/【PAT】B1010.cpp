#include <iostream>
#include <vector>
using namespace std;
int main(){
	int xishu, cishu;
	int flag = 0;
	while(cin >> xishu >> cishu){
		if(flag == 0 && cishu == 0)
			cout << "0 0";
		if(cishu != 0){
			if(flag == 1)cout << " ";
			cout << xishu * cishu << " " << cishu - 1;
			flag = 1;
		}
	} 
	return 0;
}

