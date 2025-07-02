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
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
vector<vector<char>> a;
int cnt = 0;
int dfs(int x, int y) {
    if (x < 1 || x > a.size() - 1 || y < 1 || y > a[0].size() - 1)
        return 0;
    if (a[x][y] == '.')
        return 0;
    if (a[x][y] == '#') {
        a[x][y] = '.';
        for (int i = 0; i < 8; i++) {
            dfs(x + dx[i], y + dy[i]);
        }
    }
    return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;
    a.resize(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '#') {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << endl;
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