#include <cstdio>
int IsLeap(int year) {
    int ret = 0;
    if ( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ) {
        ret = 1;
    }
    return ret;
}
int main(){
    int month[13][2] = {{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},
                        {31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
    int time1, time2;   // 默认 time1 < time2
    int y1, m1, d1;
    int y2, m2, d2;
    int ans = 1;
    scanf("%d%d", &time1, &time2);
    y1 = time1 / 10000 , m1 = time1 % 10000 / 100 , d1 = time1 % 100;
    y2 = time2 / 10000 , m2 = time2 % 10000 / 100 , d2 = time2 % 100;
    while (y1 < y2 || m1 < m2 || d1 < d2) {
        d1++;
        if (d1 > month[m1][IsLeap(y1)]) {
            d1 = 1;
            m1 ++;
        }
        if (m1 > 12 ) {
            m1 = 1;
            y1 ++;
        }
        ans ++;
    }
    printf("%d", ans);
    return 0;
}