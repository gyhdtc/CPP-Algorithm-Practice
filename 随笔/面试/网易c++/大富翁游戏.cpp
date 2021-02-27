#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int x;
    cin >> x;
    char c = '1';
    vector<int> a;
    a.push_back(0);
    int len = 1;
    int t;
    do
    {
        scanf("%d",&t);
        a.push_back(t);
        len ++;
    } while(c=getchar()!='\n'); 

    vector<int> dp(len, 0);
    dp[0] = x;
    int gold = 0;
    for (int i = 1; i < len; i++)
    {
        if (i-1 >= 0 && dp[i-1] >= 2)
            dp[i] = max(dp[i], dp[i-1]-2+a[i]);
        if (i-2 >= 0 && dp[i-2] >= 3)
            dp[i] = max(dp[i], dp[i-2]-3+a[i]);
        gold = max(gold, dp[i]);
    }
    cout << gold << endl;
    return 0;
}