#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 递增
    vector<int> a {3,9,6,7,2,1,5,8,4,0};
    
    for (int i = 1; i < a.size(); ++i)
    {
        int temp = a[i];
        int j;
        for (j = i-1; j >= 0 && a[j] > temp; --j)
        {
            a[j+1] = a[j];
        }
        a[j+1] = temp;
    }

    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}