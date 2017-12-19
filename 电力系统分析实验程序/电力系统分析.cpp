/*
xdG1=0.23;xdG2=0.14;Us1=0.105;Us2=0.105;
x1=0.4;b1=0.0000028;l1=120;l2=80;l3=70;
SG1N=120;SG2N=60;ST1N=120;ST2N=60;Uav=115;
SB=120;UB=Uav;
Xd1=xdG1*SB/SG1N;Xd2=xdG2*SB/SG2N;
XT1=Us1*SB/ST1N;XT2=Us2*SB/ST2N;
Xl1=x1*l1*SB/(Uav*Uav);Xl2=x1*l2*SB/(Uav*Uav);Xl3=x1*l3*SB/(Uav*Uav);
Bl1=b1*l1*Uav*Uav/SB/2;Bl2=b1*l2*Uav*Uav/SB/2;Bl3=b1*l3*Uav*Uav/SB/2;
*/ 
#include <iostream>
#include <Algorithm>
#include <string>
#include <vector>
using namespace std;
//已知条件 
double xdG1=0.23,xdG2=0.14;
double Us1=0.105,Us2=0.105;
double x1=0.4,b1=0.0000028;
double L1=120,L2=80,L3=70;
double SG1N=120,SG2N=60;
double ST1N=120,ST2N=60;
double UB=115,SB=120;
//已知条件
//计算 
double Xd1=xdG1*SB/SG1N, Xd2=xdG2*SB/SG2N;							//发电机
double XT1=Us1*SB/ST1N ,  XT2=Us2*SB/ST2N;								//变压器
double XL1=x1*L1*SB/(UB*UB),XL2=x1*L2*SB/(UB*UB),XL3=x1*L3*SB/(UB*UB);	//线路电抗 
double BL1=b1*L1*UB*UB/SB/2,BL2=b1*L2*UB*UB/SB/2,BL3=b1*L3*UB*UB/SB/2;//电路导纳
//计算
#define max 10
int large=5;	//初始化矩阵大小 5 

