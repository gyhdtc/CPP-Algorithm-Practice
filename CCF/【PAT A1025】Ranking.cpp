#include <cstdio>
#include <cstring>
#include <iostream>
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
 
    return 0;
}

