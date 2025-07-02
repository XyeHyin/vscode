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
const int mod = 1e5 + 3;
void solve() {
    // freopen("P1144_6.in", "r", stdin);
    // freopen("P1144_6.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<PII>> edge(n + 1);
    vector<int> dis(n + 1, 0x3f3f3f3f), cnt(n + 1, 0), vis(n + 1, 0);
    priority_queue<PII, vector<PII>, greater<PII>> q;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (u == v) continue;
        edge[u].PB({v, 1});
        edge[v].PB({u, 1});
    }
    auto dij = [&](int x) {
        cnt[1] = 1;
        dis[x] = 0;
        q.push({0, x});
        while (!q.empty()) {
            auto [d, u] = q.top();
            q.pop();
            if (vis[u])
                continue;
            vis[u] = 1;
            for (auto [a, b] : edge[u]) {
                if (dis[a] > dis[u] + b) {
                    dis[a] = dis[u] + b;
                    cnt[a] = cnt[u];
                    q.push({dis[a], a});
                } else if (dis[a] == dis[u] + b) {
                    cnt[a] = (cnt[u] + cnt[a]) % mod;
                }
            }
        }
    };
    dij(1);
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << endl;
    }
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