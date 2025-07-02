#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto check = [&](int x) {
        unsigned long long sum = 0, duo = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < x) {
                sum += (x - a[i]);
            } else {
                duo += (a[i] - x);
            }
        }
        return sum <= min((unsigned long long)m, duo) + k;
    };
    int l = 0, r = 1e18, ans, mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        // cout <<"mid"<< mid << endl;
        if (check(mid)) {
            ans = mid, l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
