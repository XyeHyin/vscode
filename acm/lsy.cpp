#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int cnt[100];
    memset(cnt, 0x3f, sizeof(cnt));
    int coins[] = {1, 3, 6, 10, 15};
    cnt[0] = 0;
    for (int i = 1; i < 100; i++) {
        for (auto coin : coins) {
            if (i >= coin && cnt[i - coin] != 0x3f) {
                cnt[i] = min(cnt[i], cnt[i - coin] + 1);
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = LLONG_MAX;
        int q = n / 15;
        for (int k = q; k >= max(0LL, q - 5); k--) {
            int tmp = n - k * 15;
            if (tmp < 100) {
                int temp = k + cnt[tmp];
                ans = min(ans, temp);
            }
        }
        cout << ans << endl;
    }
}