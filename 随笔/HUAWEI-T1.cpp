#include <iostream>

using namespace std;

int main(){
	unsigned int arr[1000];
	unsigned int a,index = 0;
	while(cin>>a){
    	arr[index++] = a;
    	char ch = getchar();
    	if(ch == '\n')
    		break;
    }
    unsigned int x = 0X55555555;
    unsigned int y = 0Xaaaaaaaa;
    unsigned int i;
    for (i = 0; i < index; i++) {
    	unsigned int b1 = arr[i];
    	unsigned int b2 = b1 & x;
    	unsigned int b3 = b1 & y;
    	arr[i] = (b2 << 1) | (b3 >> 1);
	}
    
    unsigned int shit = arr[0];
    
    for (i = 0; i < index-1; i++) {
    	unsigned int b1 = arr[i];
    	unsigned int b2 = arr[i+1];
    	unsigned int b3 = ((b1 >> 2) & 0X3fffffff) | ((b2 & 0X00000003) << 30);
    	cout << b3 << " ";
	}
    unsigned int b1 = arr[i];
    unsigned int b2 = shit;
    unsigned int b3 = ((b1 >> 2) & 0X3fffffff) | ((b2 & 0X00000003) << 30);
    cout << b3;

	return 0;

}

