#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
	Solution(string name){
		cout<<"Start project "<<name<<"!";
	}
	deque<char> get;
	deque<char> help;
	deque<char> copy;
	int digit;
	int result;
};
void outdeque(deque<int> out){
	for (deque<int>::iterator it = out.begin(); it!=out.end(); ++it)
		cout << ' ' << *it;
	cout<<"\n";
}

int main(){
	cout<<"============Just Test==========\n";
	deque<int> test_deque1(5,1);
	deque<int> test_deque2(test_deque1);
	deque<int> test_deque3(test_deque2.begin(),test_deque2.end());
	int gyh[]={1,2,3,4,5};
	deque<int> test_deque4(gyh,gyh+sizeof(gyh)/sizeof(gyh[0]));
	outdeque(test_deque1);
	outdeque(test_deque2);
	outdeque(test_deque3);
	outdeque(test_deque4);
	cout<<"============Just Test==========\n";
	return 0;
}