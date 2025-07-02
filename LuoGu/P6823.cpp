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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    vector<int> op(m);
    map<int, PII> mp;
    for (int i = 0; i < m; i++) {
        cin >> op[i];
        if (op[i] == 3) {
            int x, y;
            cin >> x >> y;
            mp[i] = {x, y};
        }
    }
    auto it = find_if(op.rbegin(), op.rend(),[](int x) { return x == 1 || x == 2; });
    if (it != op.rend()) {
        int idx = std::distance(op.begin(), it.base()) - 1; // 下标
        if (op[idx] == 1) {
            sort(a.begin(), a.end());
        } else if (op[idx] == 2) {
            sort(a.begin(), a.end(), greater<int>());
        }
        // 之后可以从idx+1开始处理后续操作
    }
    for (auto itt = it; itt != op.end(); itt++) {
        if (*itt == 3) {
            auto [x, y] = mp[itt - op.begin()];
            swap(a[x - 1], a[y - 1]);
        } else {
            reverse(a.begin(), a.end());
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
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