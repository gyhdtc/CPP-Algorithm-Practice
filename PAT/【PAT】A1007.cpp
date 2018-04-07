#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    int leftout = 0,rightout = n - 1,temp = 0,sum = -1,templeft = 0;
    for(int i = 0;i < n;i++){
      cin>>a[i];
      temp = temp + a[i];
      if(temp > sum){
        sum = temp;
        rightout = i;
        leftout = templeft;
      }else if(temp < 0){
        temp = 0;
        templeft = i + 1;
    }
  }
  if(sum < 0)
    sum = 0;
  cout<<sum<<" "<<a[leftout]<<" "<<a[rightout];
  return 0;
}
