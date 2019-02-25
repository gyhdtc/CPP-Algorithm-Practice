#include <iostream>
using namespace std;
int foundhang(int chexiang[][5], int num){// 0 1 2 3 ... ...
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 6-num; j++) {
            int flag = 0;
            for (int k = j; k < j + num; k++) {
                if (chexiang[i][k] == 1) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                return i;
            }
        }
    }
    return -1;
}
int foundlie(int chexiang[][5], int hang, int num){// 0 1 2 3 4
    for (int j = 0; j < 5-num; j++) {
        int flag = 0;
        for (int k = j; k < j + num; k++) {
            if (chexiang[hang][k] == 1) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) return j;
    }
}
void shuchuzaxiang(int chexiang[][5], int num) {
    for (int i = 0; i < 20 && num != 0; i++) {
        for (int j = 0; j < 5 && num != 0; j++) {
            if (chexiang[i][j] == 0) {
                cout << i * 5 + j + 1 << " ";
                chexiang[i][j] = 1;
                num--;
            }
        }
    }
    cout << endl;
}
int main(){
    int chexiang[20][5] = {0};
    int n;
    int num;
    int hang, lie;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        hang = foundhang(chexiang, num);
        if (hang == -1) {
            shuchuzaxiang(chexiang, num);
            continue;
        }
        lie = foundlie(chexiang, hang, num);
        for (int j = 1; j <= num; j++) {
            cout << hang * 5 + lie + j << " ";
            chexiang[hang][lie+j-1] = 1;    
        }
        cout << endl;
    }
    return 0;
}