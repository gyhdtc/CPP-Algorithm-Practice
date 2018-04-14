#include<cstdio>
#include<iostream>
#include<queue>
#include<set>
#include<vector>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long> > num;
set<long long> n;
int ans = 0;
int main(){
	num.push(1);
	n.insert(1);
	while(true){
		long long tmp = num.top();
		num.pop();
		++ans;
		if(tmp==59084709587505)break;
		for(int i = 3; i <= 7; i += 2){//3 5 7
			long long number = tmp * i;
			if(!n.count(number)){
				num.push(number);
				n.insert(number);
			}
		}
	} 
	cout << ans <<endl;
	return 0;
} 
