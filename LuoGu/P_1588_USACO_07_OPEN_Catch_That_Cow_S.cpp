#include <bits/stdc++.h>
using namespace std;

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
    int x, y;
    cin >> x >> y;
    if (x >= y) {
        cout << x - y << endl;
        return;
    }
    vector<bool> vis(100001, false);
    queue<PII> q;
    q.push(MP(x, 0));
    vis[x] = true;
    while (!q.empty()) {
        PII now = q.front();
        q.pop();
        if (now.first == y) {
            cout << now.second << endl;
            return;
        }
        if (now.first + 1 <= 100000 && !vis[now.first + 1]) {
            q.push(MP(now.first + 1, now.second + 1));
            vis[now.first + 1] = true;
        }
        if (now.first - 1 >= 0 && !vis[now.first - 1]) {
            q.push(MP(now.first - 1, now.second + 1));
            vis[now.first - 1] = true;
        }
        if (now.first * 2 <= 100000 && !vis[now.first * 2]) {
            q.push(MP(now.first * 2, now.second + 1));
            vis[now.first * 2] = true;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}