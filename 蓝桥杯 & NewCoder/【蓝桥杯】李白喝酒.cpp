#include <iostream>
#include <list> 
#include <GYH_INIT.h>
using namespace std;
int x = 0;
list<char> gyh;
void out(list<char> temp){
	for (list<char>::iterator it=temp.begin(); it!=temp.end() ; ++it)
    cout << ' ' << *it;
    cout << ' ' << x << endl;
    return;
}
void hejiu(int jiu,int dian,int hua){
	if(!(jiu >= 0 && dian <= 5 && hua <= 10 && jiu <= 10 - hua)){
		gyh.pop_back();
		return;
	}
	if( jiu == 0 && dian == 5 && hua ==10){
		x++;
		out(gyh);
		gyh.pop_back();
		return;
	}
	gyh.push_back('a');
	hejiu(jiu*2, dian+1, hua);
	gyh.push_back('b');
	hejiu(jiu-1, dian, hua+1);
	if( !gyh.empty() )gyh.pop_back();
	return;
}
int main(){
	int jiu = 2;
	int dian = 0;
	int hua = 0;
	hejiu(jiu,dian,hua);
	cout<<x<<endl;
	GYH_init(); 
	return 0;
}

