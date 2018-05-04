#include <iostream>
using namespace std;
int main(){
	long long int a, b;
	long long int h, f, m;
	double temp;
	long long int t;
	cin >> a >> b;
	temp = (b - a)/100.0;
	t = (b - a)/100;
	if(temp - t >= 0.5) t = t + 1;
	h = t/3600;
	f = (t%3600)/60;
	m = t - h*3600 - f*60;
	printf("%02d:%02d:%02d", h, f, m);
	return 0;
}

