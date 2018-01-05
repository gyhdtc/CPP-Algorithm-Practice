/*
这题可以算是 寻找根节点 方法的应用吧。
在 普林斯顿大学算法公开课上学到了  
用 nums[i] == i 来判断是否为根节点
此题用 nums[i] >= 0 来判断是否遍历过，
如果没有遍历过，则将下一个的序号 i 设置为 nums[i]
*/

/* 
==================QUESTIONS=======来源于 LeetCode 565=========================================
A zero-indexed array A of length N contains all integers from 0 to N-1.
Find and return the longest length of set S, where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... } subjected to the rule below.

Suppose the first element in S starts with the selection of element A[i] of index = i, 
the next element in S should be A[A[i]], and then A[A[A[i]]]… 
By that analogy, we stop adding right before a duplicate element occurs in S.
*/

/*
Example 1:

Input: A = [5,4,0,3,1,6,2]
Output: 6
Explanation: 
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

One of the longest S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
*/

/*
Note:

    N is an integer within the range [1, 20,000].
    The elements of A are all distinct.
    Each element of A is an integer within the range [0, N-1].

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ret = 0;
        int j;
        for(int i = 0; i < nums.size(); i++){
            int longest = 0; 
            j = i;
            while(nums[j] >= 0){
                int t = nums[j];
                nums[j] = -1;
                j = t;
                longest ++;
            }
            ret = max(ret , longest);
        }
        return ret;
    }
};

int main(){
	int i;
	vector<int> gyh;
	cin>>i;
	while(i == 200001 ){
		gyh.push_back(i);
		cin>>i;
	}
	Solution a;
	cout<<a.arrayNesting(gyh)<<endl;
	return 0;
}
