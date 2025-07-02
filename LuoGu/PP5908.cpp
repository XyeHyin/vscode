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
vector<int> adj[100005];
vector<int> vis(100005, 0);
int n, dd;
int cnt = 0;
void dfs(int x, int step){
    vis[x] = 1;
    if (step == dd) {
        cnt++;
        return;
    }
    for (auto a : adj[x]) {
        if (vis[a]) continue;
        dfs(a, step + 1);
    }
}
void solve() {
    cin >> n >> dd;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }
    dfs(1, 0);
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