#include<vector>
#include<iostream>
using namespace std;
class Solution{
public:
	int line;
	int tot;
	int chessboard[3][50];
	vector<int> reslte;
	Solution(int a){
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
	void outvector(const vector<int> copy){
		for(int i=0;i<line;i++)
			cout<<copy[i]<<"	";
	}
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
int main(){
	int line;
	cout<<"input the number of queen:"<<endl;
	cin>>line;
	Solution putdonwthequeen(line);
	putdonwthequeen.getmesolution();
	cout<<"To sum up : "<<putdonwthequeen.tot<<endl;
	return 0;
}