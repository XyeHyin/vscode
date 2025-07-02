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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 3) {
        cout << 0 << endl;
        return;
    }
    sum /= 3;
    vector<int> ok(n, 0);
    int sum1 = 0;
    int tmp = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum1 += a[i];
        if (a[i] > 0) tmp++;
        if (sum1 == sum && tmp > 0) ok[i] = 1;
    }
    for (int i = n - 2; i >= 0; i--) {
        ok[i] += ok[i + 1];
    }
    int ans = 0;
    int sum2 = 0;
    int tmp1 = 0;
    bool flag = 0;
    for (int i = 0; i < n - 2; i++) {
        sum2 += a[i];
        if (a[i] > 0) tmp1++;
        if (sum2 == sum && tmp1 > 0) {
            flag = 0;
            for (int j = i + 1; j < n - 1; j++) {
                if (a[j] > 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag)  ans += ok[i + 2];
            else ans+=ok[i+2]-1;
        }
    }
    cout << ans << endl;
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