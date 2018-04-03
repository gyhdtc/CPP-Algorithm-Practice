#include <iostream>
#include <cstring>
using namespace std;
int main(){
	string a;
	int i=0;
	int max=1,type=1,t=0;
	double gyh;
	cin>>a;
	while(a[i]!='\0'){
		i++;
	} 
	if(i==1){
		cout<<1;
		return 0;
	}
	for(int j=1;j<i;j++){
		if(a[j]==a[j-1])max++;
		else{
			type++;
			t+=max;
			max=1;
		}
	}
	t+=max;
	gyh=1.0*t/type;
	gyh=gyh*1000;
	if(int(gyh)%10>=5)gyh=gyh/1000+10/1000;
	gyh=gyh/1000;
	printf("%.2lf",gyh);
	return 0;
}

