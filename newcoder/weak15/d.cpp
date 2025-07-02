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
    vector<bool> flag(n + 1, false);
    vector<PII> g[n + 1];
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({c, b});
        g[b].push_back({c, a});
        mp[a]++;
        mp[b]++;
    }
    priority_queue<PII, vector<PII>, greater<PII>> pq2;
    for (auto it : mp) {
        pq2.push({it.second, it.first});
    }
    int ans = 0;
    while (!pq2.empty()) {
        auto [n, num] = pq2.top();
        pq2.pop();
        if (flag[num]) {
            continue;
        }
        int maxx = 0, pos;
        for (auto it : g[num]) {
            if (!flag[it.second]) {
                if (it.first > maxx) {
                    maxx = it.first;
                    pos = it.second;
                }
            }
        }
        if (maxx == 0) {
            continue;
        }
        // cout << maxx << endl;
        ans += maxx;
        flag[num] = true;
        flag[pos] = true;
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