#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int debug = 0;

template<typename T>
class myVector : public vector<T> {
    public:
    explicit myVector () : vector<T>() {};
    explicit myVector (size_t n, const T& val = T()) : vector<T>(n,val) {}
    myVector (const myVector& x) : vector<T>(x) {}
    myVector (const vector<int>& x) : vector<T>(x) {}
    myVector (initializer_list<T> il) : vector<T>(il) {}
    myVector (T *first, T *last) : vector<T>(first,last) {} 

    T& operator[] (size_t n);
    const T&   operator[] (size_t n)const;    
    
    friend ostream& operator << (ostream& output, vector<int>& arr);
};
ostream& operator << (ostream& output, vector<int>& arr) {
    for (int i = 0; i < arr.size(); i ++) {
        output << arr[i] << " ";
    }
    cout << endl;
    return output;
}
template<typename T>
T& myVector<T>::operator[] (size_t n) {
    return vector<T>::operator[](n);
}

class Solution {
    public:
        void mergeSort(myVector<int>& nums) {
            realMergeSort(nums, 0, nums.size()-1);
        }
        friend ostream& operator << (ostream& output, Solution s);
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

int main() {
    myVector<int> gyh {7,5,6,4};
    Solution mysolution;
    mysolution.mergeSort(gyh);
    cout << gyh;
    return 0;
}