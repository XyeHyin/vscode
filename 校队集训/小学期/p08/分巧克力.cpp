#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
vector<pair<int, int>> a;
bool check(int x) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += (a[i].first / x) * (a[i].second / x);
    }
    return cnt >= k;
}
int find(int l, int r) {
    int ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}
signed main() {

    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    int l = 0, r = 1e9;
    cout << find(l, r) << endl;

    return 0;
}