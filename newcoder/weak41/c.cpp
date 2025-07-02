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

void solve() {
    string s;
    cin >> s;
    if(s.size() == 1) {
        if(stoll(s) % 4 == 0) {
            cout << 0 << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        if (stoll(s.substr(s.size() - 2)) % 4 == 0) {
            cout << s << endl;
            cout << i << endl;
            return;
        }
        char c = s.front();
        s = s.substr(1) + c;
    }
    cout << -1 << endl;

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