/*
Excel����õİ칫�����ÿ����Ԫ����Ψһ�ĵ�ַ��ʾ��
���磺��12�е�4�б�ʾΪ����D12������5�е�255�б�ʾΪ��IU5����
��ʵ�ϣ�Excel�ṩ�����ֵ�ַ��ʾ����������һ�ֱ�ʾ������RC��ʽ��ַ�� 
��12�е�4�б�ʾΪ����R12C4������5�е�255�б�ʾΪ��R5C255����
��������ǣ���д����ʵ�ִ�RC��ַ��ʽ�������ַ��ʽ��ת����
�����롢�����ʽҪ��
�û�������һ������n��n<100������ʾ��������n���������ݡ�
���������n��������RC��ʽ��Excel��Ԫ���ַ��ʾ����
���������n�����ݣ�ÿ����ת����ĳ����ַ��ʾ����
    ���磺�û����룺
2
R12C4
R5C255
    �����Ӧ�������
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
