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
    vector<int> aa(n, 0), bb(n, 0);
    int ans = 0;
    for (int j = 1; j < n - 1; j++) {
        for (int i = 0; i < j; i++) {
            aa[j] = max(aa[j], min(a[i], a[j]) * (j - i));
        }
    
        for (int k = j + 1; k < n; k++) {
            bb[j] = max(bb[j], min(a[j], a[k]) * (k - j));
        }
        ans = max(ans, aa[j] + bb[j]);
    }

    cout << ans << endl;
    return 0;
}