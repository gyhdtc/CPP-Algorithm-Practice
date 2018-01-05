/*
简单说下算法哈~
首先定义一个 int/int的 键值队 map ：cnt
通过观察程序可以知道，他的所有 键 保存了前 n 个数之和， 值 都为 1
并且 键 为 0 的 值 为 1，在之后的计算中要用到。

每次i＋＋的循环中，都要求出这个i之前所有数的和，这个直接利用循环累和。
在与目标k相减。
所得到的值，再去键值对中寻找，
如果找到了，说明这个键值对的序号 n 到现在的 i 之间的和，为目标 k 。
*/
//==================QUESTIONS=======来源于 LeetCode 565========================================= 
/*
Given an array of integers and an integer k, 
you need to find the total number of continuous subarrays whose sum equals to k.
*/

/* 
Example 1:

Input:nums = [1,1,1], k = 2
Output: 2

Note:

    The length of the array is in range [1, 20,000].
    The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

*/ 
#include <iostream>
#include <vector> 
#include <map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> cnt;
        cnt[0] = 1;
        int prefix = 0;
        int ret = 0;
        for(auto i : nums){
            prefix += i;
            ret += cnt[prefix-k];
            cnt[prefix] += 1;
        }
        return ret;
    }
};
int main(){
	Solution a;
	int k,ret;
	cin>>k;
	int x[]={3,4,7,2,-3,1,4,2};
	vector<int> nums(x,x+8);
	ret = a.subarraySum(nums,k);
	cout<<ret<<endl;
	return 0;
}
