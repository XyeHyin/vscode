#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define PII pair<int, int>
#define dbg(x) std::cout << #x << ":" << x << " "
#define MP make_pair
#define PB push_back
#define rep(i, x, n) for (int i = x; i <= n; i++)
#define dep(i, x, n) for (int i = x; i >= n; i--)
#define arrout(a, n) rep(i, 1, n) std::cout << a[i]
#define arrin(a, n) rep(i, 1, n) std::cin >> a[i]
#define endl '\n'
vector<int> a;
int n, x, sum;
bool check(int y) {
    // cout << y << endl;
    if (y > n) {
        return false;
    }
    int sum = 0;
    for (int i = 1; i <= y; i++) {
        sum += a[i];
    }
    if (sum < 2 * x) {
        return false;
    }
    for (int i = 1; i + y <= n; i++) {
        // dbg(i);
        //  dbg(sum) << endl;
        sum += a[i + y];
        sum -= a[i];
        if (sum < 2 * x) {
            return false;
        }
    }
    return true;
}
void solve() {
    cin >> n >> x;
    a.resize(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    a[0] = 0;
    a[n] = 0x3f3f3f;38
    int l = 0, r = n, mid, ans;
    while (l +1< r) {
        mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}