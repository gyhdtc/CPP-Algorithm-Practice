#include <iostream>
#include <vector>
using namespace std;
int main(){
	int nums;
	char o;
	int temp = 0;
	int cha  = 0;
	int max  = 0;
	int hang; 
	cin >> nums >> o;
	int i = 1;
	while( (2 * i * i - 1) < nums){
		temp = 2 * i * i - 1;
		i ++;
	}
	cha  = nums - temp;
	if(i == 1){
		cout << o << endl;
		cout << cha - 1;
		return 0;
	} 
	hang = i-1;
	max  = 2 * hang -1;
	vector<int> out(max);
	out[hang-1] = 1;
	for(int j = hang-1, k = hang-1; j >= 0, k <= max-1;j--, k++){
		out[j] = 2*(hang-1-j) + 1;
		out[k] = 2*(k-hang+1) + 1;
	}
	for(int j = 0; j < max; j++){
		for(int a = 0; a < (max - out[j])/2; a++) cout << " ";
		for(int a = 0; a < out[j]; a++) cout << o;
		cout << endl;
	}
	cout << cha;
	return 0;
}
