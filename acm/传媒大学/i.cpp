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
const int mod = 1e9 + 7;
long long fastPow(long long base, long long power, long long mod) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        power >>= 1;
    }
    return result;
}
void solve() {
    //freopen("output.txt", "w", stdout);
    int l1, l2, r1, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int a = r1 - l1 + 1, b = r2 - l2+ 1;
    int cnt = 0;
    for (int i = l1; i <= r1; i++) {
        for (int j = l2; j <= r2; j++) {
            cnt += i ^ j;
        }
    }
    int q = a * b;
    int ans = ((cnt) * fastPow(q, mod - 2, mod)) % mod;
    cout << ans << endl;
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