#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

struct bign
{
    /* data */
    int d[1000];
    int len;
    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};
bign change(char str[]) {
    bign a;
    a.len = strlen(str);
    for (int i = 0; i < a.len; i++) {
        a.d[i] = str[a.len - i - 1] - '0';
    }
    return a;
}
bign add(bign a, bign b) {
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len || i < b.len; i++) {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if (carry != 0) {
        c.d[c.len++] = carry;
    }
    return c;
}
bign sub(bign a, bign b) {
    bign c;
    for (int i = 0; i < a.len || i < b.len; i++) {
        if (a.d[i] < b.d[i]) {
            a.d[i+1]--;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
        c.len --;
    }
    return c;
}
bign mult(bign a, bign b) {
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len; i++) {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if (carry != 0) {
        c.d[c.len++] = carry;
    }
    return c;
}
void print(bign a) {
    for (int i = a.len - 1; i>= 0; i--)
        printf("%d", a.d[i]);
    cout << endl;
}
int main() {
    char str1[1000], str2[1000];
    scanf("%s%s", str1, str2);
    bign a = change(str1);
    bign b = change(str2);
    print(add(a, b));
    print(sub(b, a));
    return 0;
}