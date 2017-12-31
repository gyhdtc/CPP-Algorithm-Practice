#include<vector>
#include<iostream>
using namespace std;
class Solution1{
public:
	int line;
	int tot;
	int chessboard[3][50];
	vector<int> reslte;
	Solution1(int a){
		line=a;
		tot=0;
		reslte.assign(line,0);
		for(int i=0;i<3;i++){
			for(int j=0;j<50;j++){
				chessboard[i][j]=0;
			}
		}
		cout<<"start porject......"<<endl;
	}
	void getmesolution(){
		dfs(0);
	}
private:
	void dfs(int cur){
		if(cur==line){
			for(int i=0;i<line;i++){
				for(int j=0;j<line;j++){
					if(reslte[i]==j)cout<<"x ";
					else
						cout<<"O ";
				}
				cout<<"---"<<reslte[i]<<endl;
			}
				cout<<endl;
				tot++;
		}
		else
		{
			for(int i=0;i<line;i++){
				if( !chessboard[0][i] && !chessboard[1][cur+i] && !chessboard[2][cur-i+line]){
					reslte[cur]=i;
					chessboard[0][i]=1;
					chessboard[1][cur+i]=1;
					chessboard[2][cur-i+line]=1;
					dfs(cur+1);
					chessboard[0][i]=0;
					chessboard[1][cur+i]=0;
					chessboard[2][cur-i+line]=0;
				}
			}
		}
	}
};
class Solution2{
public:
	int n,m;
	int x,y;
	int tot;
	vector<int> h;
	vector<vector<int>> chessboard;
	Solution2(int a,int b,int c,int d){
		n=a;//³¤
		m=b;//¿í
		x=c-1;
		y=d-1;
		tot=0;
		sum=n*m;
		h.assign(n,0);
		chessboard.assign(m,h);
		cout<<"start porject......"<<endl;
	}
	void getmesolution(){
		dfs(x,y,0);
	}
private:
	int sum;
	void dfs(int x,int y,int cur){
		if(inboard(x,y) && !chessboard[x][y]){
			cur++;
			chessboard[x][y]=cur;
			if(cur==sum){
				tot++;
				cout<<"Case# "<<tot<<endl;
				outchess(chessboard);
				cout<<endl;
				chessboard[x][y]=0;
				return;
			}
			else{
				dfs(x-1,y-2,cur);
				dfs(x-1,y+2,cur);
				dfs(x-2,y-1,cur);
				dfs(x-2,y+1,cur);
				dfs(x+1,y-2,cur);
				dfs(x+1,y+2,cur);
				dfs(x+2,y-1,cur);
				dfs(x+2,y+1,cur);
				chessboard[x][y]=0;
			}
		}
	}
	void outchess(vector<vector<int>> chessboard){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				printf("%4d",chessboard[i][j]);
			}
			cout<<endl;
		}
	}
	int inboard(int x,int y){
		if(x<n && x>=0 && y<m && y>=0)return 1; 
		return 0;
	}
};
int main(){
	char n;
	cout<<"input what question you want to know: ";
	cin>>n;
	if(n=='1'){
	int line;
		cout<<"input the number of queen:"<<endl;
		cin>>line;
		Solution1 putdonwthequeen(line);
		putdonwthequeen.getmesolution();
		cout<<"To sum up : "<<putdonwthequeen.tot<<endl;
	}
	if(n=='2'){
		int chang,kuan,x,y;
		cout<<"input ³¤/¿í:"<<endl;
		cin>>chang>>kuan;
		cout<<"input x/y:"<<endl;
		cin>>x>>y;
		Solution2 runhours(chang,kuan,x,y);
		runhours.getmesolution();
	} 
	return 0;
}