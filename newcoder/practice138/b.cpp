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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> pre(n + 1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i] * m;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
        
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        auto it = upper_bound(a.begin(), a.end(), x);
        int dis = it - a.begin();
        ans -= (pre[dis]);
        ans += dis * x;
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