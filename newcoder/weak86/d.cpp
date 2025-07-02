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
#define endl '\n'
int gcd(int a, int b) {
    while (b ^= a ^= b ^= a %= b);
    return a;
}
void solve() {
    int x, y;
    cin >> x >> y;
    if (x == 0 || y == 0) {
        cout << 0 << endl;
        return;
    }
    map<int, int> mp;
    vector<int> vis;
    queue<PII> q;
    auto in = [&](int x, int cnt) {
        if (mp.count(x)) {
            mp[x]++;
        } else {
            mp[x] = 1;
            vis.push_back(x);
            q.push({x, cnt});
        }
    };
    in(x, 0);
    in(y, 0);
    while (!q.empty()) {
        int a = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for (int b : vis) {
            if (a == b && mp[a] < 2)continue;
            vector<int> dic = {a & b,a | b,a ^ b,gcd(a, b)};
            for (int it : dic) {
                if (it == 0) {
                    cout << cnt + 1 << endl;
                    return;
                }
                if (!mp.count(it)) {
                    in(it, cnt + 1);
                }
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}