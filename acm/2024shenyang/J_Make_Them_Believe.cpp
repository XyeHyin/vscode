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
    vector<pair<string, int>> a;
    vector<pair<string, int>> b;
    for (int i = 0; i < 4; i++) {
        string s;
        int x;
        cin >> s >> x;
        a.push_back({s, x});
    }
    for (int i = 0; i < 4; i++) {
        string s;
        int x;
        cin >> s >> x;
        b.push_back({s, x});
    }
    sort(a.begin(), a.end(), [](pair<string, int> x, pair<string, int> y) {
        return x.second > y.second;
    });
    sort(b.begin(), b.end(), [](pair<string, int> x, pair<string, int> y) {
        return x.second > y.second;
    });
    auto [aa, bb] = a[0];
    auto [cc, dd] = b[0];
    if (bb > dd) {
        cout << aa << " beats " << cc << endl;
    } else {
        cout << cc << " beats " << aa << endl;
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