#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            pre[i][j] =a[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
    int ans = -1;
    while (q--) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        int cnt =
            (pre[x][y] - pre[x][v - 1] - pre[u - 1][y] + pre[u - 1][v - 1]);
        if (ans == -1)
            ans = cnt;
        else
            ans ^= cnt;
    }
    cout << ans << endl;
    return;
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