#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    if (n == 1){
        cout << nums[0];
        return 0;
    }
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n - 1; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    int ans = dp[n - 2];
    dp[1] = nums[1];
    dp[2] = max(nums[1], nums[2]);
    for (int i = 3; i < n; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    cout << max(ans, dp[n - 1]);
}