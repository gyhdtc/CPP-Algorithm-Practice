#include <iostream>
#include <vector>
#include <list>
#include <deque> 
#include <algorithm>
#include <string>
using namespace std;
/*
大体思路 
定义一个结构体，里面有数字 一个 INT 存储ASCII码，计算时用以生成 数字  或者  算子。
一个char 用以保存这个东西是 数字 还是 算子。 
*/ 

struct Suan{
	int num;//ASCII码 
	int flag;//
}suan={0,0};
class Calculate{
	public:
		double resltu;
		char   c;
		Calculat(string name){
			int len=name.size();
			cout<<"==========Calculate==========\n"; 
			cout<<"==========";
			if(len>9)
				for(int i=0;i<9;i++)cout<<name[i];
			else 
			cout<<name;
			for(int i=0;i<19-len;i++)cout<<"=";
		}
		deque<Suan> duiwu;
		double doit(){
			return Howdo(x,y,c);
		}
	
	private:
		double jia (double const &x,double const &y);
		double jian(double const &x,double const &y);
		double chen(double const &x,double const &y);
		double chu (double const &x,double const &y); 
		
		double Howdo(double &x,double &y,char &c){
			
			switch(c){
				case '+':return jia (x, y);
					 break;
				case '-':return jian(x, y);
					 break;
				case '*':return chen(x, y);
					 break;
				case '/':return chu (x, y);
					 break;
				default:;
			}
		}
};
double Calculate::jia(double const &x,double const &y){
	return x+y;
}
double Calculate::jian(double const &x,double const &y){
	return x-y;
}
double Calculate::chen(double const &x,double const &y){
	return x*y;
}
double Calculate::chu(double const &x,double const &y){
	if(y == 0){
		 return 9999999999999999999999.0;
	}
	else 
		 return x/y;
}
int main(){
	Calculate b("gyhisdtc.");
	char   c;
	cin>>c;
	while(c != 'q'){

	}
	return 0;
}


