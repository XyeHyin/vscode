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
int c(int n, int m) {
    if (n < m)
        return 0;
    if (m == 0 || n == m)
        return 1;
    return c(n - 1, m - 1) + c(n - 1, m);
}
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
    int n;
    cin >> n;
    if (n < 6) {
        cout << 0 << endl;
        return;
    }
    int ans = 1;
    int j = (n - 6 + 1);
    int sum = (1+j) * j / 2;
    
    // dbg(tmp);
    int tmpp = fastPow(26, n - 6, mod);
    // dbg(tmpp);
    tmpp = (tmpp * sum) % mod;
    cout << tmpp % mod << endl;
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