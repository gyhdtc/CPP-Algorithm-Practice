#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n][n];
    vector<int> x;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    int summax = n + n - 2;
    for (int sum = 0; sum <= summax; sum++){
        x.clear();
        
        if (sum < n){
            int num = sum + 1;
            for (int i = 0; i <= sum; i++){
                x.push_back(a[sum-i][i]);
            }
        }
        
        if (sum >= n){
            int num = summax - sum + 1;
            for (int i = n-1; i >= n-num; i--){
                x.push_back(a[i][sum-i]);
            }
        }

        if(sum % 2 == 0) {
            for (int j = 0; j < x.size(); j++)
            cout << x[j] << " ";
        }
        else {
            for (int j = x.size()-1; j >= 0; j--)
            cout << x[j] << " ";
        }
    }
    return 0;
}