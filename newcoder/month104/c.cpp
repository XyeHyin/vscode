#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n;
vector<int> a;
bool check(int t) {
    int cnt1 = 0, cnt2 = 0;
    vector<int> tmp(n, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] > t) {
            tmp[i] = a[i] - t;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (tmp[i] > 0) {
            cnt2 += tmp[i];
            tmp[i + 1] -= tmp[i];
            tmp[i + 1] = max(0LL, tmp[i + 1]);
            tmp[i] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (tmp[i] > 0)
            cnt1 += tmp[i];
    }
    return cnt1 + cnt2 <= 2 * t;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = 1e12;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}