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
    int n = 4, r = 3;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    vector<bool> v(n);
    fill(v.begin(), v.begin() + r, 1);
    do {
        vector<int> aa;
        for (int i = 0; i < n; ++i) {
            if (v[i]) {
                aa.push_back(a[i]);
            }
        }
        do {
            for (int i = 0; i < r; ++i) {
                cout << aa[i] << " ";
            }
            cout << endl;
        } while (next_permutation(aa.begin(), aa.end()));
    } while (prev_permutation(v.begin(), v.end()));
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