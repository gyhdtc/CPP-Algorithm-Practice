/*
Excel是最常用的办公软件。每个单元格都有唯一的地址表示。
比如：第12行第4列表示为：“D12”，第5行第255列表示为“IU5”。
事实上，Excel提供了两种地址表示方法，还有一种表示法叫做RC格式地址。 
第12行第4列表示为：“R12C4”，第5行第255列表示为“R5C255”。
你的任务是：编写程序，实现从RC地址格式到常规地址格式的转换。
【输入、输出格式要求】
用户先输入一个整数n（n<100），表示接下来有n行输入数据。
接着输入的n行数据是RC格式的Excel单元格地址表示法。
程序则输出n行数据，每行是转换后的常规地址表示法。
    例如：用户输入：
2
R12C4
R5C255
    则程序应该输出：
D12
IU5
*/
#include <iostream>
#include <Algorithm>
#include <string> 
using namespace std;

int find_add_C(string str){
	int len=str.size();
	for(int i=0;i<len;i++){
		if(str[i]==67)return i;
	}
}
int main(){
	int number,i=0,j=0,k=0,m=0;
	int add_R=0,add_C;
	int r=0,c=0;
	string zimu="-ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string address[100];
	cin>>number;
	for(;number>0;number--){
		cin>>address[j];
		j++;
	}
	for(i=0;i<j;i++){
		int wei2=0,wei1=0;
		r=0;
		c=0;
		add_C=find_add_C(address[i]);
		for(k=add_R+1;k!=add_C;k++){
			r=r*10+address[i][k]-48;
		}
		for(m=add_C+1;m<address[i].size();m++){
			c=c*10+address[i][m]-48;
		}
		wei2=c/26;
		wei1=c%26;
		if(wei2==0){
			cout<<zimu[wei1]<<r<<"\n";
		}
		else{
			cout<<zimu[wei2]<<zimu[wei1]<<r<<"\n";
		}
	}
	return 0; 
}
