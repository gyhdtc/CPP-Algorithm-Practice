#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool isprime(int n) {
    if(n <= 1) return false;
    int sqr = int(sqrt(n * 1.0));
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}
int rev(int n, int d){
	vector<int> x;
	int out = 0;
	while(n > 0){
		x.push_back(n % d);
		n = n / d; 
	}
	for(int i = 0; i < x.size(); i++)
            out = out * d + x[i];
	return out;
} 
int main(){
	int n, d, re_n;
	cin >> n;
	while(n >= 0){
		cin >> d;
		re_n = rev(n, d);
		//cout<<re_n<<endl;
		if(isprime(n) && isprime(re_n))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		cin >> n;
	} 
	return 0;
}

