#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, m;
    cin >> t >> m;
    vector<pair<int, int>> a;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back(make_pair(x, y));
    }
    vector<int> dp(t + 1, 0);
    for (int i = 0; i < m; i++) {
        for (int j = t; j >= a[i].first; j--) {
            dp[j] = max(dp[j], dp[j - a[i].first] + a[i].second);
        }
    }
    cout << dp[t] << endl;
    return 0;
}