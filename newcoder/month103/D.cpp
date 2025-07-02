#include <bits/stdc++.h>
using namespace std;
#define int long long
double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}      
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        unordered_set<string> ans;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int aa = a[i] + a[j];
                int bb = b[i] + b[j];
                ans.insert(to_string(aa) + "+" + to_string(bb));
            }
        }
        cout << ans.size() << endl;
    }
    return 0;
}