#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
typedef long long ll;
using namespace std;
const int N = 500010;
int cnt, n , m, a[N];
double b[N];
double ans = 0, avg, tot, nowavg;
int main() {
    cin >> n >> m;
    for (int i=1;i<=n;++i)scanf("%d",&a[i]);
    sort(a+1, a+n+1);
    nowavg = avg = 1.0*m/n;
    tot = 0;
    for (int i=1;i<=n;++i){
        if (a[i] < nowavg){
            ans += (a[i]-avg)*(a[i]-avg);
            tot += a[i];
        }else{
            nowavg = (m-tot)/(n-i+1);
            if (a[i] >= nowavg){
                ans += (nowavg-avg)*(nowavg-avg)*(n-i+1);
                break;
            }
            i--;
        }
    }
    ans=ans/n;
    ans = sqrt(ans);
    printf("%.4f\n", ans);
    return 0;
}
