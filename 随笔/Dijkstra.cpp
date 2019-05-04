#include <iostream>
#include <cmath>
using namespace std;
const int MAXINT = 32767;

struct Node
{
    int x;
    int y;
};

class Map
{
    public:
    int n;// n*n
    bool s[100];// 是否检测 Ni (i*n+j)点
    int dist[100];// 走入 Ni 点的代价
    int prev[100];// 走入 Ni 点要经过的点
    int A[100][100];// n*n个点，最多10000个
    int MAX_H;

    void print_A(){
        for (int i = 0; i < n*n; i++) {
            for (int j = 0; j < n*n; j++) {
                printf("%5d ", A[i][j]);
            }
            cout << endl;
        }
    }
    void print_s(){
        for (int i = 0; i < n*n; i++) {
            if (s[i] == true) cout << "T ";
            else cout << "F ";
        }
        cout << endl;
    }
    void print_dist(){
        for (int i = 0; i < n*n; i++) {
            printf("%2d -> %2d\n", i, dist[i]);
        }
        cout << endl;
    }
    void print_prev(){
        for (int i = 0; i < n*n; i++) {
            printf("%2d -> %2d\n", i, prev[i]);
        }
        cout << endl;
    }
};

void Creat_A(Map &a) {
    int n = a.n;
    int x_h[n][n-1];
    int x_s[n-1][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            cin >> x_h[i][j];
        }
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x_s[i][j];
        }
    }
    for (int i = 0; i < n*n; i++) {
        for (int j = 0; j < n*n; j++) {
            a.A[i][j] = MAXINT;
            if (i == j) a.A[i][j] = 0;
        }
    }
/*
    要构造 A 矩阵，我们输入一个n*n矩阵x[n][n]
    i j 表示 i*n+j 这个点
    他只会和他的上下左右点连通，
    连通代价是（要注意判断是否超界）：
    ← j>0  : A[i*n+j][i*n+j-1] = x[i][j-1]
    → j<n-1: A[i*n+j][i*n+j+1] = x[i][j+1]
    ↑ i>0  : A[i*n+j-n][i*n+j] = x[i+1][j]
    ↓ i<n-1: A[i*n+j+n][i*n+j] = x[i-1][j]
*/
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            a.A[i*n+j][i*n+j+1] = x_h[i][j];
            a.A[i*n+j+1][i*n+j] = x_h[i][j];
        }
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n; j++) {
            a.A[i*n+j][i*n+j+n] = x_s[i][j];
            a.A[i*n+j+1][i*n+j] = x_h[i][j];
        }
    }
}

int main(){
    Map gyh;
    int v0, v1, n;
    cin >> gyh.n;
    gyh.MAX_H = 2 * gyh.n;
    n = gyh.n;
/*
    range : 0 → n*n-1
    i = v0 / n;
    j = v0 % n;
*/
    cin >> v0;
    cin >> v1;
    Creat_A(gyh);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = i*n+j;
            gyh.s[num] = false;
            gyh.dist[num] = gyh.A[v0][i*gyh.n + j];
            if (gyh.dist[num] == MAXINT)
                gyh.prev[num] = -1;
            else
                gyh.prev[num] = v0;
        }
    }
    gyh.dist[v0] = 0;
    gyh.s[v0] = true;
    for(int i = 1; i < n*n; i++) {
        int mindist = MAXINT;
        int u = v0;
        // 找出当前未使用的点j的dist[j]最小值
        for(int j = 0; j < n*n; j++) {
            if((!gyh.s[j]) && gyh.dist[j] < MAXINT) {
                // u保存当前邻接点中距离最小的点的号码 
                u = j;
                mindist = gyh.dist[j];
            }
        }
        
        gyh.s[u] = true;
        
        for(int j = 0; j < n*n; j++)
        if((!gyh.s[j]) && gyh.A[u][j] < MAXINT)
        {
            //在通过新加入的u点路径找到离v0点更短的路径
            if(gyh.dist[u] + gyh.A[u][j] < gyh.dist[j])  
            {
                //更新dist
                gyh.dist[j] = gyh.dist[u] + gyh.A[u][j]; 
                //记录前驱顶点 
                gyh.prev[j] = u;
            }
        }
    }
    while(gyh.prev[v1] != v1) {
        printf("%d <- ", v1);
        v1 = gyh.prev[v1];
    }
    return 0;
}
/*
5
0
20
1 1 1 1
1 1 1 1
10 10 10 10
1 1 1 1
1 1 1 1
1 1 1 1 1
10 10 1 10 10
10 10 1 10 10
1 1 1 1 1
*/