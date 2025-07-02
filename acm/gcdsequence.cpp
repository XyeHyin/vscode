#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int gcd(int a, int b) {
    while (b ^= a ^= b ^= a %= b)
        ;
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, n;
    T = read();
    while (T--) {
        n = read();
        vector<int> a(n + 1), b(n + 1), l(n + 1), r(n + 1);
        for (int i = 1; i <= n; i++)
            a[i] = read();
        for (int i = 1; i < n; i++)
            b[i] = gcd(a[i], a[i + 1]);
        l[1] = r[n - 1] = 1;
        for (int i = 2; i < n; i++)
            l[i] = l[i - 1] & (b[i] >= b[i - 1]);
        for (int i = n - 2; i >= 1; i--)
            r[i] = r[i + 1] & (b[i] <= b[i + 1]);
        bool flag = false;
        for (int i = 3; i <= n - 2; i++) {
            if (l[i - 2] && r[i + 1] && gcd(a[i - 1], a[i + 1]) >= b[i - 2] &&
                gcd(a[i - 1], a[i + 1]) <= b[i + 1]) {
                flag = true;
                break;
            }
        }
        if (r[2] || r[3] && gcd(a[1], a[3]) <= b[3] || l[n - 2] ||
            l[n - 3] && gcd(a[n], a[n - 2]) >= b[n - 3] || flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}