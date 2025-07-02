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

const int MOD = 1e9 + 7;
const int maxn = 1e5 + 10;
int n, k;
vector<int> adj[maxn];
bool vis[maxn];
int fa[maxn];
vector<int> ch[maxn];
void solve() {
    cin >> n >> k;
    if (k >= n) {
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> tree;
    tree.reserve(n);
    queue<int> q;
    q.push(1);
    fa[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        tree.push_back(u);
        for (int v : adj[u]) {
            if (v == fa[u])
                continue;
            fa[v] = u;
            ch[u].push_back(v);
            q.push(v);
        }
    }
    reverse(tree.begin(), tree.end());
    auto check = [&](int x) {
        int cnt1 = 0;
        vector<int> sum(n + 1, 0);
        vector<bool> OK(n + 1, 0);
        for (int u : tree) {
            int tmp = 1;
            for (int i : ch[u]) {
                tmp += sum[i];
            }
            if (tmp > x) {
                cnt1++;
                sum[u] = 0;
                OK[u] = 1;
            } else {
                sum[u] = tmp;
            }
        }
        if (cnt1 > k)  return 0;
        rep(u, 1, n) {
            if (!OK[u] && !vis[u]) {
                int cnt = 0;
                queue<int> p;
                p.push(u);
                vis[u] = 1;
                while (!p.empty()) {
                    int cur = p.front();
                    p.pop();
                    cnt++;
                    for (int v : adj[cur]) {
                        if (OK[v] || vis[v]) continue;
                        vis[v] = 1;
                        p.push(v);
                    }
                }
                if (cnt > x) return 0;
            }
        }
        return 1;
    };
    int l = 1, r = n, ans = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;
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