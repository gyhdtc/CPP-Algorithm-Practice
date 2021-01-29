#include <iostream>
#include <vector>
using namespace std;
// ---
// 继承 vector， 重载 << 运算符
template<typename T>
class myVector : public vector<T> {
    public:
    myVector (initializer_list<T> il) : vector<T>(il) {}

    T& operator[] (size_t n);    
    
    template<typename t>
    friend ostream& operator<< (ostream& output, vector<t>& arr);
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
// ---
// 求解
class Solution {
    public:
    int binarySearch(myVector<int>&, int);
    private:
    int realBinarysearch(myVector<int>&, int, int, int);
};
int Solution::binarySearch(myVector<int>& a, int target) {
    return realBinarysearch(a, 0, a.size()-1, target);
}
int Solution::realBinarysearch(myVector<int>& a, int start, int end, int t) {
    if (start > end) {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (a[mid] == t) {
        return mid;
    } else if (t < a[mid]) {
        return realBinarysearch(a, start, mid - 1, t);
    } else {
        return realBinarysearch(a, mid + 1, end, t);
    }
}
// ---
// main
int main() {
    myVector<int> v {1,3,5,7,6,9,10,14};
    Solution s;
    int target;
    int res;
    cout << "input a int : ";
    cin >> target;
    res = s.binarySearch(v, target);
    cout << "vector : " << v;
    cout << "answer : " << res;
    return 0;
}