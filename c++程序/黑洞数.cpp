//任意一个5位数，比如：34256，
//把它的各位数字打乱，重新排列，可以得到一个最大的数：65432，一个最小的数23456。
//求这两个数字的差，得：41976，把这个数字再次重复上述过程（如果不足5位，则前边补0）。
//如此往复，数字会落入某个循环圈（称为数字黑洞）。
//比如，刚才的数字会落入：[82962, 75933, 63954, 61974] 这个循环圈。
#include <iostream>
#include <vector>
#include <algorithm>
#define number 5
using namespace std;
vector<int> heidong;
vector<int> zonghe;
vector<int>::iterator it;
int get_max_number(int x){
	int a[number]={0,0,0,0,0};
	int max=0;
	int t=0,i;
	for(i=0;i<number;i++){
		a[i]=x%10;
		x=x/10;
	}
	for(i=0;i<number;i++)
		for(int j=i+1;j<number;j++)if(a[i]<a[j])swap(a[i],a[j]);
	
	for(i=0;i<number;i++)
		max=max*10+a[i];
	return max;
}
int get_min_number(int x){
	int a[number]={0,0,0,0};
	int min=0,i;
	for(i=0;i<number;i++){
		a[i]=x%10;
		x=x/10;
	}
	for(i=0;i<number;i++)
		for(int j=i+1;j<number;j++)if(a[i]>a[j])swap(a[i],a[j]);
		
	for(i=0;i<number;i++)
		min=min*10+a[i];
	return min;
}
void findheidong(int x){
	int max,min,y;
	max=get_max_number(x);
	min=get_min_number(x);
	y=max-min;
	it=find(heidong.begin(),heidong.end(),y);
	if( it == heidong.end() ){
		heidong.push_back(y);
	}
	else if( (find(zonghe.begin(),zonghe.end(),*it)) != zonghe.end() ){
		heidong.clear();
		return;
	}
	else if(*it==0){
		heidong.clear();
		return;
	}
	else{
		int i=0;
		for(;it!=heidong.end();it++){
			zonghe.push_back(*it);
			if(i==0)cout<<"[";
			if( (it+1) != heidong.end() ){
				cout<<*it<<","<<" ";
			}
			else{
				cout<<*it<<"]"<<"\n";
			}
			i++;
		}
		heidong.clear();
		return;
	}
	findheidong(y);
}
int main(){
	int i=10000;
	for(i;i<100000;i++)findheidong(i);
	return 0;
}