struct Node{
	double y=0;	//导纳值 
	double r=0;	//电抗值 
	int flag=0;	//判断是否连接 
	string obj;	//判断是否为线路,Y-yes,N-no,--- 
};				//导纳矩阵节点
struct Lnode{
	int x=0; 
	int y=0;
	double r=0;
	double b=0;
};				//线路，x、y记载了连接点,线路参数 
void initY(Node y[max][max],Lnode x[3]){
	y[0][2].flag=1;y[0][0].obj="N";
	y[2][0].flag=1;y[2][0].obj="N";
	y[2][3].flag=1;y[2][3].obj="Y";
	y[2][4].flag=1;y[2][4].obj="Y";
	y[3][1].flag=1;y[3][1].obj="N";
	y[3][2].flag=1;y[3][2].obj="Y";
	y[3][4].flag=1;y[3][4].obj="Y";
	y[4][2].flag=1;y[4][2].obj="Y";
	y[4][3].flag=1;y[4][3].obj="Y";
	y[1][3].flag=1;y[1][3].obj="N";
	y[0][0].flag=1;y[0][0].obj="-";
	y[1][1].flag=1;y[1][1].obj="-";
	y[2][2].flag=1;y[2][2].obj="-";
	y[3][3].flag=1;y[3][3].obj="-";
	y[4][4].flag=1;y[4][4].obj="-";
	x[0].x=2;
	x[0].y=3;
	x[1].x=2;
	x[1].y=4;
	x[2].x=4;
	x[2].y=3;
} 
void y_getvalue(Node y[max][max],Lnode x[3]){
	y[0][0].y=-1/Xd1-1/XT1;
	y[1][1].y=-1/Xd2-1/XT2;
	y[2][2].y=-1/XL1-1/XL2-1/XT1+BL1+BL2; 
	y[3][3].y=-1/XL1-1/XL3-1/XT2+BL1+BL3;
	y[4][4].y=-1/XL2-1/XL3+BL2+BL3;
	y[0][2].y=1/XT1;y[2][0].y=y[0][2].y;
	y[1][3].y=1/XT2;y[3][1].y=y[1][3].y;
	y[2][3].y=1/XL1;y[3][2].y=y[2][3].y;
	y[2][4].y=1/XL2;y[4][2].y=y[2][4].y;
	y[3][4].y=1/XL3;y[4][3].y=y[3][4].y;
	x[0].r=XL1;
	x[0].b=BL1;
	x[1].r=XL2;
	x[1].b=BL2;
	x[2].r=XL3;
	x[2].b=BL3;
}
void out_yY(Node y[max][max],int large){
	for(int i=0;i<large;i++){
		for(int j=0;j<large;j++){
				if(y[i][j].y!=0.0)printf("j%-10.3f	",y[i][j].y);
				else printf("%-10.1f	",y[i][j].y);
		}
		cout<<"\n";
	}
}
void out_yDL(Node y[max][max],int x,int large){
	x--;
	for(int i=0;i<large;i++){
		for(int j=0;j<large;j++){
			if(i==x||j==x)continue;
			if(y[i][j].y!=0.0)printf("j%-10.3f	",y[i][j].y);
			else printf("%-10.1f	",y[i][j].y);
		}
		cout<<"\n";
	}
}
void out_yXDL(Node y[max][max],Lnode ll[3],int h,int large){
	y[ll[h].x][ll[h].x].y=y[ll[h].x][ll[h].x].y-1/ll[h].r-ll[h].b/2;
	y[ll[h].y][ll[h].y].y=y[ll[h].y][ll[h].y].y-1/ll[h].r-ll[h].b/2;
	y[ll[h].y][ll[h].x].y=0;
	y[ll[h].x][ll[h].y].y=0;
	for(int i=0;i<large;i++){
		for(int j=0;j<large;j++){
			if(y[i][j].y!=0.0)printf("j%-10.3f	",y[i][j].y);
			else printf("%-10.1f	",y[i][j].y);
		}
		cout<<"\n";
	}
}
void copy_Y(Node y[max][max],Node copyy[max][max],int large){
	for(int i=0;i<large;i++){
		for(int j=0;j<large;j++){
			copyy[i][j]=y[i][j];
		}
	}
}
int main(){	
	int large=5;
	Node y[max][max];					//两点连接，flag=1，否则为0，构成一张图表
	Lnode x[3]; 						//连接线路的两点 
	initY(y,x);							//初始化 
	y_getvalue(y,x);					//节点导纳赋值，线路参数赋值 
	out_yY(y,large);						//输出导纳 
	Node copyy[max][max];					//复制一个图表
	int DL; 
	copy_Y(y,copyy,large);					//y给copyy 
	cout<<"输入短路节点：";
	cin>>DL;
	if(DL!=0)out_yDL(copyy,DL,large);			//短路节点计算 
	copy_Y(y,copyy,large);					//y给copyy
	cout<<"输入中点短路线路编号：";
	cin>>DL;
	if(DL!=0)out_yXDL(copyy,x,DL-1,large);		//短路线路 
	copy_Y(y,copyy,large);					//y给copyy
	char k; 								//用以判断Y/N 
	int gyh,shou=0,wei=0;
	double daona;
	while(1){
		cout<<"是否拓展矩阵？请输入N或Y，N=NO，Y=YES:"<<"\n";
		cin>>k;
		if(k!='Y')return 0;
		else{
			cout<<"添加连枝请输入1，添加树枝请输入2"<<"\n";
			cin>>gyh;
			if(gyh==1){
				cout<<"输入节点1、2、导纳，回车结束。";
				cin>>shou>>wei>>daona;
				copyy[shou-1][shou-1].y=copyy[shou-1][shou-1].y+daona;
				copyy[shou-1][wei-1].y =copyy[shou-1][wei-1].y -daona;
				copyy[wei-1][shou-1].y =copyy[wei-1][shou-1].y -daona;
				out_yY(copyy,large);
			}
			if(gyh==2){
				large++; 
				cout<<"最大节点数:"<<large<<",为您自动添加节点->"<<large+1<<"\n";
				cout<<"请输入与之相连的节点编号和导纳，回车结束:"; 
				cin>>shou>>daona;
				wei=large;
				copyy[shou-1][shou-1].y=copyy[shou-1][shou-1].y+daona;
				copyy[shou-1][wei-1].y =copyy[shou-1][wei-1].y -daona;
				copyy[wei-1][shou-1].y =copyy[wei-1][shou-1].y -daona;
				out_yY(copyy,large);
			}
		}
	}
}

