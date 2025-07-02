#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

int mod_exp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void solve() {
    int n = 10000;
    int total = mod_exp(9, n, MOD);
    int exclude_3_7 = mod_exp(7, n, MOD);
    int exclude_3_or_7 = mod_exp(8, n, MOD);
    int result = (total - 2 * exclude_3_7 + exclude_3_or_7 + MOD) % MOD;
    cout << result << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}