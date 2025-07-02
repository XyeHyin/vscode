#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    k = n - k;
     int ans = 0;
    for(int i = 0; i < n; i++) {
        if(i + k > n) break;
        int tmp = (accumulate(a.begin() + i, a.begin() + i + k, 0));
        ans=max(tmp,ans);
    }
    cout << ans << endl;
    return 0;
}   