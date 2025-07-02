#include <bits/stdc++.h>
using namespace std;
int dicm(int y, int m) {
    if (m == 2) {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) return 29;
         else return 28;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}
int trans(int y, int m, int d) {
    int ans = 0;
    for (int i = 1970; i < y; i++) {
        ans += (i % 4 == 0 && i % 100) || (i % 400 == 0) ? 366 : 365;
    }
    for (int i = 1; i < m; i++) {
        ans += dicm(y, i);
    }
    ans += d - 1;
    return ans;
}
void solve(int sss) {
    int yyyy = 1970, MM = 1, dd = 1, hh, mm, ss;
    int ans = sss / 86400;
    sss %= 86400;
    hh = sss / 3600;
    sss %= 3600;
    mm = sss / 60;
    ss = sss % 60;
    while (
        ans >=((yyyy % 4 == 0 && yyyy % 100) || (yyyy % 400 == 0) ? 366 : 365)) {
        ans -= ((yyyy % 4 == 0 && yyyy % 100 ) || (yyyy % 400 == 0) ? 366: 365);
        yyyy++;
    }
    while (ans >= dicm(yyyy, MM)) {
        ans -= dicm(yyyy, MM);
        MM++;
    }
    dd += ans;
    printf("%04d-%02d-%02d %02d:%02d:%02d\n", yyyy, MM, dd, hh, mm, ss);
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int yyyy, MM, dd, hh, mm, ss, x;
        scanf("%d-%2d-%2d %d:%d:%d %d", &yyyy, &MM, &dd, &hh, &mm, &ss, &x);
        int sss = trans(yyyy, MM, dd) * 86400 + hh * 3600 + mm * 60 + ss;
        int tmp = x * 60;
        solve((sss / tmp) * tmp);
    }
    return 0;
}