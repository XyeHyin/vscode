#include <bits/stdc++.h>
#define L using
#define S namespace
#define Y std
#define endl '\n'
#define int long long
#define lowbit(x) (x & (-x))
const int N = 2e5 + 10;
// const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
// const int mod = 998244353;
// L S Y;
// int xx[] = {-1, 0, 1, 0}, yy[] = {0, 1, 0, -1}; // (-1, 0) (0, 1) (1, 0) (0,
// -1)

int n, m, k;
int a[N], b[N], f0[N], f1[N];

void solve() {
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= n; i++)
        std::cin >> b[i];
    f0[1] = a[1];
    f1[1] = LLONG_MIN;
    for (int i = 2; i <= n; i++) {
        f0[i] = f0[i - 1] + a[i];
        f1[i] = f1[i - 1] + b[i];
        f0[i] = std::max(
            f0[i], (f1[i - 1] - k >= 0 ? f1[i - 1] - k + a[i] : LLONG_MIN));
        f1[i] = std::max(f1[i],
                         f0[i - 1] - k >= 0 ? f0[i - 1] - k + b[i] : LLONG_MIN);
    }
    std::cout << std::max(f0[n], f1[n]) << endl;
}

signed main() {
    //	int t; std:: cin >> t;
    int t = 1;
    while (t--)
        solve();
    return 0;
}