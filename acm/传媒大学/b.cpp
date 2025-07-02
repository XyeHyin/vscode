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
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
int flag[1005][1005] = {0};
char mp[1005][1005];
struct XyeHyin {
    int x, y;
    int step;
};
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == '*') {
                flag[i][j] = 1;
                flag[i + 1][j] = 1;
                flag[i - 1][j] = 1;
                flag[i][j + 1] = 1;
                flag[i][j - 1] = 1;
            } else if (mp[i][j] == '#') {
                flag[i][j] = 1;
                flag[i + 1][j] = 1;
                flag[i - 1][j] = 1;
                flag[i][j + 1] = 1;
                flag[i][j - 1] = 1;
                flag[i + 1][j + 1] = 1;
                flag[i - 1][j - 1] = 1;
                flag[i + 1][j - 1] = 1;
                flag[i - 1][j + 1] = 1;
                flag[i + 2][j] = 1;
                flag[i - 2][j] = 1;
                flag[i][j + 2] = 1;
                flag[i][j - 2] = 1;
            }
        }
    }
   /*  if(mp[1][1] || mp[n][m]) {
        cout << -1 << endl;
        return;
    } */
    int ans = 0x3f3f3f3f;
    auto bfs = [&]() {
        queue<XyeHyin> q;
        q.push({1, 1, 0});
        while (!q.empty()) {
            auto [xx, yy, zz] = q.front();
            q.pop();
            if (xx == n && yy == m) {
                ans = min(zz, ans);
            }
            if (flag[xx][yy]) continue;
            flag[xx][yy] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = xx + dx[i];
                int ny = yy + dy[i];
                if (nx < 1 || nx > n || ny < 1 || ny > m)
                    continue;
                if (flag[nx][ny])
                    continue;
                q.push({nx, ny, zz + 1});
            }
        }
    };
    bfs();
    if(ans == 0x3f3f3f3f) {
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;
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