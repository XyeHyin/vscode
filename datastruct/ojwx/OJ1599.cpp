#include <iostream>
using namespace std;
#define int long long
int dp[51];
signed main() {
    int M;
    cin >> M;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= 50; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    while (M--) {
        int N;
        cin >> N;
        cout << dp[N] << endl;
    }
    return 0;
}