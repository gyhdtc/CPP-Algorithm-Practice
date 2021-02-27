#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> gyh;
int shit = 0;


string shuzi(string& str, int start, int len)
{
    string res;
    switch (len)
    {
    case 1:
        res += str[start];
        break;
    case 2:
        res += str[start];
        res += str[start+1];
        break;
    case 3:
        res += str[start];
        res += str[start+1];
        res += str[start+2];
        break;
    default:
        break;
    }
    return res;
}

int main(){
    string str;
    cin >> str;
    int len = str.size();
    if (len == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    if (len == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    if (len == 2 && str[0] == '1')
    {
        cout << 2 << endl;
        return 0;
    }
    if (len == 2 && str[0] == '0')
    {
        cout << 1 << endl;
        return 0;
    }

    gyh["0"] = 1;
    gyh["1"] = 1;

    gyh["00"] = 1;
    gyh["01"] = 1;
    gyh["10"] = 2;
    gyh["11"] = 2;

    gyh["000"] = 1;
    gyh["001"] = 1;
    gyh["010"] = 2;
    gyh["100"] = 3;
    gyh["110"] = 4;
    gyh["101"] = 3;
    gyh["011"] = 2;
    gyh["111"] = 4;
    // dfs(str, 0);
    int made[len];
    for (int i = 0; i < len; ++i)
    {
        made[i] = 0;
    }

    made[0] = gyh[shuzi(str, 0, 1)];
    made[1] = gyh[shuzi(str, 0, 2)];
    made[2] = gyh[shuzi(str, 0, 3)];

// cout << made[0] << endl;
// cout << made[1] << endl;
// cout << made[2] << endl;
// cout << gyh[shuzi(str, 0, 3)] << endl;

    for (int i = 3; i < len; ++i)
    {
        made[i] =  made[i-1]  +  (str[i-1] != '0'? made[i-2] : 0) + (str[i-2] != '0' ? made[i-3] : 0);
    }
    cout << made[len-1] << endl;

    // int res = 0;
    // cout << res << endl;
    return 0;
}