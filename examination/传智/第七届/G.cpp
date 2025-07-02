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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    rep(i, 0, n - 1) cin >> a[i];
    auto check = [&](int nn) {
        // dbg(nn) << " ";
        int tmp = k;
        for (int i = 0; i < n; i++) {
            if (a[i] > nn) {
                tmp-=ceil((a[i] - nn) * 1.0 / x);
                // dbg(tmpp) << " ";
            }
        }
        // dbg(tmp)<<endl;
        return tmp >= 0;
    };
    int l = -1e17, r = 1e17;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (!check(mid))  l = mid + 1;
        else r = mid - 1;
    }
    cout << l<< endl;
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