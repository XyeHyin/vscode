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
    string s;
    cin >> s;
    map<int, int> mp;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 26; j++) {
            int tmp = min({abs(s[i] - 'a' - j), abs(s[i] - 'a' - (j + 26)),abs(s[i]-'a'+26-j)});
            mp[j] += tmp;
            // dbg(tmp);
        }
    }
    int ans = LLONG_MAX;
    for (auto it : mp) {
        ans = min(ans, it.second);
        // cout << it.first << ":" << it.second << endl;
    }
    cout << ans << endl;
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