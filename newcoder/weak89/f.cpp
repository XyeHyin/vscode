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
vector<int> g[100005];
int ans = 0;
vector<bool> vis;
void dfs(int u, int die) {
    for (int v : g[u]) {
        if (v == die)
            continue;
        dfs(v, u);
    }
    for (int v : g[u]) {
        if (v == die)
            continue;
        if (!vis[u] && !vis[v]) {
            cout << u << " " << v << endl;
            vis[u] = 1;
            vis[v] = 1;
            ans++;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis.assign(n + 1, 0);
    ans = 0;
    dfs(1, 0);
    int res = (ans & 1 ? ((ans + 1) / 2) : (ans / 2));
    cout << res << endl;
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