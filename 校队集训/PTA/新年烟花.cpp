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
    int n, m, h;
    cin >> n >> m >> h;
    int mp[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
        }
    }
    int ans = 0, inix = -1, iniy = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] != 0) continue;
            int cnt = 0;
            for (int l = j; l >= 0; l--) {
                if (mp[i][l] < 0)
                    cnt++;
                if (mp[i][l] >= h)
                    break;
            }
            for (int l = j; l < m; l++) {
                if (mp[i][l] < 0)
                    cnt++;
                if (mp[i][l] >= h)
                    break;
            }
            for (int l = i; l >= 0; l--) {
                if (mp[l][j] < 0)
                    cnt++;
                if (mp[l][j] >= h)
                    break;
            }
            for (int l = i; l < n; l++) {
                if (mp[l][j] < 0)
                    cnt++;
                if (mp[l][j] >= h)
                    break;
            }
            if (cnt >= 3) {
                // cout<<i<<" "<<j<<endl;
                if (inix == -1) {
                    inix = i;
                    iniy = j;
                }
                ans++;
            }
        }
    }
    cout << ans << endl << inix << ' ' << iniy;
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