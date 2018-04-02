#include <iostream>
#include <vector>
using namespace std;
//hh:ff:mm-----01:34:67
bool campare(string a,string b){
  int ah,af,am,bh,bf,bm;
  ah = (a[0]-'0')*10 + a[1]-'0';
  af = (a[3]-'0')*10 + a[4]-'0';
  am = (a[6]-'0')*10 + a[7]-'0';
  
  bh = (b[0]-'0')*10 + b[1]-'0';
  bf = (b[3]-'0')*10 + b[4]-'0';
  bm = (b[6]-'0')*10 + b[7]-'0';
  
  if((ah * 3600 + af * 60 + am) < (bh * 3600 + bf * 60 + bm))return true;
  return false;
}
int main() {
    string person,in,out;
    string unlock,lock,unlockin,lockout;
    int num;
    cin>>num;
    cin>>person>>in>>out;
    unlock = person;
    unlockin = in;
    lock = person;
    lockout = out;
    num--;
    while(num){
      cin>>person>>in>>out;
      if(campare(in,unlockin)){
      unlock = person;
      unlockin = in;
    }
      if(!campare(out,lockout)){
      lock = person;
      lockout = out;
    }
      num--;
  }
  cout<<unlock<<" "<<lock;
  return 0;
}
