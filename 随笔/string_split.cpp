#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<string> split(const string& str, const string& delim) {
	vector<string> res;
	if("" == str) return res;
	//先将要切割的字符串从string类型转换为char*类型
	char * strs = new char[str.length() + 1] ; //不要忘了
	strcpy(strs, str.c_str()); 
 
	char * d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());
 
	char *p = strtok(strs, d);
	while(p) {
		string s = p; //分割得到的字符串转换为string类型
		res.push_back(s); //存入结果数组
		p = strtok(NULL, d);
	}
 
	return res;
}
bool FlagJu(int flag[]) {
    for (int i = 0; i < 4; ++i) {
        if (flag[i] == 1) return true;
    }
    return false;
}
int main(){
    string s;
    getline(cin, s);
    std::vector<string> res = split(s, " ");
    // for (int i = 0; i < res.size(); ++i)
	// {
	// 	cout << res[i] <<endl;
    // }
    for (int i = 0; i < res.size(); ++i)
	{
		if (res[i].length() < 8) {
            cout << "1" << endl;
        }
        else {
            int flag[4] = {1,1,1,1}; // a A 1 .
            for (int j = 0; j < res[i].length(); ++j) {
                if ((int)res[i][j] >= 97 && (int)res[i][j] <= 122) {
                    flag[0]--;
                }
                else if ((int)res[i][j] >= 65 && (int)res[i][j] <= 90) {
                    flag[1]--;
                }
                else if ((int)res[i][j] >= 48 && (int)res[i][j] <= 57) {
                    flag[2]--;
                }
                else {
                    flag[3]--;
                }
            }
            if (FlagJu(flag))
                cout << "2" << endl;
            else 
                cout << "0" << endl;
        }
    }
    return 0;
}
