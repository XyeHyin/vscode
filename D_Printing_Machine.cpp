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
struct XyeHYin {
    int x, y;
    bool operator<(const XyeHYin &other) const {
        return x > other.x || (x == other.x && y > other.y);
    }
};
struct XyeHyin2{
    int first, second;
    bool operator<(const XyeHyin2 &other) const {
        return second > other.second || (second == other.second && first > other.first);
    }
};
void solve() {
    int n;
    cin >> n;
    priority_queue<XyeHYin> pq;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pq.push({x, x+y});
    }
    priority_queue<XyeHyin2> q;
    int time = pq.size() ? pq.top().x : 0;
    int cnt = 0;
    while (!pq.empty()|| !q.empty()) {
        while (!pq.empty() && pq.top().x == time) {
            q.push({pq.top().x, pq.top().y});
            pq.pop();
        }
        while (!q.empty() && q.top().second < time) {
            q.pop();
        }
        if (!q.empty()) {
            auto [x, y] = q.top();
            q.pop();
            cnt++;
        }
        if(q.size()){
            time++;
        }else{
            time = pq.size() ? pq.top().x : time;
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