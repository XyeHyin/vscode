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
    sort(a.begin(), a.end());
    int mid = a[n / 2];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(a[i] - mid);
    }
    cout << sum << endl;
    return 0;
}