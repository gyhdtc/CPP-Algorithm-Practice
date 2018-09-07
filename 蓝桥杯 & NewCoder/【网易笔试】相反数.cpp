#include <iostream>
using namespace std;
int main(){
	int x,t;
	int y=0;
	cout<<"123";
	cin>>x;
	t=x;
	while(x>0){
		y = y*10 +x%10;
		x = x/10;
	}
	y=y+t;
	cout<<y;
	return 0;
}

