#include <iostream>
#include <vector>
using namespace std;

int mid(vector<int> a, int i, int j) {
    int t = a[i];
    while (i < j) {
        while (a[j] >= t && i < j) --j;
        a[i] = a[j];
        while (a[i] < t && i < j) ++i;
        a[j] = a[i];
    }
    a[i] = t;
    return i;
}

void quicksort(vector<int>& a, int left, int right) {
    if (left == right) return;
    int middle = mid(a, left, right);
}

int main() {
    vector<int> a {6,5,4,7,8,9,0,1,2};
    quicksort(a, 0, a.size()-1);
}