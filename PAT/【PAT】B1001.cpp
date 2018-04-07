#include <iostream>
using namespace std;
int main(){
	int n, i = 0;
	cin >> n;
	while(n != 1){
		n = n%2==0?n/2:(3*n+1)/2;
		i++;
	}
	cout << i;
	return 0;
}

