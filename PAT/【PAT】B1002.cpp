#include <iostream>
#include <vector>
using namespace std;
int main(){
	string s;
	string a[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"}; 
	vector<int> gyh;
	int sum = 0;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		sum += s[i] - '0';
	}
	while(sum != 0){
		gyh.push_back(sum%10);
		sum /= 10;
	}
	for(int i = gyh.size() - 1; i >= 0; i--){
		if(i == gyh.size() - 1)
			cout << a[gyh[i]];
		else 
			cout << " " << a[gyh[i]];
	}
	return 0;
}

