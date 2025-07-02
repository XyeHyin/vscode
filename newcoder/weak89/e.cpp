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
struct XyeHyin {
    int a, b, c, d;

};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mp(n, vector<int>(m, 0));
    int cnt0 = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++){
            mp[i][j] = s[j] -'0';
            if(mp[i][j] == 0) cnt0++;
        } 
    }
    if (cnt0 & 1) {
        cout << -1 << endl;
        return;
    }
    vector<XyeHyin> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (mp[i][j] == 0) {
                ans.push_back({i, j, i, j + 1});
                mp[i][j] ^= 1;
                mp[i][j + 1] ^= 1;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (mp[i][m - 1] == 0) {
            ans.push_back({i, m-1, i + 1, m-1});
            mp[i][m - 1] ^= 1;
            mp[i + 1][m - 1] ^= 1;
        }
    }
    if (mp[n - 1][m - 1] != 1) {
        cout << -1 << endl;
        return;
    }
    cout << ans.size() << endl;
    for (auto it : ans) {
        cout << it.a+1 << " " << it.b +1 << " " << it.c+1 << " " << it.d +1<< endl;
    }
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