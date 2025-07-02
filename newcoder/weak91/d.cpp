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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<pair<int, int>> b;
    for (int i = 0; i < n;) {
        int j = i + 1;
        while (j < n && a[j] == a[i]) j++;
        b.push_back({a[i], j - i});
        i = j;
    }
    int ans = 0;
    int m = b.size();
    for (int i = 0; i < m;) {
        int j = i;
        while (j + 1 < m && b[j + 1].first == b[j].first + 1) j++;
        if (j - i + 1 == 1)   ans += b[i].second;
        else   ans += 1;
        i = j + 1;
    }
    cout << ans - 1 << endl;
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