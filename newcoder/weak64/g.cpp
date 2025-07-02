#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int LOG = 17;
vector<int> tree[MAXN];
int depth[MAXN];
int prt[MAXN][LOG];
#define int long long

void dfs(int node, int par) {
    prt[node][0] = par;
    for (int i = 1; i < LOG; i++) {
        if (prt[node][i - 1] != -1) {
            prt[node][i] = prt[prt[node][i - 1]][i - 1];
        } else {
            prt[node][i] = -1;
        }
    }
    for (int i : tree[node]) {
        if (i != par) {
            depth[i] = depth[node] + 1;
            dfs(i, node);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    int dis = depth[u] - depth[v];
    for (int i = 0; i < LOG; ++i) {
        if ((dis >> i) & 1) {
            u = prt[u][i];
        }
    }
    if (u == v)
        return u;
    for (int i = LOG - 1; i >= 0; --i) {
        if (prt[u][i] != prt[v][i]) {
            u = prt[u][i];
            v = prt[v][i];
        }
    }
    return prt[u][0];
}

int dist(int u, int v) {
    int l = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[l];
}

signed main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    memset(prt, -1, sizeof(prt));
    depth[1] = 0;
    dfs(1, -1);
    while (q--) {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int dist_to_path = min(dist(i, x), dist(i, y));
            ans += dist_to_path;
        }
        cout << ans << endl;
    }

    return 0;
}