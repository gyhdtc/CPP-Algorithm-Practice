#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;
double measure(double G1,int x,int y,int radio,int &tot){
	double G2;
	if( ((G1-x)*(G1-x) + y*y) > (radio*radio) ){
		G2=x+sqrt(radio*radio-y*y);
		if(G2>G1) tot++;
	}
	return G2;
}

int main(){
	cout<<"               |   岛屿         "<<endl;
	cout<<"               |            "<<endl;
	cout<<"--------雷达---|---雷达------->X"<<endl;
	cout<<"               |            "<<endl;
	cout<<"               |   陆地         "<<endl;
	int radio;
	int number;
	int x,y;
	int tot=0;
	int i=0,t=0;
	double G;
	cout<<"岛屿数量：";
	cin>>number;
	cout<<"雷达半径：";
	cin>>radio;
	if( radio<=0 || number<0 ){
		cout<<"error!";
		return 0;
	}
	cout<<"输入"<<number<<"行"<<"岛屿坐标："<<endl; 
	vector<int> Xzhou;
	vector<int> Yzhou;
	while( i<number ){
		cin>>x>>y;
		if( y<=0 || y>radio ){
			cout<<"Y坐标无效(Y<="<<radio<<")，重新输入"; 
			continue;
		}
		Xzhou.push_back(x);
		Yzhou.push_back(y);
		i++;
	}
	for(i=0; i < number; i++ ){
		for(int j=i; j < number; j++){
			if(Xzhou[i]>Xzhou[j]){
   				t = Xzhou[i];
				Xzhou[i] = Xzhou[j];
				Xzhou[j] = t;
				t = Yzhou[i];
				Yzhou[i] = Yzhou[j];
				Yzhou[j] = t;
			}
		}
	}
	if( number==0 ){
		cout<<tot<<endl;
		return 0;
	}
	G=Xzhou[0]+sqrt(radio*radio-Yzhou[0]*Yzhou[0]);
	tot++;
	for(i=1;i<number;i++){
		G=measure(G,Xzhou[i],Yzhou[i],radio,tot);
	}
	cout<<"case # "<<tot<<endl;
	return 0;
}


