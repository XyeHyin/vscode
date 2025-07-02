// name: 小红的数组操作.cpp
// date 2025-06-08
// author: XyeHyin

#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")

// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
// #include "atcoder/maxflow"
// #include "atcoder/mincostflow"
// #include "atcoder/modint"
// #include "atcoder/scc"
// #include "atcoder/segtree"
// #include "atcoder/string"
// #include "atcoder/twosat"
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

#define int long long
#define d64 long double
#define PII pair<int, int>
#define ff first
#define ss second
#define itn int
#define dbg(x) std::cout << #x << ":" << x << " "
#define dbgl(x) std::cout << #x << ":" << x << "\n"
#define all(x) x.begin(), x.end()
#define MP make_pair
#define PB push_back
#define rep(i, x, n) for (int i = x; i <= n; i++)
#define dep(i, x, n) for (int i = x; i >= n; i--)
#define arrout(a, n) rep(i, 1, n) std::cout << a[i]
#define arrin(a, n) rep(i, 1, n) std::cin >> a[i]
#define arrin0(a, n) rep(i, 0, n - 1) std::cin >> a[i]
#define arrout0(a, n) rep(i, 0, n - 1) std::cout << a[i]
#define endl "\n"
#define mem(a, x) memset(a, x, sizeof a)
#define YES() cout << "YES" << endl
#define NO() cout << "NO" << endl
#define Yes() cout << "Yes" << endl
#define No() cout << "No" << endl
#define yes() cout << "yes" << endl
#define no() cout << "no" << endl

const int mod = 1e9 + 7;
const int N = 1e5 + 5;
const int INF = 1e18;
const int inf = 0x3f3f3f3f;
const PII d8[8] = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                   {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
const PII d4[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const PII d3[3] = {{0, 1}, {1, 0}, {0, 1}};
const PII d2[2] = {{0, 1}, {1, 0}};
const double PI = acos(-1);
const double eps = 1e-9;
const int mod1 = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    set<int> se;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        se.insert(a[i]);
    }
    if (se.size() == n) {
        cout << 0 << endl;
        return;
    }
    vector<int> pre(n + 2, 0);
    vector<int> suf(n + 2, 0);
    map<int, int> mp;
    map<int, int> mp2;
    set<int> s;
    int ans = 0;
    bool ok = 0;
    int start = -1;
    for (int i = 1; i <= n; i++) {
        int len = s.size();
        s.insert(a[i]);
        if (s.size() == len) {
            if (ok) {
                pre[i] = max(mp[a[i]], pre[i - 1]);
                mp[a[i]] = i;
                continue;
            }
            start = i;
            pre[i] = max(mp[a[i]], pre[i - 1]);
            mp[a[i]] = i;
            ans = a[i] * (n - i + 1);
            ok = 1;
        } else {
            mp[a[i]] = i;
            pre[i] = pre[i - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << pre[i] << " ";
    }
    cout << endl;
    s.clear();
    bool ok2 = 0;
    int end = 1e18;
    for (int i = n; i > 0; i--) {
        int len = s.size();
        s.insert(a[i]);
        if (s.size() == len) {
            if (ok2) {
                suf[i] = min(mp2[a[i]], suf[i + 1]);
                mp2[a[i]] = i;
                continue;
            }
            end = i;
            suf[i] = mp2[a[i]];
            mp2[a[i]] = i;
            ans = min(ans, a[i] * (i));
            ok2 = 1;
        } else {
            mp2[a[i]] = i;
            suf[i] = suf[i + 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << suf[i] << " ";
    }
    cout << endl;
    // cout<<start << " " << end << endl;
    // if (start != -1) {
    //     for (int i = start; i <= n; i++) {
    //         cout << (pre[i - 1] * a[pre[i - 1]] +
    //                  (n - suf[i + 1] + 1) * a[suf[i + 1]])
    //              << " ";
    //         ans = min(ans, (pre[i - 1] * a[pre[i - 1]] +
    //                         (n - suf[i + 1] + 1) * a[suf[i + 1]]));
    //     }
    //     cout << endl;
    // }
    // if (end != 1e18) {
    //     for (int i = 1; i <= end; i++) {
    //         cout << (pre[i - 1] * a[pre[i - 1]] +
    //                  (n - suf[i + 1] + 1) * a[suf[i + 1]])
    //              << " ";
    //         ans = min(ans, (pre[i - 1] * a[pre[i - 1]] +
    //                         (n - suf[i + 1] + 1) * a[suf[i + 1]]));
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i++) {
        if (pre[i] == 0 || suf[i] == 0)
            continue;
        ans = min(ans, (pre[i] * a[pre[i]] + (n - suf[i] + 1) * a[suf[i]]));
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