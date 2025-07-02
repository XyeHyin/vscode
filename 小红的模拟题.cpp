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
int dx[2] = {1, 0};
int dy[2] = {0, 1};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '#')
                vis[i][j] = true;
        }
    }
    string ans = "";
    function<void(int, int)> dfs = [&](int x, int y) {
        if (x == n && y == m) {
            cout << ans << endl;
            exit(0);
        }
        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx > n || ny > m || vis[nx][ny])continue;
            ans += (i == 0 ? 'S' : 'D');
            dfs(nx, ny);
            ans.pop_back();
        }
    };
    dfs(1, 1);
    return;
}

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