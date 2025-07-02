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
    int n, ans;
    cin >> n;
    vector<int> a(n);
    vector<int> suf(n + 1, 0);
    for (int i = 0; i < n; i++)  cin >> a[i];
    for (int i = n - 1; i >= 0; i--)  suf[i] = suf[i + 1] + a[i];
    cout<<(ans=suf[0])<<" ";
    sort(suf.begin() + 1, suf.end()-1, greater<int>());
    for (int k = 1; k < n; k++) {
        ans += suf[k];
        cout << ans << " ";
    }
    cout << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}