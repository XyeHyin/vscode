#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> coin(n);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    int aim;
    cin >> aim;
    int maxx = aim + 1;
    vector<int> dp(maxx, maxx);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= aim; j++) {
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }
    if (dp[aim] == maxx) {
        cout << "impossible" << endl;
    } else {
        cout << dp[aim] << endl;
    }
    return 0;
};
