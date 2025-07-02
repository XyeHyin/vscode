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

void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    if (n >= 1) dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1];
        int sum2 = a[i - 1] + a[i];
        if (sum2 < 0)  dp[i] = max(dp[i],dp[i - 2]-sum2);
        if (i >= 3) {
            int sum3 = a[i - 2] + a[i - 1] + a[i];
            if (sum3 < 0) dp[i] = max(dp[i],dp[i - 3]- sum3);
        }
    }
    cout << sum + dp[n] << endl;
    return;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)	solve();
    return 0;
}