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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    rep(i, 0, n - 1) cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int maxx = 0, l = 0, len = a.size();
    for (int r = 0; r < len; r++) {
        while (l < r && (a[r] - a[l] + 1) - (r - l + 1) > k)  l++;
        int nd = (a[r] - a[l] + 1) - (r - l + 1);
        if (nd <= k)  maxx = max(maxx, (a[r] - a[l] + 1) + min(a[l] - 1, k - nd) + min(m - a[r], k - nd - min(a[l] - 1, k - nd)));
    }
                
    cout << maxx << endl;
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