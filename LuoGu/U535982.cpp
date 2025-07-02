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
    string s;
    cin >> s;
    string dica="",dicb="";
    for(int i = 0; i < n; i++) {
        dica += "AB";
        dicb += "BA";
    }
    int dp1 = 0, dp2 = 0;
    for(int i = 0; i < 2*n; i++) {
        if(s[i] != dica[i]) dp1++;
        if(s[i] != dicb[i]) dp2++;
    }
    cout << min(dp1/2, dp2/2) << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}