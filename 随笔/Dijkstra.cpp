#include <iostream>
#include <cmath>
using namespace std;
const int MAXINT = 32767;

class Map
{
    public:
        int n;// n*n
        bool s[100];// 是否检测 Ni (i*n+j)点
        int dist[100];// 走入 Ni 点的代价
        int prev[100];// 走入 Ni 点要经过的点
        int A[100][100];// n*n个点，最多10个
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
    int t;
    for (int i = 0; i < n*n; i++) {
        for (int j = 0; j < n*n; j++) {
            a.A[i][j] = MAXINT;
        }
    }
    for (int num = 0; num < n*n; num++) {
        int i, j;
        a.A[num][num] = 0;
        i = num / n;
        j = num % n;
        if (i > 0) {
            a.A[num][num-n] = 1;
            a.A[num-n][num] = 1;
        }
        if (i < n-1) {
            a.A[num][num+n] = 1;
            a.A[num+n][num] = 1;
        }
        if (j > 0) {
            a.A[num][num-1] = 1;
            a.A[num-1][num] = 1;
        }
        if (j < n-1) {
            a.A[num][num+1] = 1;
            a.A[num+1][num] = 1;
        }
    }
    cin >> t;
    while(t != -1) {
        int i, j;
        i = t / n;
        j = t % n;
        if (i > 0) {
            a.A[t][t-n] = 2*n;
            a.A[t-n][t] = 2*n;
        }
        if (i < n-1) {
            a.A[t][t+n] = 2*n;
            a.A[t+n][t] = 2*n;
        }
        if (j > 0) {
            a.A[t][t-1] = 2*n;
            a.A[t-1][t] = 2*n;
        }
        if (j < n-1) {
            a.A[t][t+1] = 2*n;
            a.A[t+1][t] = 2*n;
        }
        cin >> t;
    }
}

int cha(int a, int b, int n){
    int cha = abs(a/n - b/n) + abs(a%n - b%n);
    return 2*cha;
}

int main(){
    Map gyh;
    int v0, v1, n;
    
    cin >> gyh.n;
    cin >> v0;
    cin >> v1;

    n = gyh.n;
    gyh.MAX_H = 2 * n;
    
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
            if((!gyh.s[j]) && gyh.dist[j] + cha(j, v1, n) < mindist) {
                // u保存当前邻接点中距离最小的点的号码 
                u = j;
                mindist = gyh.dist[j] + cha(j, v1, n);
            }
        }
        gyh.s[u] = true;
        if (u == v1) break;
        else cout << u << " ";
        for(int j = 0; j < n*n; j++)
        if((!gyh.s[j]) && gyh.A[u][j] < MAXINT)
        {
            //在通过新加入的u点路径找到离v1点更短的路径
            if(gyh.dist[u] + gyh.A[u][j] < gyh.dist[j])  
            {
                //更新dist
                gyh.dist[j] = gyh.dist[u] + gyh.A[u][j]; 
                //记录前驱顶点 
                gyh.prev[j] = u;
            }
        }
    }
    cout << endl;
    while(gyh.prev[v1] != v1) {
        printf("%d <- ", v1);
        v1 = gyh.prev[v1];
    }
    printf("%d", v1);
    return 0;
}
/*
5
2
22

1 1 1 1
10 10 10 10
10 10 10 10
10 10 10 10
1 1 1 1

1 10 1 10 1
1 10 1 10 1
1 10 10 10 1
1 10 10 10 1
*/

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
/*
10
41
49

1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 20 20 20 20 20 1 1
1 1 1 1 1 20 20 1 1
1 1 1 1 1 20 20 1 1
1 1 1 1 1 20 20 1 1
1 1 20 20 20 20 20 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1

1 1 1 1 1 1 1 1 1 1
1 1 1 20 20 20 20 1 1 1
1 1 1 20 20 20 20 1 1 1
1 1 1 1 1 1 20 1 1 1
1 1 1 1 1 1 20 1 1 1
1 1 1 20 20 20 20 1 1 1
1 1 1 20 20 20 20 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
*/