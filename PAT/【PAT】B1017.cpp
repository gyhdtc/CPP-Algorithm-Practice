#include <iostream>

using namespace std;
int main(){
	string s;
	int a;
	cin >> s >> a;
	int t, temp;
	t = (s[0] - '0') / a;
	if((t != 0 && s.size() > 1) || s.size() == 1)
		cout << t;
	temp = (s[0] - '0') % a;
	for(int i = 1; i < s.size(); i++){
		t = (temp * 10 + s[i] - '0') / a;
        cout << t;
        temp = (temp * 10 + s[i] - '0') % a;
	}
	cout << " " << temp;
	return 0;
}

