#include<iostream>
using namespace std;
int main()
{
int t;
cin>>t;
int n;
int a[100000];
while(t)
{
int mod2=0;
int mod4=0;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>a[i];
}
for(int i=0;i<n;i++)
{
if(a[i]%4==0)
mod4++;
else if(a[i]%2==0)
mod2++;
}
if(mod4>=(n-mod2-mod4))
cout<<"Yes"<<endl;
else
cout<<"No"<<endl;

t--;
}
}
