#include <iostream>
#include <algorithm>
using namespace std;
bool cmp1(int a, int b){
	return a >= b; 
}
int main(){
	int n, max, min, t;
	int a[4];
	cin >> n;
	while(1){
		for(int i = 0; i < 4; i++)
			a[i] = 0;
		for(int i = 0; i < 4; i++){
			a[i] = n % 10;
			n = n / 10;
		}
		sort(a, a + 4, cmp1);
		max = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
		min = a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];
		n = max - min;
		//cout << max << " " << min << " " << n;
		printf("%04d - %04d = %04d\n", max, min, n);
		if(n == 6174 || n == 0)
			break;
	}
	return 0;
}

