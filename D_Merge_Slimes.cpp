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
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        mp[a] = b;
    }
    for(auto i : mp) {
       auto [a, b] = i;
       mp[a] = 0;
         int len = log2(b);
        for (int j = 0; j <= len; j++) {
            if ((1LL<<j)&b) {
                mp[a * (1LL << (j))]++;
            }
        }
    }
    int cnt = 0;
    for (auto i : mp) {
        cnt += i.second;
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