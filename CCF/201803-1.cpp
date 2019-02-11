#include <iostream>

using namespace std;

int main(){
	int num;
	int jiangli = 2;
	int total = 0;
	int num2 = 0;
	cin >> num;
	while (num != 0) {
		if (num == 2) num2 ++;
		else num2 = 0;
		
		if (num2 > 1) total += num + jiangli * (num2 - 1);
		else total += num;
		
		cin >> num;
	}
	cout << total;
	return 0;
}

