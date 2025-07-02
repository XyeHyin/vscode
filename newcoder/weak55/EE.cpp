#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        int temp = 1;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                temp *= a[j];
                if (temp % 10 == 6) {
                    cnt++;
                }
                temp%=MOD;
            }
        }
        ans = (ans + cnt) % MOD;
    }

    cout << ans << endl;
    return 0;
}