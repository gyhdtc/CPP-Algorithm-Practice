#include <iostream>

using namespace std;
int main(){
	long long a, b;
	int da, db;
	int ta, tb;
	cin >> a >> da >> b >> db; 
	ta = 0;
	tb = 0;
	while(a != 0){
		if(a%10 == da){
			ta = ta * 10 + da;
		}
		a = a/10;
	}
	while(b != 0){
		if(b%10 == db){
			tb = tb * 10 + db;
		}
		b = b/10;
	}
	cout << ta + tb;
	return 0;
}

