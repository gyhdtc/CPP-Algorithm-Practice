#include <iostream>

using namespace std;
int main(){
	int n;
	int a[3] = {0};
	cin >> n;
	for(int i = 0; i < 3; i++){
		a[i] = n % 10;
		n /= 10;
	}
	for(int i = 0; i < a[2]; i++){
		cout << "B";
	}
	for(int i = 0; i < a[1]; i++){
		cout << "S";
	}
	for(int i = 0; i < a[0]; i++){
		cout << i + 1;
	}
	return 0;
}

