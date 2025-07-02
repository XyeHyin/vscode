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
    int t;
    while (cin >> t) {
        if (t == 0) break;
        int n = t;
        vector<vector<int>> mp(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
        for(int i = 1; i <= n; i++) {
            mp[i][i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int nn;
            cin >> nn;
            for (int j = 1; j <= nn; j++) {
                int x, y;
                cin >> x >> y;
                mp[i][x] = min(mp[i][x], y);
            }
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
                }
            }
        }
        int ans = 0x3f3f3f3f;    
        int tmp = 0;
        for(int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                cnt = max(cnt,mp[i][j]);
            }
            if(cnt < ans) {
                ans = cnt;
                tmp = i;
            }
        }
        cout <<tmp<<" "<< ans << endl;
    out:;

    }
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cin >> t;
        solve();
    return 0;
}