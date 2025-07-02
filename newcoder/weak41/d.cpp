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
    int n, q;
    cin >> n >> q;
    vector<char> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> cr(n + 1);
    vector<int> ce(n + 1);
    vector<int> cd(n + 1);
    for (int i = 1; i <= n; i++) {
        cr[i] = cr[i - 1] + (a[i] == 'r');
        ce[i] = ce[i - 1] + (a[i] == 'e');
        cd[i] = cd[i - 1] + (a[i] == 'd');
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        if (len < 3) {
            cout << 0 << endl;
            continue;
        }
        
        vector<int> ans(3, len / 3);
        int cnt = len % 3;
        for (int i = 0; i < cnt; i++) {
            ans[i]++;
        }
        sort(ans.begin(), ans.end());
        int maxx = 0;
        do {
            /* for(int i = 0; i < 3; i++) {
                cout << ans[i] << " ";
            }
            cout << endl; */
            maxx = max(maxx,cr[l + ans[0]-1] - cr[l - 1] +
                                 ce[l + ans[0] + ans[1]-1] - ce[l + ans[0] - 1] +
                                 cd[r] - cd[r-ans[2]]);
           /*  cout << cr[l + ans[0]-1]-cr[l-1] << endl;
            dbg(ans[0]) << endl;
            cout<< ce[l + ans[0] + ans[1]-1]-ce[l + ans[0] - 1] << endl;
            dbg(ans[1]) << endl;
            cout << cd[r] - cd[r-ans[2]] << endl;
            dbg(ans[2]) << endl; */
        } while (next_permutation(ans.begin(), ans.end()));
        cout << len-maxx << endl;
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