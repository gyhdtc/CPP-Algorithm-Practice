#include <iostream>
using namespace std;
int main(){
    string c;
    int sum = 0;
    int j = 1;
    char flag;
    for (int i = 0; i <= 12; i++) {
        cin >> c[i];
        if (c[i] <= '9' && c[i] >= '0' && i != 12) {
            sum += (c[i] - '0') * j;
            j++;
        }
        if (i == 12)
            flag = c[i];
    }
    
    if (sum % 11 == 10 && flag == 'X' || sum % 11 != 10 && sum % 11 == flag - '0') {
        cout << "Right";
        return 0;
    }
    else if(sum % 11 == 10 && flag != 'X') {
        c[12] = 'X';
    }
    else if(sum % 11 != 10 && sum % 11 != flag - '0') {
        c[12] = sum % 11 + '0';
    }

    for (int i = 0; i <= 12; i++) {
        cout << c[i];
    }
    return 0;
}