#include<iostream>
using namespace std;
int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isLeapYear(int year){
	if((year%400==0)||(year%100!=0&&year%4==0))return true;
	return false;
}
int main(){
	int currWeekday=2;//1901.1.1
	int res=0;//result
	for(int year=1901;year<=2000;++year){
		if(isLeapYear(year))month[2]=29;
		else month[2]=28;
		for(int mon=1;mon<=12;++mon){
			for(int day=1;day<=month[mon];++day){
				if(currWeekday==1)++res;
				currWeekday=(currWeekday+1)%7;
			}
		}
	}
	cout<<res;
	return 0;
}
