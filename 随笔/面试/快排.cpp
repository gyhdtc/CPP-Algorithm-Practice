#include <iostream>
#include <vector>
using namespace std;

int middle(vector<int>& a, int start, int end)
{
    int i = start;
    int j = end;
    int temp = a[i];

    while (i < j)
    {
        while (a[j] >= temp && i < j) --j;
        a[i] = a[j];
        while (a[i] < temp && i < j) ++i;
        a[j] = a[i];
    }
    a[i] = temp;
    return i;
}
void quicksort(vector<int>& a, int start, int end)
{
    if (start == end) return;
    int i = middle(a, start, end);
    if (start <= end)
    {
        quicksort(a, start, i);
        quicksort(a, i+1, end);
    }
}
int main()
{
    // 递增
    vector<int> a {15, 33, 84, 44, 15, 1, 9, 23, 101};
    quicksort(a, 0, a.size()-1);
    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}