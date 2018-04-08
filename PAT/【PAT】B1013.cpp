#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int a){
	if(a == 1)
		return false;
	if(a == 2)
		return true;	
	for(int i = 2; i < sqrt(a) + 1; i++){
		if(a%i == 0)
			return false;
	}
	return true;
}
int main(){
	int n, m;
	cin >> n >> m;//第n个到第m个 
	int cut = 0;
	int num = 0;
	int i = 1;
	while(cut != m){
		if(isprime(i)){
			cut++;
			if(cut >= n){
				num++;
				if(num%10 != 0 && cut != m)
					cout << i << " ";
				else if(num%10 == 0 && cut != m)
					cout << i << endl;
				else
					cout << i;
			} 
		}
		i++;
	} 
	return 0;
}
