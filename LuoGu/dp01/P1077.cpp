#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<int> dp(m+1, 0);
    dp[0] = 1;
    for(int i=0; i<n; i++){
        for (int j = m;j>0;j--){
            for(int k=1; k<=min(a[i], j); k++){
                dp[j] = (dp[j] + dp[j-k]) % 1000007;
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}