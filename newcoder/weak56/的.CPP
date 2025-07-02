#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<int>());
        int maxx = -1;
        for (int i = 0; i < n - 2; i++) {
            if (a[i] < a[i + 1] + a[i + 2]) {
                maxx = a[i] + a[i + 1] + a[i + 2];
                break;
            }
        }
        cout << maxx << endl;
    }
    return 0;
}