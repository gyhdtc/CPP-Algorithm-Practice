/*
���������ʽ��
���� x ���� = ���� x ������
����ʾ��������λ����˵���һ����λ������һ����λ����
���û���޶����������������Ӻܶࡣ
��Ŀǰ���޶��ǣ���9�����飬��ʾ1~9��9�����֣�������0��
����ʽ��1��9��ÿ�����ֳ�����ֻ����һ�Σ�
���磺
46 x 79 = 23 x 158
54 x 69 = 27 x 138
54 x 93 = 27 x 186
���̣�������п��ܵ������
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> divide(int x){
	vector<int> number;
	number.push_back(x/10);
	number.push_back(x%10);
	return number;
}
int main(){
	int i=12,j=12;
	int len=2;
	vector<int> a(10,0);
	vector<int> x,y;
	for(i;i<100;i++){
		x=divide(i);
		if(a[x[0]]!=0||a[x[1]]!=0||x[1]==0)continue;
		else
			a[x[0]]++;
			a[x[1]]++;
		for(j=i+1;j<100;j++){
			y=divide(j);
			if(a[y[0]]!=0||a[y[1]]!=0||y[1]==0)continue;
			a[y[0]]++;
			a[y[1]]++;
		}
	}
	return 0;
}
