#include <iostream>
#include <list>
using namespace std;
list<char> gyh;
unsigned long long n;
void out(list<char> temp){
	for (list<char>::iterator it=temp.begin(); it!=temp.end() ; ++it)
    cout << *it;
    return;
}
void toubi(unsigned long long x){
	if(x>n/2 && x!=n){
		gyh.pop_back();
		return;
	}
	if(x==n){
		out(gyh);
		return;
	}
	gyh.push_back('2');
	toubi(x*2+2);
	gyh.push_back('1');
	toubi(x*2+1);
	gyh.pop_back();
	return;
}
int main(){
	cin>>n;
	toubi(0);
	return 0;
}

