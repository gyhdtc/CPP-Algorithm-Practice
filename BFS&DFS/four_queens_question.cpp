#include<vector>
#include<iostream>
using namespace std;
class Solution{
public:
	int line;
	vector<int> reslte;
	Solution(int a){
		line=a;
		cout<<"start porject......"<<endl;
		cout<<"Get the large of chessboard is : "<<line<<endl;
	}
	void getmesolution(){
		vector<int> gyh(line,0);
		vector<vector<int>> chessboard(line,gyh);
		dfs(chessboard);
	}
private:
	void outvector(const vector<int> copy){
		for(int i=0;i<line;i++)
			cout<<copy[i]<<"	";
	}
	void dfs(vector<vector<int>> chessboard){
		
	}
	void setone(int i,int j,vector<vector<int>> chessboard){
		
	}
};
int main(){
	int line;
	cout<<"input the number of queen:"<<endl;
	cin>>line;
	Solution putdonwthequeen(line);
	return 0;
}