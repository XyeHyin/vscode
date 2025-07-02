#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> dp(n, 1);
    for (int i = 0; i < n;i++){
        for(int j = 0; j < i; j++){
                dp[i] = max(dp[i], dp[j]);
        }
        dp[i] ++;
    }
    cout<<dp[n-1]<<endl;    
        return 0;
}