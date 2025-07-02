#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
#define int long long

int fastPow(int base, int power, int mod) {
    int result = 1;
    while (power > 0) {
        if (power & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        power >>= 1;
    }
    return result;
}
int zuhe(int n, int m) {
    int ans = 1;
    for (int i = 1; i <= m; i++) {
        ans = ans * (n - i + 1) % MOD;
        ans = ans * fastPow(i, MOD - 2, MOD) % MOD;
    }
    return ans;
}
signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int res = zuhe(n + m, m);
        int res2 = fastPow(n + 1, m - n, MOD);
        cout << res * res2 % MOD << endl;
    }
    return 0;
}