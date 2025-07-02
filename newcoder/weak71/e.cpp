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
double S(int a, int b, int c) {
    double p = (a + b + c) * 1.0 / 2;
    double s = p * (p - a) * (p - b) * (p - c);
    return s;
}
bool OK(int a, int b, int c) { return a + b > c && a + c > b && b + c > a; }
void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mp[x] += y;
    }
    for (auto it = prev(mp.end()); it != mp.begin(); it--) {
        if (it->second >= 2) {
            auto it2 = prev(it);
            double ans = -1;
            for (; it2 != mp.end(); it2++) {
                int a = it->first, b = it2->first;
                if (OK(a, a, b)) {
                    // dbg(a) << endl;
                    // dbg(b) << endl;
                   ans = max(ans, sqrt(S(a, a, b)));
                }
            }
            if (ans != -1) {
                cout << fixed << setprecision(20) << ans << endl;
                return;
            }
            break;
        }
    }
    cout << -1 << endl;
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