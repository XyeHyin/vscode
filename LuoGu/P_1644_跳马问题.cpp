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
int n, m;
int dx[] = {1, 2, 1, 2};
int dy[] = {2, 1, -2, -1};
int ans;
void dfs(int x, int y) {
    if (x == n && y == m) {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx <= n && ny <= m&&nx>=0&&ny>=0) {
            dfs(nx, ny);
        }

    }
    return;
}
void solve() {
    cin >> m >> n;
    ans = 0;
    dfs(0, 0);
    cout << ans << endl;
    return; }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}