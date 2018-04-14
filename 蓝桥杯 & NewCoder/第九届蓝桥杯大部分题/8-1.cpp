#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 1005;
int n;
int vis[maxn][maxn];
char mp[maxn][maxn];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
bool judge(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)return false;
	if (vis[x][y])return false;
	return true;
}
void dfs(int x, int y) {//—∞’“œ‡¡¨µ„
	vis[x][y] = 1;
	for (int i = 0; i< 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (judge(tx, ty)&&mp[tx][ty]=='#')
			find(tx, ty);
	}
}
int main(){
	int cnt=0;
	cin >> n;
	getchar();// \n
	for (int i = 0; i < n; ++i)scanf("%s", mp[i]);
	for (int i = 0; i< n; i++)
		for (int j = 0; j< n; j++)
			if (mp[i][j] == '#' && !vis[i][j]) {
				dfs(i, j);
				++cnt;
			}
    return 0;
}
