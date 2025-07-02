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
vector<int> g[10001];
int dfs(int x) {
    int tmp = 1;
    for (auto i : g[x]) {
        tmp += dfs(i);
    }
    return tmp;
}
void solve() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        g[x].PB(y);
    }
    int maxx = -1, ans;
    for (int i = 1; i <= 10000; i++) {
        if (g[i].size() == 0) continue;
        if (maxx < dfs(i)) {
            maxx = dfs(i);
            ans = i;
        }
    }
    cout << ans << endl << ans << endl;
    for (auto i : g[ans]) {
        cout << i << (i == g[ans].back() ? "" : " ");
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