#include <iostream>

int main() {
    int a,b,i=0;
    double shang;
    for(a=23;a<45;a++)
        for(b=a+1;b<=1100;b++){
            if((a*b)%45==0){
                shang=(a*b)/45;
                if((a+b)/shang==2)i++;
            }
        }
    cout<<i;
    return 0;
}
