#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 10
#define M (2*N-1)

class HTNode{               // 树中的节点结构 
    public:
        int weight;
        int parent, lchild, rchild;
};
class HTCode{               // 编码的结构
    public:
        char data;
        char code[N];
        int weight;
};
// 初始化节点，输入节点个数， 字符 和 权重
void Init(HTCode hc[], int &n){
    int i;
    cout << "Input n = ";
    cin >> n;
    printf("Inout %d character\n", n);
    for (i = 1; i <= n; i++) {
        cin >> hc[i].data;
    }
    printf("Inout %d weight\n", n);
    for (i = 1; i <= n; i++) {
        cin >> hc[i].weight;
    }
}
// 选择最小的两个值
void Select(HTNode ht[], int n, int &s1, int &s2){
    int i;
    for (i = 1; i <= n && ht[i].parent != 0; i++);
    s1 = i;
    for (i = 1; i <= n; i++) {
        if (ht[i].parent == 0 && ht[i].weight < ht[s1].weight) s1 = i;
    }
    for (i = 1; i <= n; i++) {
        if (ht[i].parent == 0 && i != s1)
            break;
    }
    s2 = i;
    for (i = 1; i <= n; i++) {
        if (ht[i].parent == 0 && i != s1 && ht[i].weight < ht[s2].weight) s2 = i;
    }
}
// 哈夫曼树
void HuffmanCode(HTNode ht[], HTCode hc[], int n){
    char cd[N];
    int i;
    int m, c, f;
    int s1, s2;
    int start;
    m = 2 * n - 1;
    // 这还是利用 hc 对 ht哈夫曼编码树进行初始化的简单构造
    for (i = 1; i <= m; i++) {
        if (i <= n) {
            ht[i].weight = hc[i].weight;
        }
        ht[i].parent = ht[i].lchild = ht[i].rchild = 0;
    }
    // 这里就是根据哈夫曼树的定义进行操作
    for (i = n+1; i <= m; i++) {
        Select(ht, i-1, s1, s2);
        ht[s1].parent = i;
        ht[s2].parent = i;
        ht[i].lchild  = s1;
        ht[i].rchild  = s2;
        ht[i].weight  = ht[s1].weight + ht[s2].weight;
        cout << ht[i].weight;
    }
    // 这里构成哈夫曼编码
    cd[n-1] = '\0';
    for (i = 1; i <= n; i++) {
        start = n - 1;
        for (c = i, f = ht[i].parent; f; c = f, f = ht[f].parent) {
            if (ht[f].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        }
        strcpy(hc[i].code, &cd[start]);
    }
}

int main(){
    int i, m, n, w[N+1];
    HTNode ht[M+1];
    HTCode hc[N+1];
    Init(hc, n);            // 初始化哈夫曼节点
    HuffmanCode(ht, hc, n); // 构造Huffman树
    for (i = 1; i <= n; i++)  
        printf("\n%c---%s", hc[i].data, hc[i].code);
    cout << endl;  
    return 0;
}