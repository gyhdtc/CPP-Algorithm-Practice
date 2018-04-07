#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n, maxscore = -1, minscore = 101;
	string maxname, maxid;
	string minname, minid;
	cin >> n;
	while(n--){
		int temp;
		string tname, tid;
		cin >> tname >> tid >> temp;
		if(temp > maxscore){
			maxname = tname;
			maxid = tid;
			maxscore = temp;
		}
		if(temp < minscore){
			minname = tname;
			minid = tid;
			minscore = temp;
		}
	} 
	cout << maxname << " " << maxid;
	cout << endl;
	cout << minname << " " << minid;
	return 0;
}
