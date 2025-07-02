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

bool check(vector<int> sides) {
    sort(sides.begin(), sides.end());
    return sides[0] + sides[1] > sides[2];
}

void solve() {
    int l, r;
    cin >> l >> r;
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        string s = to_string(i);
        if (s.find('0') != string::npos) continue;
        vector<int> num;
        for (char ch : s) {
            num.PB(ch - '0');
        }
        bool ok = false;
        for (int msk = 0; msk < (1 << 6); msk++) {
            if (__builtin_popcount(msk) != 3) continue;
            vector<int> aa, bb;
            for (int j = 0; j < 6; j++) {
                if (msk & (1 << j)) aa.PB(num[j]);
                else bb.PB(num[j]);
            }
            if (check(aa) && check(bb)) {
                ok = true;
                break;
            }
        }
        if (ok) cnt++;
    }
    cout << cnt;
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