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
int n, m, s, t;
int a[10005];
const int maxn = 1e5 + 5;
vector<PII> edge[maxn];
vector<PII> dis;
struct XyeHyin {
    int d, a, u;
    bool operator>(const XyeHyin &other) const {
        if (d == other.d) return a > other.a;
        return d > other.d;
    }
};

void dij() {
    dis.assign(n + 1, {0x3f3f3f3f, 0x3f3f3f3f});
    dis[s] = {0, 0};
    priority_queue<XyeHyin, vector<XyeHyin>, greater<XyeHyin>> pq;
    pq.push({0, 0, s});
    while (!pq.empty()) {
        auto [x, y, u] = pq.top();
        pq.pop();
        if (x != dis[u].first || y != dis[u].second)
            continue;
        for (auto [v, w] : edge[u]) {
            int xx = x + w;
            int maxx = (v == t ? y : max(y, a[v]));
            if (xx < dis[v].first ||
                (xx == dis[v].first && maxx < dis[v].second)) {
                dis[v] = {xx, maxx};
                pq.push({xx, maxx, v});
            }
        }
    }
}

void solve() {
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        edge[u].PB({v, d});
        edge[v].PB({u, d});
    }
    dij();
    if (dis[t].first == 0x3f3f3f3f) cout << "Impossible";
    else cout << dis[t].first << " " << dis[t].second;
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