#include <iostream>
#include <cmath> 
/*
A1 = �ܱ�5����������������ż���ĺͣ� 
A2 = ����5������1�����ְ�����˳����н�����ͣ�������n1-n2+n3-n4...�� 
A3 = ��5������2�����ֵĸ����� 
A4 = ��5������3�����ֵ�ƽ��������ȷ��С�����1λ�� 
A5 = ��5������4��������������֡� 
*/
using namespace std;
int main(){
	int a1 = 0, a2 = 0, a3 = 0, a5 = 0;
	double a4 = 0.0;
	int ca1 = 0, ca2 = 0, ca3 = 0, ca4 = 0, ca5 = 0;
	int n, t, m = 0, g = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t;
		if(t%5 == 0 && t%2 == 0){
			a1 += t;
			ca1 ++;
		}
		if(t%5 == 1){
			a2 += t * pow(-1, m);
			ca2 ++;
			m ++;
		}
		if(t%5 == 2){
			a3 ++;
			ca3 ++;
		}
		if(t%5 ==3){
			a4 += t;
			ca4 ++;
			g ++;
		}
		if(t%5 == 4){
			ca5 ++;
			if(t > a5) a5 = t;
		}
	}
	if(ca1 != 0) cout << a1 << " ";
	else cout << "N ";
	
	if(ca2 != 0) cout << a2 << " ";
	else cout << "N ";
	
	if(ca3 != 0) cout << a3 << " ";
	else cout << "N ";
	
	if(ca4 != 0) cout << a4 << " ";
	else cout << "N ";
	
	if(ca5 != 0) cout << a5;
	else cout << "N";
	
	return 0;
}
