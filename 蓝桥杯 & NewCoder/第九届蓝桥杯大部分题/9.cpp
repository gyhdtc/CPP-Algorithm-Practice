#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1010;
const int inf=0x3f3f3f3f;
int a[maxn],b[maxn],c[maxn];//余数为i的前三大的数字 
int main(){
	memset(a,0xff,sizeof(a));//-1
	memset(b,0xff,sizeof(b));
	memset(c,0xff,sizeof(c));
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		int tmp;
		cin>>tmp;
		int yu=tmp%k;
		if(a[yu]>=tmp||b[yu]>=tmp||c[yu]>=tmp)continue;
		if(a[yu]==-1||b[yu]==-1||c[yu]==-1){
			if(a[yu]==-1)a[yu]=tmp;
			else if(b[yu]==-1)b[yu]=tmp;
			else c[yu]=tmp;
		}
		else{
			if(a[yu]<tmp)a[yu]=tmp;
			else if(b[yu]<tmp)b[yu]=tmp;
			else if(c[yu]<tmp)c[yu]=tmp;
		}
		//cout<<yu<<" "<<a[yu]<<" "<<b[yu]<<" "<<c[yu]<<endl;
	}
	int res=0;
	for(int i=0;i<=k-1;++i){
		for(int j=0;j<=k-1;++j){
			int l=k-i-j;
			if(l<0)l+=k;
			int aa,bb,cc;
			if(i!=j&&i!=l&&j!=l){//三个数余数不同 
				aa=max(a[i],max(b[i],c[i]));
				bb=max(a[j],max(b[j],c[j]));
				cc=max(a[l],max(b[l],c[l]));
			}else if(i==j&&j==l){//三个数余数相同 
				aa=a[i],bb=b[j],cc=c[l];
			}else{//两个数余数相同 
				if(i==j){
					cc=max(a[l],max(b[l],c[l]));
					int minn=min(a[i],min(b[i],c[i]));
					if(minn==c[i])aa=a[i],bb=b[i];
					else if(minn==a[i])aa=b[i],cc=c[i];
					else aa=a[i],cc=c[i];
				}else if(i==l){
					bb=max(a[j],max(b[j],c[j]));
					int minn=min(a[i],min(b[i],c[i]));
					if(minn==c[i])aa=a[i],bb=b[i];
					else if(minn==a[i])aa=b[i],cc=c[i];
					else aa=a[i],cc=c[i];
				}else if(j==l){
					aa=max(a[i],max(b[i],c[i]));
					int minn=min(a[j],min(b[j],c[j]));
					if(minn==c[j])aa=a[j],bb=b[j];
					else if(minn==a[j])aa=b[j],cc=c[j];
					else aa=a[j],cc=c[j];
				} 
			}
			if(aa==-1||bb==-1||cc==-1)continue;
			res=max(res,aa+bb+cc); 
		}
	}
	cout<<res;
	return 0;
}
