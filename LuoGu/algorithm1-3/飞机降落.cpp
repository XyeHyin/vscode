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
struct plane {
    int t, d, l;
};
int n;
bool vis[20];
vector<plane> a(20);
bool dfs(int step, int time) {
    if (step == n)
        return true;
    for (int i = 1; i <= n; i++) {
        if (time > a[i].t + a[i].d)
            continue;
        if (vis[i])
            continue;
        vis[i] = 1;
        if (dfs(step + 1, max(time, a[i].t) + a[i].l))
            return true;
        vis[i] = 0;
    }
    return false;
};
void solve() {
    memset(vis, 0, sizeof(vis));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].t >> a[i].d >> a[i].l;
    }
    if (dfs(0, 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}