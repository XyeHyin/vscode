// name: P_3389_模板_高斯消元法.cpp
// date 2025-06-25
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
#define coutf(x) cout << fixed << setprecision(x)

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
template <typename... Args> void print(const Args &...args) {
    ((cout << args << ' '), ...);
    cout << '\n';
}
template <typename... Args> void printn(const Args &...args) {(cout << ... << args);cout << '\n';}
void solve() {
    int n;
    cin >> n;
    vector<vector<double>> a(n, vector<double>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int maxx = i;
        for (int j = 0; j < n; j++) {
            if (j < i && fabs(a[j][j]) >= eps) {
                continue;
            }
            if (fabs(a[j][i]) > fabs(a[maxx][i])) {
                maxx = j;
            }
        }
        swap(a[i], a[maxx]);
        if (fabs(a[i][i]) < eps) {
            continue;
        }
        for (int j = n; j >= i; j--) {
            a[i][j] /= a[i][i];
        }
        for (int j = i + 1; j < n; j++) {
            if (fabs(a[j][i]) < eps)
                continue;
            for (int k = n; k >= i; k--) {
                a[j][k] -= a[i][k] * a[j][i] / a[i][i];
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            a[i][n] -= a[i][j] * a[j][n];
        }
    }
    for (int i = 0; i < n; i++) {
        if (fabs(a[i][i]) < eps) {
            if (fabs(a[i][n]) > eps) {
                cout << "-1" << endl;
                return;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (fabs(a[i][i]) < eps) {
            cout << 0 << endl;
            return;
        }
    }
    
    for (int i = 0; i < n; i++) {
        coutf(2);
        printn("x", i + 1, "=", a[i][n]);
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