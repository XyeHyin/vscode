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
const int N = 1e5 + 5;
int fa[N];
int find(int x) { return fa[x] = fa[x] == x ? x : find(fa[x]); }
void merge(int x, int y) {
    int faX = find(x);
    int faY = find(y);
    if (faX == faY)
        return;
    fa[find(x)] = find(y);
}
struct Edge {
    int u, v, w;
    bool operator<(const Edge &e) const { return w < e.w; }
};
priority_queue<Edge> pq;
void solve() {
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> mp;
    for(int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        mp[x] = 1;
    }
    for (int i = 0; i < n; i++) {
        fa[i] = i;
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        pq.push({u, v, w});
        ans+= w;
    }
    int cnt = 0;
    while (!pq.empty()) {
        auto [u, v, w] = pq.top();
        pq.pop();
        int fu = find(u), fv = find(v);
        if (mp[fu] and mp[fv]) continue;
        if(mp[fu]) mp[fv] = 1;
        if(mp[fv]) mp[fu] = 1;
        merge(u, v);
        ans -= w;
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