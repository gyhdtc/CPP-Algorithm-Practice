#include <iostream>
#include <vector>
using namespace std;
const int N=1005;
int a[N];
 
int main()
{
	vector<int> nums;
	nums.push_back(5);
	cout << nums.size();
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int temp=3;
		if(i==1||i==n)//开始的店铺和最后的店铺除以2 
		  temp--;
		int ans=(a[i-1]+a[i]+a[i+1])/temp;
		printf("%d ",ans);
	}
	printf("\n");
	return 0;
}
