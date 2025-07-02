#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (k == 1) {
            cout << accumulate(a.begin() + 1, a.end(), 0LL) << endl;
        } 
        else if (k == n) {
            if (a.back() < 0)
                cout << 0 << endl;
            else
                cout << a.back() << endl;
        }
         else if (k * 2 > n) {
            int maxx = LLONG_MIN;
            for (int i = k; i <= n - k + 1; i++) {
                int tmp = 0;
                for (int j = i; j < i + k; j++) {
                    tmp += a[j];
                }
                maxx = max(maxx, tmp);
            }
            cout << maxx << endl;
        }
         else {
            vector<int> dp(n + 1, LLONG_MIN);
            vector<int> sum(n + 1, LLONG_MIN);
            for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
            for (int i = 1; i <= n; i++) {
                if(i>=k){
                    if(i>=2*k){
                    int bei=i/k;
                    for(int j=0;j<=bei;j++){
                        dp[i]=max(dp[i-1],dp[j*k]+sum[i]-sum[j*k-1]);
                    }
                    }
                    else dp[i]=max(dp[i-1],sum[i]-sum[k-1]);
                }else dp[i] = 0;
            }
            for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
            cout<<endl;
            cout << dp[n] << endl;
        }
    }
    return 0;
}