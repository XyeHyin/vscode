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
const int mod = 998244353;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans+((sum + a[i]) * a[i]%mod)) % mod;
        sum = (sum*2%mod + a[i]) % mod;
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