#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,m;
    cin >> t >> m;
    vector<pair<int, int>> a(m+1);
    for (int i = 1; i <= m;i++){
        cin >> a[i].first >> a[i].second;
    }
    vector<int> dp(t + 1, 0);
    for (int i = 1; i <= m;i++){
        for (int j = t ; j >= a[i].first;j--){
            dp[j] = max(dp[j], dp[j - a[i].first] + a[i].second);
        }
    }
    cout << dp[t];
    return 0;
}