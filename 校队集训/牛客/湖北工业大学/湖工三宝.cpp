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
struct XyeHyin {
    int a, b, c, end;
    int sum;
};
void solve() {
    int n;
    cin >> n;
    vector<XyeHyin> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].a >> a[i].b >> a[i].c >> a[i].end;
        a[i].sum = a[i].a + a[i].b + a[i].c;
    }
    sort(a.begin() + 1, a.end(), [](XyeHyin x, XyeHyin y) {
        return x.end-x.sum < y.end - y.sum;
    });
    int ans = 0;
    int time = 0;
    for(int i = 1; i <= n; i++) {
        cout<< a[i].a << " " << a[i].b << " " << a[i].c << " " << a[i].end << endl;
    }
    for (int i = 1; i <= n; i++) {
        a[i].sum += time;
        if (a[i].sum<= a[i].end) {
            ans++;
            time += a[i].a + a[i].b + a[i].c;
        }
    }
    cout << ans << endl;
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