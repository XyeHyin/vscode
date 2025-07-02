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
    // freopen("data1.in", "r", stdin);
    // freopen("c.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    char flag = s[s.size() - 1];
    int pos;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == flag) {
            pos = i;
        } else {
            break;
        }
    }
    vector<bool> vis(n, 0);
    // dbg(pos) << " ";
    for (int i = 0; i < n - 1; i++) {
        // dbg(m) << " ";
        // dbg(i) << endl;
        if (i >= pos) {
            break;
        }
        if (s[i] == s[i + 1]) {
            char tmp = s[i];
            int cnt = 0;
            int j;
            priority_queue<PII, vector<PII>, greater<PII>> pq;
            for (j = i; j < n; j++) {
                if (s[j] == tmp) {
                    cnt += a[j];
                    pq.push({a[j], j});
                } else {
                    break;
                }
            }
            // dbg(cnt) << " ";
            if (cnt > m) {
                while (!pq.empty()) {
                    PII t = pq.top();
                    pq.pop();
                    if (t.first <= m) {
                        vis[t.second] = 1;
                        m -= t.first;
                    } else {
                        break;
                    }
                }
            } else {
                for (int k = i; k < j; k++) {
                    vis[k] = 1;
                }
                m -= cnt;
            }
            i = j - 1;
        } else if (s[i] < s[i + 1] && m >= a[i]) {
            vis[i] = 1;
            m -= a[i];
        }
    }
    string ans = "";
    for (int i = 0; i < n; i++) {
        ans += s[i];
        if (vis[i]) {
            ans += s[i];
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