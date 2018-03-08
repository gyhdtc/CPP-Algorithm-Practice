#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#define X 10
#define Y 10
using namespace std;
int many = 0;
int sx,sy;
int gx,gy;
int longth = 101;
int d[X][Y];
typedef pair<int,int> p;
list<p> que;
list<p> out;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};// move X or Y
const char maze[X][Y]={
/*
 0   1   2   3   4   5   6   7   8   9
*/
'#','S','#','#','#','#','#','#','.','#',// 0
'.','.','.','.','.','.','#','.','.','#',// 1
'.','#','.','#','#','.','#','#','.','#',// 2
'.','.','.','.','.','.','.','.','.','.',// 3
'#','#','.','#','#','.','#','#','#','#',// 4
'.','.','.','.','#','.','.','.','.','#',// 5
'.','#','#','#','#','#','#','#','.','#',// 6
'.','.','.','.','.','.','.','.','.','.',// 7
'.','#','#','#','#','.','#','.','#','.',// 8
'.','.','.','.','.','.','.','.','G','#',// 9
};


void init(){
	for(int i = 0; i < X; i ++)
	for(int j = 0; j < Y; j ++){
		if(maze[i][j] == 'S'){
			sx = i;
			sy = j;
		}
		else if(maze[i][j] == 'G'){
			gx = i;
			gy = j;
		}
		d[i][j] = 0;
	}
}


bool inside(int x,int y){
	if(x < 0 || x >= X || y < 0 || y >= Y)
	return false;
	else
	return true;
}


void compare(){
	if(longth > que.size()){
		longth = que.size();
		out.clear();
		out = que;
	}
}


void print_out_list(){
	cout<<"--------------------The min distance is "<<many<<"-------------------"<<endl;
	int gyh[X][Y]={0};
	list<p>::iterator it = out.begin();
	pair<int,int> q;
	for(; it != out.end(); it ++){
		q = *it;
		cout<<"("<<q.first<<","<<q.second<<")"<<" -> ";
		gyh[q.first][q.second] = 1;
	}
	cout<<"E N D"<<endl;
	for(int i = 0; i < X; i ++){
		for(int j = 0; j < Y; j ++){
			if(gyh[i][j] == 0)
			cout<<"  "<<gyh[i][j]<<"  ";
			else
			cout<<" ["<<gyh[i][j]<<"] ";
		}
		cout<<endl<<endl;
	}
}


void print_que_list(){
	int gyh[X][Y]={0};
	list<p>::iterator it = que.begin();
	pair<int,int> q;
	for(; it != que.end(); it ++){
		q = *it;
		cout<<"("<<q.first<<","<<q.second<<")"<<" -> ";
		gyh[q.first][q.second] = 1;
	}
	cout<<"E N D"<<endl;
	for(int i = 0; i < X; i ++){
		for(int j = 0; j < Y; j ++){
			if(gyh[i][j] == 0)
			cout<<"  "<<gyh[i][j]<<"  ";
			else
			cout<<" ["<<gyh[i][j]<<"] ";
		}
		cout<<endl<<endl;
	}
}


void bfs(int x,int y){
	d[x][y] = 1;
	que.push_back(p(x,y));
	if(x == gx && y == gy){
		many++;
		cout<<"case : "<<many<<endl;
		compare();
		print_que_list();
	}
	for(int i = 0; i < 4; i ++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(inside(nx,ny) && maze[nx][ny] != '#' && d[nx][ny] == 0){
		bfs(nx,ny);
		}
	}
	d[x][y] = 0;
	que.pop_back();
	return;
}


int main(){
	cout<<"         _         "<<endl;
	cout<<"       {{+}}       "<<endl;
	cout<<"      {{   }}      "<<endl;
	cout<<"      {{   }}      "<<endl;
	cout<<"      {{   }}      "<<endl;
	cout<<"      {{   }}      "<<endl;
	cout<<"      {{   }}      "<<endl;
	cout<<"      {{   }}      "<<endl;
	cout<<"      {{   }}      "<<endl;
	cout<<"      {{   }}      "<<endl;
	cout<<"      {{   }}      "<<endl;
	cout<<"      {{   }}      "<<endl;
	cout<<"  *** {{   }} ***  "<<endl;
	cout<<" *****{{   }}***** "<<endl;
	cout<<"**   **-----**   **"<<endl;
	cout<<"**   **-----**   **"<<endl;
	cout<<" *****-------***** "<<endl;
	cout<<"  ***---------***  "<<endl;
	init();
	bfs(sx,sy);
	print_out_list();
	return 0;
}


