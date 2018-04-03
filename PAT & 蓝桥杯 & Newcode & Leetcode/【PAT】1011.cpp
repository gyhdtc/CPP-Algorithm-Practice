#include <iostream>
using namespace std;
int main(){
	char a[3] = {'W','T','L'};
	double max[3] = {0.0};
	int maxindex[3] = {0};
	double temp;
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			cin>>temp;
			if(temp > max[i]){
				max[i] = temp;
				maxindex[i] = j; 
			} 
		}
	}
	printf("%c %c %c %.2lf",a[maxindex[0]],a[maxindex[1]],a[maxindex[2]],(max[0]*max[1]*max[2]*0.65-1)*2);
	return 0;
}

