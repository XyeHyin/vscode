#include <bits/stdc++.h>
using namespace std;
// jc  =128, xt=64,bb=32,dr=16,er=8,mm=4,dn=2,en=1
enum { JC = 128, XT = 64, BB = 32, DR = 16, ER = 8, MM = 4, DN = 2, EN = 1 };
// 测x是否包含y
bool f1(int x, int y) { return (x & y) == y; }
// 判断x是否合理
bool f2(int x) {
    if (!f1(x, JC) && x > 64) return false;
    if (!f1(x, BB) && f1(x, MM) && (f1(x, DR) || f1(x, ER))) return false;
    if (f1(x, BB) && !f1(x, MM) && (f1(x, DN) || f1(x, EN)))return false;
    return true;
}
void f(int x, int *result, int step, bool &finished) {
    if (finished) return;
    if (x == 0) {
        int i;
        for (i = 0; i < step; i++) {
            cout << result[i] << " ";
        }
        finished = true;
        return;
    }
    static int a[15] = {
        JC | XT, JC | BB, JC | DR, JC | ER, JC | MM,JC | DN, JC | EN, JC,
        BB | DR, BB | ER,BB | MM, BB, 
        MM | DN, MM | EN, MM};
    int i;
    static bool flag[512];
    for ( i = 0; i < 15; i++)
        if (step % 2 == 0) {
            if (!f1(x, a[i])) continue;
            if (!f2(x - a[i])) continue;
            if (!f2(255 - x + a[i])) continue;
            if (flag[x - a[i]]) continue;
            else flag[x - a[i]] = 1;
            result[step] = a[i];
            f(x - a[i], result, step + 1, finished);
        } else {
            if (!f1(255-x, a[i])) continue;
            if (!f2(255-x - a[i])) continue;
            if (!f2(x + a[i]))  continue;
            if (flag[x + a[i]+256])continue;                                                                    
            flag[x + a[i]+256] = 1;
            result[step] = a[i];
            f(x + a[i], result, step + 1, finished);
        }
}

int main() {
    bool finished = false;
    int result[200];
    f(255, result, 0, finished);
    return 0;
}