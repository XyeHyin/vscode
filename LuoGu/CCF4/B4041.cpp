#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        sort(a.begin()+l-1, a.begin()+r);
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " "[i == n - 1];
    }

    return 0;
}