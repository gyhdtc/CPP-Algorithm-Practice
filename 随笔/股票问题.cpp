#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int a[20]={1,4,-6,7,5,-9,-6,0,4,5,3,6,10,6,7,-10,1,2,4,-6};
	vector<int> gyh(a,a+20);
	int maxv = -200000000;
	int minn = gyh[0];
	for(int i = 0; i < gyh.size(); i++){
		maxv = max(maxv,gyh[i] - minn);
		minn = min(gyh[i] , minn);
	}
	cout<<maxv<<endl;
	return 0;
}
