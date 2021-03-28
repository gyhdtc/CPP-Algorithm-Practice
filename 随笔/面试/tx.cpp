#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

// void shiftup(vector<int>& a, int n, int cur) {
//     int p = (cur - 1) / 2;
//     while (cur > 0) {
//         if (a[cur] < a[p]) {
//             int t = a[p];
//             a[p] = a[cur];
//             a[cur] = t;

//             cur = p;
//             p = (cur - 1) / 2;
//         }
//         else {
//             break;
//         }
//     }
// }
// void heap(vector<int>& a, int n, int i) {
//     int l = 2*i+1;
//     int r = 2*i+2;
//     int largest = i;
//     if (l < n && a[l] > a[largest]) largest = l;
//     if (r < n && a[r] > a[largest]) largest = r;
//     if (largest != i) {
//         swap(a[i], a[largest]);
//         heap(a, n, largest);
//     }
// }
// void del(vector<int>& a) {
//     a[0] = a[a.size()-1];
//     a.erase(a.end()-1);
//     heap(a, a.size()-1, 0);
// }
// void out(vector<int>& a) {
//     for (int i = 0; i < a.size(); ++i) cout << a[i] << " ";
//     cout << endl;
// }

void out(vector<int>& a) {
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> a {1,2,3,4,5,6};
    a.resize(10);
    vector<int>::iterator a1 = a.begin();
    vector<int>::iterator a2 = a.begin()+1;
    vector<int>::iterator a3 = a.begin()+2;
    vector<int>::iterator e = a.begin()+5;
    a.insert(a2, 0);
    cout << *(a.begin()+5) << endl;
    cout << *e << endl;
    cout << (a.begin()+5 == e ? 1 : 2) << endl;
    out(a);
}