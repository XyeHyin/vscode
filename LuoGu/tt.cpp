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
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }
    int cnt = 1;
    map<int, priority_queue<int>> dic;

    if (!pq.empty()) {
        dic[0].push(pq.top());
        pq.pop();
    }
    while (!pq.empty()) {
        int xx = pq.top();
        pq.pop();
        if (!dic[cnt].size()) {
            dic[cnt].push(xx);
            continue;
        }
        int len = dic[cnt].size();
        int tp = dic[cnt].top();
        if (len < tp) {
            dic[cnt].push(xx);
        } else {
            pq.push(xx);
            bool flag = false;
            while (!pq.empty()) {
                if (pq.top() > pq.size()) {
                    flag = true;
                    dic[cnt].push(pq.top());
                    pq.pop();
                } else {
                    cnt++;
                    dic[cnt].push(xx);
                    break;
                }
            }
            if (!flag) {
                pq.pop();
            }
        }
    }
    cout << cnt << endl;
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