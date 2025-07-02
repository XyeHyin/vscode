#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    while (b ^= a ^= b ^= a %= b)
        ;
    return a;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int flag = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        flag = gcd(flag, a[i]);
    }
    if (flag != 1) {
        cout << "INF" << endl;
        return 0;
    }
    vector<int> dp(10005, 0);
    dp[0] = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j < 10005; j++) {
            dp[j] = max(dp[j], dp[j - a[i]]);
        }
    }
    for (int i = 1; i < 10005; i++) {
        if (!dp[i]) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}