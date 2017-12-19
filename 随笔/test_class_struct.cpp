#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
using namespace std;
 
class jisuanqi{
	public:
		double x;
		double y;
		char   c;
		jisuanqi(string name){
			cout<<"======¼ÆËãÆ÷======\n"; 
			cout<<name<<"\n\n";
		}
		
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
double jisuanqi::jia(double const &x,double const &y){
	return x+y;
}
double jisuanqi::jian(double const &x,double const &y){
	return x-y;
}
double jisuanqi::chen(double const &x,double const &y){
	return x*y;
}
double jisuanqi::chu(double const &x,double const &y){
	if(y == 0){
		 return 9999999999999999999999.0;
	}
	else 
		 return x/y;
}
int main(){
	jisuanqi b("gyh");
	double x,y;
	char   c;
	cin>>x>>c>>y;
	while(c != 'q'){
		b.x=x;
		b.c=c;
		b.y=y;
		cout<<"result: "<<b.doit()<<"\n";
		cin>>x>>c>>y;
	}
	return 0;
}


