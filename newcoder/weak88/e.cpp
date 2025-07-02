#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define PII pair<int, int>
#define dbg(x) std::cout << #x << ":" << x << " "
#define MP make_pair
#define PB push_back
#define rep(i,x,n) for(int i=x;i<=n;i++)
#define dep(i,x,n) for(int i=x;i>=n;i--)
#define arrout(a,n) rep(i,1,n)std::cout<<a[i]
#define arrin(a,n) rep(i,1,n)std::cin>>a[i]
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<int> dp0(n + 1,0), dp1(n + 1,0);
    dp0[1] = a[1];
    dp1[1] = LLONG_MIN;
    for (int i = 2; i <= n; i++) {
        int tmp = LLONG_MIN;
        if (dp1[i - 1] >= k) tmp = dp1[i - 1] - k + a[i];
        dp0[i] = max(dp0[i - 1] + a[i], tmp);
        int tmpp = LLONG_MIN;
        if (dp0[i - 1] >= k) tmpp = dp0[i - 1] - k + b[i];
        dp1[i] = max(dp1[i - 1] + b[i], tmpp);
    }
    cout << max(dp0[n], dp1[n]) << endl;
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