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
    int n;
    cin >> n;
    vector<PII> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    int maxx = -1;
    for (int i = 0; i < 24; i++) {
        int ans = 0;
        for (int j = 0; j < n; j++) {
            if ((a[j].second + i) % 24 >= 9 && (a[j].second + i) % 24 <= 17) {
                ans += a[j].first;
            }
        }
        maxx = max(maxx, ans);
    }
    cout << maxx << endl;
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