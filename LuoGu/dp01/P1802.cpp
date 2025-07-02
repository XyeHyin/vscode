#include <bits/stdc++.h>
using namespace std;
#define int long long
struct XyeHyin{
    int lose,win, need;
};
signed main(){
    int n, x;
    cin >> n >> x;
    vector<XyeHyin> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i].lose >> a[i].win>>a[i].need;
    }
    sort(a.begin(), a.end(), [](XyeHyin a, XyeHyin b){
        return a.need<b.need;
    });
    vector<int> dp(x+1, 0); 
    for(int i=0; i<n; i++){
        for(int j=x; j>=a[i].need; j--){
            dp[j]=max(dp[j]+a[i].lose, dp[j-a[i].need]+a[i].win);
        }
        for(int j=a[i].need-1; j>=0; j--){
            dp[j]=dp[j]+a[i].lose;
        }
    }
    cout << 5*dp[x]<<endl;
    return 0;
}