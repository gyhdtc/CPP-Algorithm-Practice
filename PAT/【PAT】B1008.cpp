#include <iostream>

using namespace std;
void resv(int a[], int start, int end){
	for(start, end; start < end; start++, end--){
		int t = a[start];
		a[start] = a[end];
		a[end] = t;
	}
}
int main(){
	int n, k;
	cin >> n >> k;
	int a[n]; 
	for(int i = 0; i < n; i++){
		cin >> a[i];
	} 
	k = k % n;
	resv(a, 0, n-k-1);
	resv(a, n-k, n-1);
	resv(a, 0, n-1);
	for(int i = 0; i < n; i++){
		if(i == 0)
			cout << a[i];
		else 
			cout << " " << a[i];
	}
	return 0;
}

