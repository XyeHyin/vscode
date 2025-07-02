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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1e18));
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int l = 1; l <= 6; l++) {
                if (j<l) break;
                int num=0;
                if (i == 1&&j - l) continue;
                else if(i!=1) num = dp[i - 1][j-l];
                dp[i][j] = max(dp[i][j], num + a[j]);
            }
        }
    }
    int ans = -1e18;
    for (int j = 1; j <= n; j++) ans = max(ans, dp[k][j]);
    cout << ans << endl;
    return;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)	solve();
    return 0;
}