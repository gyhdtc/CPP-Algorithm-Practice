#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct Student
{
    char id[15];
    int score;
    int location_number;
    int location_rank;
}stu[30010];

bool cmp(Student a, Student b) {
    if (a.score != b.score) return a.score > b.score;
    else return strcmp(a.id, b.id);
}

int main(){
    // n 考场数 k 每个考场的人数 num 总考生数
    int n, k, num = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%s %d", stu[num].id, &stu[num].score);
            stu[num].location_number = i;
            num ++;
        }
        // 排列一个考场的分数
        sort(stu + num - k, stu + num, cmp);
        stu[num-k].location_rank = 1;
        for (int j = num - k + 1; j < num; j++) {
            if (stu[j].score == stu[j-1].score)
                stu[j].location_rank = stu[j-1].location_rank;
            else {
                stu[j].location_rank = j + 1 - (num - k);
            }
        }
    }
    cout << num << endl;
    sort(stu, stu + num, cmp);
    int r = 1;
    for (int i = 0; i < num; i++) {
        if (i > 0 && stu[i].score != stu[i-1].score)
            r = i + 1;
        printf("%s ", stu[i].id);
        printf("%d %d %d\n", r, stu[i].location_number, stu[i].location_rank);
    }
    return 0;
}

