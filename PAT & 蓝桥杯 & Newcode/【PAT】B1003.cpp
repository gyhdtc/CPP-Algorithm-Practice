#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	string s;
	cin >> n;
	while(n--){
		cin >> s;
		vector<int> A;
		int P_index = -1, T_index = -1;
		for(int i = 0; i < s.size(); i++){
			switch(s[i]){
				case 'P':
					P_index = i;
					break;
				case 'A':
					A.push_back(i);
					break;
				case 'T':
					T_index = i;
					break;
				default:
					break;
			}
		}
		// 排出了 有其他字母 没有P，A，T P、T个数大于1 的情况 
		if((A.size() + 2 != s.size()) || A.size() == 0 || P_index == -1 || T_index == -1){
			cout << "NO" << endl;
			//break;
		}else if(P_index * (T_index - P_index - 1) == s.size() - T_index - 1){
			cout << "YES" << endl;
			//break;
		}else
			cout << "NO" << endl; 
	} 
	return 0;
}

