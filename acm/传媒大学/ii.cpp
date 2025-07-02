#include <bits/stdc++.h>
#define L using
#define S namespace
#define Y std
#define endl '\n'
#define int long long
#define lowbit(x) (x & (-x))
const int N = 1e6 + 10;
// const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
// const int mod = 998244353;
// L S Y;
// int xx[] = {-1, 0, 1, 0}, yy[] = {0, 1, 0, -1}; // (-1, 0) (0, 1) (1, 0) (0,
// -1)

int n, m, a, b, c, d;

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

int f1(int n, int k) {
    n++;
    int re = (n >> k + 1) * (((int)1 << k) % mod) % mod +
             std::max((int)0, n % ((int)1 << k + 1) - ((int)1 << k));
    return re % mod;
}

int f0(int n, int k) {
    n++;
    int re = (n >> k + 1) * (((int)1 << k) % mod) % mod +
             std::min(n % ((int)1 << k + 1), (int)1 << k);
    return re % mod;
}

void solve() {
    std::cin >> a >> b >> c >> d;
    int ans = 0;
    for (int i = 0; i < 60; i++) {

        int cnt = (f0(b, i) - f0(a - 1, i) + mod) % mod *
                      ((f1(d, i) - f1(c - 1, i) + mod) % mod) % mod +
                  (f1(b, i) - f1(a - 1, i) + mod) % mod *
                      ((f0(d, i) - f0(c - 1, i) + mod) % mod) % mod;
        ans += ((int)1 << i) % mod * cnt % mod;
        ans %= mod;
    }
    std::cout << (ans * fastPow(((b-a+1) % mod * ((d-c+1) % mod)) % mod, mod-2, mod)% mod )<< endl;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    //	int t = 1;
    while (t--)
        solve();
    return 0;
}