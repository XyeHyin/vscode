#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
const int MAX = 10000000 + 5;
int fact[MAX];
int inv_fact[MAX];
int power_mod(int a, int b) {
    int res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
void init() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) fact[i] = fact[i - 1] * i % MOD;
    inv_fact[MAX - 1] = power_mod(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; i--)
    inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}
int comb(int n, int k) {
    if (n < k || k < 0) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}
inline int pow2(int x) { return power_mod(2, x); }
void solve() {
    int n, k;
    cin >> n >> k;
    if (n % 2 != 0 || k < 2) {
        cout << 0 << '\n';
        return;
    }
    if (k > n) {
        cout << 0 << '\n';
        return;
    }
    int total = comb(n, k);
    int without = comb(n / 2, k) * pow2(k) % MOD;
    int ans = (total - without + MOD) % MOD;
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}