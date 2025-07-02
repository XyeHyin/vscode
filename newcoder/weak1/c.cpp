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
    int n = s.size();
    string dic = "";
    int cnt1 = count(s.begin(), s.end(), '1');
    string dic2 = "";
    bool flag = false;
    if (cnt1 * 2 > n) {
        for (int i = 0; i < n; i++) {
            if (i & 1)
                dic += '0';
            else
                dic += '1';
        }
    } else if (cnt1 * 2 < n) {
        for (int i = 0; i < n; i++) {
            if (i & 1)
                dic += '1';
            else
                dic += '0';
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                dic += '1';
                dic2 += '0';
            } else {
                dic += '0';
                dic2 += '1';
            }
        }
        flag = true;
    }
    int ans = 0;
    int ans2 = 0;
    string ss = s;
    for (int i = 0; i < n; i++) {
        if (s[i] != dic[i]) {
            auto it = s.find(dic[i], i + 1);
            ans += it - i;
            swap(s[i], s[it]);
        }
    }
    if (flag) {
        for (int i = 0; i < n; i++) {
            if (ss[i] != dic2[i]) {
                auto it = ss.find(dic2[i], i + 1);
                ans2 += it - i;
                swap(ss[i], ss[it]);
            }
        }
        ans = min(ans, ans2);
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