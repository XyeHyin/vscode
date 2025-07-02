#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int hong = 0, zi = 0;
        sort(a.begin(), a.end(), greater<int>());
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) hong += a[i];
            else zi += a[i];
        }
        hong=hong-a[0]+a[n-1];
        zi=zi-a[n-1]+a[0];
        if (hong>zi) {
            cout << "kou" << endl;
        } else if (hong<zi) {
            cout << "yukari" << endl;
        } else {
            cout << "draw" << endl;
        }
    }
    return 0;
}