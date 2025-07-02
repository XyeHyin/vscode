#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define PII pair<int, int>
#define dbg(x) std::cout << #x << ":" << x << " "
#define MP make_pair
#define PB push_back
#define rep(i, x, n) for (int i = x; i <= n; i++)
#define dep(i, x, n) for (int i = x; i >= n; i--)
#define arrout(a, n) rep(i, 1, n) std::cout << a[i]
#define arrin(a, n) rep(i, 1, n) std::cin >> a[i]
#define endl '\n'

void solve() {
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    bool flag = false;
    if (2 * ya == yb + yc || 2 * xa == xb + xc)flag = true;
    if (2 * yb == ya + yc || 2 * xb == xa + xc)flag = true;
    if (2 * yc == ya + yb || 2 * xc == xa + xb) flag = true;
    cout << (flag ? "YES" : "NO") << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}