#include <vector>
#include <string>
#include <iostream>
using namespace std;

int findindex(int start, int end, vector<int>& a, int target) {
    int i;
    for (i = start; i <= end; ++i) {
        if (a[i] > target) return i;
    }
    return i;
}

void shit(int start, int end, vector<int>& a) {
    // cout << start << end << endl;
    if (start > end) return;
    else if (start == end) {
        cout << a[start] << " ";
        return;
    }
    else {
        int index = findindex(start+1, end, a, a[start]);
        if (index <= end) {
            shit(start+1, index-1, a);
            shit(index, end, a);
        }
        else {
            shit(start+1, index-1, a);
        }
        
    }
}

int main() {
    vector<int> gyh;
    char c;
    int t;
    do {
        scanf("%d", &t);
        gyh.push_back(t);
        scanf("%c", &c);
    } while (c == ' ');

    // for (int i = 0; i < gyh.size(); ++i) {
    //     cout << gyh[i] << endl;
    // }
    shit(0, gyh.size()-1, gyh);
}