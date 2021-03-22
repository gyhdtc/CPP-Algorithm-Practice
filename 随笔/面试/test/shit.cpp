#include <iostream>
#include <vector>
using namespace std;
#define MAXINT 2e9
vector<int> shit({0,1,2,2,3,4,3,4,4,3,4});

int dfs(int n) {
    if (shit[n] != 0) return shit[n];
    else {
        int a = MAXINT, b = MAXINT;
        if (n % 2 == 0)
            a = dfs(n/2)+1;
        if (n % 3 == 0)
            b = dfs(n/3)+1;
        return min(a, min(b, dfs(n-1)+1));
    }
}

int main() {
    int t;
    cin >> t;
    shit.resize(2e9+1);
    cout << shit[90] << endl;
    while (t--) {
        int n;
        cin >> n;
        cout << dfs(n) << endl;
    }
}
// #include <iostream>
// #include <unordered_map>
// using namespace std;

// unordered_map<int, int> gyh;

// int dfs(int p) {
//     if (gyh.count(p) == 1) {
//         return gyh[p];
//     }
//     if(p == 1) {
//         return 1;
//     }
//     if(p == 2) {
//         return 2;
//     }
//     if(p == 3){
//         return 2;
//     }
//     int t1 = 2e9;
//     int t2 = 2e9;
//     int t3 = 2e9;
    
//     t1 = 1 + dfs(p-1);

//     if (p%2 == 0) {
//         t2 = 1 + dfs(p/2);
//     }
//     if(p%3 == 0) {
//         t3 = 1 + dfs(p/3);
//     }
//     int res = min(t1, min(t2, t3));
//     gyh[p] = res;
//     return res;
// }
// int main(){
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         cout << dfs(n) << endl;
//     }
//     return 0;
// } 