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
    int n, m;
    cin >> n >> m;
    vector<int> dic(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> dic[i];
    }
    vector<int> a(n, 0);
    vector<vector<PII>> b(n);
    int maxx = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int cnt = 0;
        for(int j = 0; j < m; j++) {
            if (s[j] == 'o') {
                cnt+= dic[j];
            } else {
                b[i].PB({dic[j], j});
            }
        }
        a[i] = cnt+(i+1);
        maxx = max(maxx, a[i]);
    }
    for(int i = 0; i < n; i++) {
        sort(b[i].begin(), b[i].end());
    }
    for(int i = 0; i < n; i++) {
        int ans = 0;
        int tmp = a[i];
        if(tmp == maxx) {
            cout << 0 << endl;
            continue;
        }
        while(tmp<=maxx){
            if (b[i].empty()) {
                break;
            }
            ans ++;
            tmp += b[i].back().first;
            b[i].pop_back();
        }
        cout<<ans<<endl;
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