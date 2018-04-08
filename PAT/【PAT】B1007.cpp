#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int a){
	if(a == 1 || a == 2)
		return false;
	for(int i = 2; i < sqrt(a) + 1; i++){
		if(a%i == 0)
			return false;
	}
	return true;
}
int main(){
	int n, t = 3, cut = 0;
	cin >> n;
	if(n == 0 || n == 1 || n ==2){
		cout << cut;
		return 0;
	}
	while(t <= n){
		if(isprime(t) && isprime(t - 2)) cut++;
		t += 2;
	}
	cout << cut;
	return 0;
}

