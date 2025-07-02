#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum1 += (a[i] + a[j]) % 100000000;
        }
    }
    cout << sum1 << endl;
    return 0;
}