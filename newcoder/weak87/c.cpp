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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'Z') {
            if (a[i] == 0 || (a[i - 1] > 0 && a[i] <= 0) ||
                (a[i - 1] < 0 && a[i] >= 0)) {
                ans++;
                a[i] = (a[i - 1] > 0 ? 1 : -1);
            }
        } else if (s[i] == '>') {
            if (a[i] <= 0) {
                ans++;
                a[i] = 1;
            }
        } else if (s[i] == '<') {
            if (a[i] >= 0) {
                ans++;
                a[i] = -1;
            }
        }
    }

    cout << ans << endl;
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