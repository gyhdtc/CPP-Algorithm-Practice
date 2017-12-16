/*
看下面的算式：
□□ x □□ = □□ x □□□
它表示：两个两位数相乘等于一个两位数乘以一个三位数。
如果没有限定条件，这样的例子很多。
但目前的限定是：这9个方块，表示1~9的9个数字，不包含0。
该算式中1至9的每个数字出现且只出现一次！
比如：
46 x 79 = 23 x 158
54 x 69 = 27 x 138
54 x 93 = 27 x 186
请编程，输出所有可能的情况！
*/

//！！！这个还没写完！！！

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
