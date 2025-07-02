#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define PII pair<int, int>
#define dbg(x) std::cout << #x << ":" << x << " "
#define MP make_pair
#define PB push_back
#define rep(i,x,n) for(int i=x;i<=n;i++)
#define dep(i,x,n) for(int i=x;i>=n;i--)
#define arrout(a,n) rep(i,1,n)std::cout<<a[i]
#define arrin(a,n) rep(i,1,n)std::cin>>a[i]
#define endl '\n'
const int N = 2e5 + 5;
int n, a, b, x, y, k, dis[N], cnt[N];
void solve(){
    cin >> n >> k >> a >> b >> x >> y;
    memset(dis, 0x3f, sizeof(dis));
    a--, b--;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>pq;
    pq.push({0, a, 0});
    int inf = dis[a];
    dis[a] = 0;
    while (pq.size()) {
        auto it = pq.top();
        pq.pop();
        int d = it[0], u = it[1], t = it[2];
        if (d != dis[u] || t != cnt[u]) continue;
        int v = (u + x) % n;
        if (dis[v] > dis[u] + 1) {
            dis[v] = dis[u] + 1;
            cnt[v] = cnt[u];
            pq.push({dis[v], v, cnt[v]});
        }
        v = (u - y + n) % n;
        if (dis[v] > dis[u] + 1) {
            dis[v] = dis[u] + 1;
            cnt[v] = cnt[u];
            pq.push({dis[v], v, cnt[v]});
        }
        if (t + 1 <= k) {
            v = (u + n / 2) % n;
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                cnt[v] = cnt[u] + 1;
                pq.push({dis[v], v, cnt[v]});
            } else if (dis[v] == dis[u] + 1 && cnt[v] > cnt[u] + 1) {
                cnt[v] = cnt[u] + 1;
                pq.push({dis[v], v, cnt[v]});
            }
        }
    }
    if (dis[b] > inf / 2) dis[b] = -1;
    cout << dis[b];
    return;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)	solve();
    return 0;
}