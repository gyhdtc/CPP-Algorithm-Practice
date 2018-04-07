#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	int arr[10000] = {0};
	int n, t, flag = 0;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> t;
		a[i] = t;
		while (t != 1) {
            if (t % 2 != 0) t = 3 * t + 1;
            t = t / 2;
            arr[t] = 1;
        }
	}
	sort(a, a + n, cmp);
	for(int i = 0; i < n; i++){
		if(arr[a[i]] == 0){
			if(flag == 1)
				cout << " ";
			cout << a[i];
			flag = 1;
		}
	}
	return 0;
}

