#include <iostream>
#include <vector>
/*
Sample Input:
7
2 3 1 5 7 6 4后序（左右根） 
1 2 3 4 5 6 7中序（左根右） 
Sample Output:
4 1 6 3 5 7 2
*/
using namespace std;
vector<int> zhong, hou, pre(100000, -1);
int n;
void xian(int root, int start, int end, int index){
	if(start > end)
		return;
	int i = start;
	while(i < end && hou[root] != zhong[i])// find root node
		i++;
	pre[index] = hou[root];
	xian(root - 1 - end + i, start, i - 1, 2*index+1);
	xian(root - 1, i + 1, end, 2*index+2);
}
int main(){
	cin >> n;
	zhong.resize(n);
	hou.resize(n);
	int cnt = 0;
	for(int i = 0; i < n; i++)cin >> hou[i];
	for(int i = 0; i < n; i++)cin >> zhong[i];
	xian(n-1, 0, n - 1, 0); 
	for(int i = 0; i < pre.size(); i++) {
        if (pre[i] != -1) {
            if (cnt != 0) printf(" ");
            printf("%d", pre[i]);
            cnt++;
        }
        if (cnt == n) break;
    }
	return 0;
}

