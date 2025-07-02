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
int gcd(int a, int b) {
    while (b ^= a ^= b ^= a %= b)
        ;
    return a;
}
void solve() {
    int n, m;
    cin >> n >> m;
    if (gcd(n, m) == 1)
        cout << "Yes" << endl;
    else {
        cout << "No" << endl;
        return;
    }
    int j = 1;
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        cout<< (i*(m)+1) << " ";
        a.push_back(i * (m) + 1);
    }
    cout << endl;
    j = 1;
    for (int i = 0; i < m; i++) {
        cout << (i*n+1) << " ";
        b.push_back(i * n + 1);
        j += (m - 1);
    }
    cout << endl;
    // set<int> vis;
    // for (int i = 0; i < a.size(); i++) {
    //     for (int j = 0; j < b.size(); j++) {
    //         cout << (a[i] * b[j]) % (n * m) << " ";
    //         vis.insert((a[i] * b[j]) % (n * m));
    //     }
    //     cout << endl;
    // }
    // if(vis.size() != n * m) {
    //     cout << "BAKAA" << endl;
    //     return;
    // }
    // cout << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}