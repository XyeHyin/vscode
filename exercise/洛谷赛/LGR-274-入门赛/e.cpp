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
    int x, n;
    cin >> x >> n;
    int cnt[5] = {0};
    while (n--) {
        int tmp = 0, ans = 0;
        rep(i, 0, 4) {
            int xx;
            cin >> xx;
            if (xx > tmp&&x-xx>=0) {
                tmp = xx;
                ans = i;
            }
        }
        if(x-tmp>=0){
            x-=tmp;
            cnt[tmp-1]++;
        }
    }
    rep(i, 0, 4) cout << cnt[i] << " ";
    cout << endl;
    cout<<x<<endl;
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