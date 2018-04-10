#include <iostream>

using namespace std;
int main(){
	int a[10] = {0};
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		a[s[i] - '0']++;
	} 
	for(int i = 0; i < 10; i++){
		if(a[i] != 0){
			printf("%d:%d\n",i, a[i]);
		}
	}
	return 0;
}

