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
    int t = 1;
    cout << "test:" << t++ << endl;
    while (1) {
        system("data.exe");
        system("cc.exe");
        system("c.exe");
        if (system("fc cc.out c.out > diff.log")) {
            cout << "WA\n";
            ifstream diffFile("diff.log");
            string line;
            while (getline(diffFile, line)) {
                cout << line << endl;
            }
            break;
        }
    }
    cout << "AC\n";
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