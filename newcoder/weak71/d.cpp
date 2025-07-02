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
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = LLONG_MAX;
    vector<int> dic = {0, 1, 2};
    do {
        vector<vector<int>> dp(n + 1, vector<int>(3, LLONG_MAX));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            int tmp = s[i] - '0';
            int aa = (dic[0] != tmp) ? a[i] : 0;
            int bb = (dic[1] != tmp) ? a[i] : 0;
            int cc = (dic[2] != tmp) ? a[i] : 0;
            if (dp[i][0] != LLONG_MAX)dp[i + 1][0] = dp[i][0] + aa;
            if (dp[i][0] != LLONG_MAX || dp[i][1] != LLONG_MAX)dp[i + 1][1] = min(dp[i][0], dp[i][1]) + bb;
            if (dp[i][1] != LLONG_MAX || dp[i][2] != LLONG_MAX) dp[i + 1][2] = min(dp[i][1], dp[i][2]) + cc;
        }
        ans = min(ans, min(min(dp[n][0], dp[n][1]), dp[n][2]));
    } while (next_permutation(dic.begin(), dic.end()));
    cout << ans << endl;
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