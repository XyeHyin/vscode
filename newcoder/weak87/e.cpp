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
    int n, x, y;
    cin >> n >> x >> y;
    if ((x & y) != y) {
        cout << "NO" << endl;
        return;
    }
    if (x < y) {
        cout << "NO" << endl;
        return;
    }
    if (n == 1) {
        if (x == y)
            cout << "YES" << endl << x << endl;
        else
            cout << "NO" << endl;
        return;
    }
    int dic = x ^ y;
    int len = log2(x);
    cout << "YES" << endl;
    int cnt = 0;
    vector<int> ans;
    ans.push_back(x);
    ans.push_back(x);
    for (int i = 0; i <= len; i++) {
        if (cnt == n - 2) {
            int tmp = 0;
            for (int j = i; j <= len; j++) {
                if ((dic >> j) & 1) {
                    tmp |= (1ll << j);
                }
            }
            ans.push_back(tmp);
            cnt++;
            break;
        }
        if ((dic >> i) & 1) {
            cnt++;
            ans.PB(1ll << i);
        }
    }
    int num=n-ans.size();
    if(num&1){
        int tmpp=ans.back();
        ans.pop_back();
        ans.back()|=tmpp;
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    for (int i = 0; i < num; i++) {
        cout << y << " ";
    }
    cout << endl;
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