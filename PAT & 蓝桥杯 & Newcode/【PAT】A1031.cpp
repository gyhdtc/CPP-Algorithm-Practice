#include <iostream>
using namespace std;
int main(){
	int len;
	int i, j, x;
	string s;
	cin>>s;
	len = s.size();
	if(len%3 == 0){
		for(i = 0, j = len - 1; i < len/3; i++, j--){
			cout<<s[i];
			for(int k = 0; k < len/3 -2; k++)
				cout<<" ";
			cout<<s[j]<<endl;
		}
		for(i; i <= j; i++)
			cout<<s[i];
	}else if(len%3 == 1){
		for(i = 0, j = len - 1; i < (len - 1)/3; i++, j--){
			cout<<s[i];
			for(int k = 0; k < len/3 - 1; k++)
				cout<<" ";
			cout<<s[j]<<endl;
		}
		for(i; i <= j; i++)
			cout<<s[i];
	}else{
		for(i = 0, j = len - 1; i < (len - 2)/3; i++, j--){
			cout<<s[i];
			for(int k = 0; k < len/3; k++)
				cout<<" ";
			cout<<s[j]<<endl;
		}
		for(i; i <= j; i++)
			cout<<s[i];
	}
	return 0;
}
