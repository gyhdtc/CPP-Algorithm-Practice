#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> a;
	int k = 0;
	for(int i = 0; i < 10; i++){
		int t;
		cin >> t;
		while(t--){
			a.push_back(i);
			k++;
		}
	}
	for(int i = 0; i < k; i++){
		if(a[0] == 0 && a[i] != 0){
			int t = a[i];
			a[i] = 0;
			a[0] = t;
			break;
		}
	}
	for(int i = 0; i < k; i++) cout << a[i];
	return 0;
}

