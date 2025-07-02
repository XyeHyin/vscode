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
    int n;
    cin >> n;
    vector<string> a(101);
    vector<string> dic(n + 1);
    int maxx = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        dic[i] = s;
        maxx = max(maxx, (int)dic[i].size());
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < maxx; j++) {
            if (j >= dic[i].size())
                a[j] += '*';
            else
                a[j] += dic[i][j];
        }
    }
    for (int i = 0; i < maxx; i++) {
        string s = a[i];
        for (int j = s.size() - 1; j >= 0; j--) {
            if (s[j] == '*') {
                s.erase(j, 1);
            } else
                break;
        }
        cout << s << endl;
    }
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