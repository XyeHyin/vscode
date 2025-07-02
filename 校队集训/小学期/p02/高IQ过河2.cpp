#include <bits/stdc++.h>
using namespace std;
enum { JC = 128, XT = 64, BB = 32, DR = 16, ER = 8, MM = 4, DN = 2, EN = 1 };
bool f1(int x, int y) { return (x & y) == y; }
bool f2(int x) {
    if (!f1(x, JC) && x > 64)
        return false;
    if (!f1(x, BB) && f1(x, MM) && (f1(x, DR) || f1(x, ER)))
        return false;
    if (f1(x, BB) && !f1(x, MM) && (f1(x, DN) || f1(x, EN)))
        return false;
    return true;
}

void f(int x, int *re, int step, bool &fi) {
    if (fi)
        return;
    if (x == 0) {
        int i;
        for (i = 0; i < step; i++)
            cout << re[i] << endl;
        fi = 1;
        return;
    }
    static int a[15] = {JC | XT, JC | BB, JC | DR, JC | ER, JC | MM,
                        JC | DN, JC | EN, JC,      BB | DR, BB | ER,
                        BB | MM, BB,      MM | DN, MM | EN, MM};
    int i;
    static bool flag[512];
    for (i = 0; i < 15; i++)
        if (step % 2 == 0) {
            if (!f1(x, a[i]))
                continue;
            if (!f2(x - a[i]))
                continue;
            if (!f2(255 - x + a[i]))
                continue;
            if (flag[x - a[i]])
                continue;
            flag[x - a[i]] = 1;
            re[step] = a[i];
            f(x - a[i], re, step + 1, fi);
        } else {
            if (!f1(255 - x, a[i]))
                continue;
            if (!f2(255 - x - a[i]))
                continue;
            if (!f2(x + a[i]))
                continue;
            if (flag[x + a[i] + 256])
                continue;
            flag[x + a[i] + 256] = 1;
            re[step] = a[i];
            f(x + a[i], re, step + 1, fi);
        }
}
int main() {

    int re[200];
    bool finished = 0;
    f(255, re, 0, finished);
    return 0;
}