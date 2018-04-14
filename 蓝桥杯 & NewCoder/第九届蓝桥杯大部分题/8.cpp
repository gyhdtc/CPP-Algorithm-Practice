#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 1005;
struct node {
	int x, y;
	node(){}
	node(int xx,int yy):x(xx),y(yy){}
};
int n, cnt;
int vis[maxn][maxn];//���������Ƿ񱻷��ʹ� 
char mp[maxn][maxn];//��ͼ 
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
vector<node> d[100000];//��i����ͨ������ĵ� 
bool judge(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)return false;
	if (vis[x][y])return false;
	return true;
}
void find(int x, int y) {//Ѱ��������
	d[cnt].push_back(node(x, y));//��cnt��½�صĵ� 
	vis[x][y] = 1;
	for (int i = 0; i< 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (judge(tx, ty)&&mp[tx][ty]!='.')
			find(tx, ty);
	}
}
void dfs(int x, int y) {//��ʴ
	vis[x][y] = 1;
	for (int i = 0; i< 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (judge(tx, ty)) {
			if (mp[tx][ty] == '#') vis[tx][ty] = 1;
			else dfs(tx, ty);
		}
	}
}
int main(){
	cin >> n;
	getchar();// \n
	for (int i = 0; i < n; ++i)scanf("%s", mp[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (mp[i][j] == '#' && !vis[i][j]) {
				cnt++;//��cnt��½�� 
				find(i, j);
			}
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i< n; i++)
		for (int j = 0; j< n; j++)
			if (mp[i][j] == '.' && !vis[i][j])
				dfs(i, j);
	int ans = 0;
	for (int i = 1; i <= cnt; i++) {//�ж���ɵ���ĵ㻹�ڲ���
		int j, k = d[i].size();
		for (j = 0; j < k; j++)
			if (vis[d[i][j].x][d[i][j].y] == 0)
				break;
		if (j == k)ans++;
	}
	cout << ans << endl;
    return 0;
}
