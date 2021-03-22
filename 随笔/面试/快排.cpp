#include <iostream>
#include <time.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// int middle(vector<int>& a, int start, int end)
// {
//     int i = start;
//     int j = end;
//     int temp = a[i];

//     while (i < j)
//     {
//         while (a[j] >= temp && i < j) --j;
//         a[i] = a[j];
//         while (a[i] < temp && i < j) ++i;
//         a[j] = a[i];
//     }
//     a[i] = temp;
//     return i;
// }
// void quicksort(vector<int>& a, int start, int end)
// {
//     if (start == end) return;
//     int i = middle(a, start, end);
//     if (start <= end)
//     {
//         quicksort(a, start, i);
//         quicksort(a, i+1, end);
//     }
// // }
//     int middle(vector<int>& a, int i, int j) {
//         int t = a[i];
//         while (i < j) {
//             while (i < j && t <= a[j]) --j;
//             a[i] = a[j];
//             while (i < j && a[i] < t) ++i;
//             a[j] = a[i];
//         }
//         a[i] = t;
//         return i;
//     }
//     int qucik(vector<int>& a, int i, int j, int k) {
//         // cout << i << endl;
//         int t = a[i];
//         int index = middle(a, i, j);
//         // cout << index << "-" << k << endl;
//         // _sleep(2);
//         // int len = j - i + 1;
//         if (index == j-k+1) {
//             return t;
//         }
//         else if (index < j-k+1) {
//             // cout << 1 << endl;
//             return qucik(a, index+1, j, k);
//         }
//         else {
//             return qucik(a, 0, index-1, k-j+index);
//         }
//     }
//     int findKthLargest(vector<int>& nums, int k) {
//         return qucik(nums, 0, nums.size()-1, k);
//     }
vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> res;
        int len = a.size();
        sort(a.begin(), a.end());
        if (len < 3 || a[0] >= 0)
            return res;
        // cout << 1;
        for (int i = 0; i < len; ++i) {
            // cout << 2;
            int left = i+1, right = len-1;
            while (left < right && left < len) {
                int t = a[i] + a[left] + a[right];
                if (t == 0) {
                    // cout << 3;
                    res.push_back(vector<int>({a[i], a[left], a[right]}));
                    int temp_l = a[left];
                    int temp_r = a[right];
                    while (left < len && a[left] == temp_l) left ++;
                    while (right > left && a[right] == temp_r) right --;
                }
                else if (t > 0) {
                    left ++;
                }
                else {
                    right --;
                }
            }
        }
        return res;
    }

void vectorp(vector<vector<int>>& a) {
    for (auto i : a) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
} 
int main()
{
    // 递增
    // vector<int> a {3,2,1,5,6,4};
    // // cout << findKthLargest(a, 2) << endl;
    // set<int> s (a.begin(), a.end());
    // int k = 2;
    // int len = s.size();
    // // cout << s.size();
    // for (int i = 0; i < len-k; i++) {
    //     int t = *s.begin();
    //     // cout <<  t << endl;
    //     s.erase(t);
    // }
    // cout << *s.begin() << endl;
    vector<int> a {-1,0,1,2,-1,-4};
    vector<vector<int>> res;
    res = threeSum(a);
    vectorp(res);
    return 0;
}