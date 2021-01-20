#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int debug = 0;
template <typename T> ostream& operator<< (ostream&, vector<T>& );
template <typename T> ostream& operator<< (ostream&, queue<T>& );

template<typename T>
class myVector : public vector<T> {
    public:
    explicit myVector () : vector<T>() {}
    explicit myVector (size_t n, const T& val = T()) : vector<T>(n,val) {}
    myVector (const myVector& x) : vector<T>(x) {}
    myVector (const vector<int>& x) : vector<T>(x) {}
    myVector (initializer_list<T> il) : vector<T>(il) {}
    myVector (T *first, T *last) : vector<T>(first,last) {} 

    T& operator[] (size_t n);
    const T& operator[] (size_t n)const;    
    
    friend ostream& operator<<<T> (ostream& output, vector<T>& arr);
};
template<typename T>
ostream& operator<< (ostream& output, vector<T>& arr) {
    for (int i = 0; i < arr.size(); i ++) {
        output << arr[i] << " ";
    }
    output << endl;
    return output;
}
template<typename T>
T& myVector<T>::operator[] (size_t n) {
    return vector<T>::operator[](n);
}

template <typename T>
class myQueue : public queue<T> {
    public:
        myQueue() : queue<T>() {};

        friend ostream& operator<<<T> (ostream& output, queue<T>& q);
};
template <typename T>
ostream& operator<< (ostream& output, queue<T>& q) {
    while (!q.empty()) {
        output << q.front() << " ";
        q.pop();
    }
    output << endl;
    return output;
}

class Solution {
    public:
        // 归并排序
        void mergeSort(myVector<int>& nums) {
            realMergeSort(nums, 0, nums.size()-1);
        }
        // 单调队列 （滑动窗口最大值）
        myVector<int> maxSlidingWindow(myVector<int>&, int);
        
    private:
        void realMergeSort(myVector<int>&, int, int);
        void merge_Sort(myVector<int>&, int, int, int);
};
void Solution::realMergeSort(myVector<int>& a, int l, int r) {
    if (l >= r)
        return;
    int mid = (l+r)/2;
    realMergeSort(a, l, mid);
    realMergeSort(a, mid+1, r);
    merge_Sort(a, l, r, mid);
}
void Solution::merge_Sort(myVector<int>& a, int l, int r, int mid) {
    vector<int> aux(a.begin()+l, a.begin()+r+1);
    int k = l;
    int i = l, j = mid +1;
    for (k; k <= r; k++) {
        if (i > mid) {
            a[k] = aux[j-l];
            j ++;
            continue;
        }
        else if (j > r) {
            a[k] = aux[i-l];
            i ++;
            continue;
        }
        else if (aux[i-l] < aux[j-l]) {
            a[k] = aux[i-l];
            i ++;
        }
        else {
            a[k] = aux[j-l];
            j ++;
        }
    }
}
myVector<int> Solution::maxSlidingWindow(myVector<int>& nums, int k) {
    myVector<int> res;
    queue<int> temp;
    for (int i = 0; i < nums.size(); i++) {
        if (!temp.empty() && temp.front() < nums[i]) {
            while(!temp.empty()) temp.pop();
        }
        else if (temp.size() == k)
            temp.pop();
        temp.push(nums[i]);
        if (i >= k-1)
            res.push_back(temp.front());
    }
    return res;
}

int main() {
    Solution mysolution;
    // 归并排序
    // myVector<double> gyh1 {7.2,5,6,4};
    // mysolution.mergeSort(gyh1);
    // cout << gyh1;
    
    // 单调队列 滑动窗口最大值
    // myVector<int> gyh2 {1,-1};
    // myVector<int> answer;
    // int k = 1;
    // answer = mysolution.maxSlidingWindow(gyh2, k);
    // cout << answer;

    // 测试 MyQueue 的 cout <<
    // myQueue<int> q1;
    // myQueue<double> q2;
    // for (int i = 0; i < 10; i++) {
    //     q1.push(i);
    //     q2.push(i/2.0);
    // }
    // cout << q1;
    // cout << q2;
    return 0;
}