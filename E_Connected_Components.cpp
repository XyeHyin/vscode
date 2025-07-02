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
const int maxn = 1e6 + 1;
int fa[maxn];
int findfather(int x) { return fa[x] = (fa[x] == x ? x : findfather(fa[x])); }
void merge(int a, int b) {
    int na = findfather(a);
    int nb = findfather(b);
    fa[na] = nb;
}
void solve() {
    int n;
    cin >> n;
    vector<PII> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= n;i++){
        fa[i] = i;
    }
    for (int i = 1; i < n;i++){
        for (int j = i+1; j <= n;j++){
            auto [x, y] = a[i];
            auto [p, q] = a[j];
            if((x-p<=i-j&&i-j<=y-q)||(p-x<=j-i&&j-i<=q-y)) {
                merge(i, j);
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n;i++){
        if(fa[i]==i)
            cnt++;
    }
    cout << cnt << endl;
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