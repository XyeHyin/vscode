#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> b = a;
    sort(a.begin()+1, a.end(),greater<int>());
    vector<pair<int,int>> dp(n + 1);
    int minn = 0x3f3f3f3f;
    dp[1].first = a[1];
    dp[1].second = a[1];
    for (int i = 2; i <= n; i++){
        minn = min(minn, a[i]);
        dp[i].first = i * i * minn;
        dp[i].second = minn;
    }
    auto it= max_element(dp.begin(), dp.end(),[](pair<int,int> a, pair<int,int> b) { return a.first < b.first; });
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if(b[i] >= it->second){
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}