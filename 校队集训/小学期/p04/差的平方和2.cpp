#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    vector<int> num(n);
    int sum = 0, sum1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        sum1 += num[i];
    }
    for (int i = 0; i < n; i++) {
        sum += (n - 1) * num[i] * num[i];
        sum1 -= num[i];
        sum -= num[i] * sum1 * 2;
    }
    cout << sum;
    return 0;
}