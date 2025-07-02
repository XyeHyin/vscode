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
int dx[3] = {0, 1, 0};
int dy[3] = {1, 0, -1};
int mp[2005][2005];
int dis[2005][2005];
int vis[2005][2005];
int n, m;
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    auto bfs = [&]() {
        memset(dis, 0x3f, sizeof(dis));
        dis[1][1] = 0;
        deque<PII> q;
        q.push_back({1, 1});
        while (!q.empty()) {
            auto [xx, yy] = q.front();
            q.pop_front();
            for (int i = 0; i < 3; i++) {
                int nx = xx + dx[i];
                int ny = yy + dy[i];
                if (nx < 1 || nx > n || ny < 1 || ny > m)
                    continue;
                int d = dis[xx][yy] + (mp[nx][ny] != mp[xx][yy] ? 2 : 1);
                if (d < dis[nx][ny]) {
                    dis[nx][ny] = d;
                    if (mp[nx][ny] != mp[xx][yy]) {
                        q.push_back({nx, ny});
                    } else {
                        q.push_front({nx, ny});
                    }
                }
            }
        }
    };
    bfs();
    cout << dis[n][m] << endl;
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