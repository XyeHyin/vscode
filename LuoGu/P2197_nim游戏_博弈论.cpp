#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            ans ^= tmp;
        }
        if (!ans) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}