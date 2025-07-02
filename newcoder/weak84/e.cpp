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
const int maxn = 1e5 + 10;
int n;
vector<int> w[maxn];
vector<int> t[maxn];
int s = 0;
int ans = LLONG_MAX;
int dfs(int x, int y) {
    int sum = 0;
    for (int i = 0; i < t[x].size(); i++) {
        if (t[x][i] == y) continue;
        int tmp = dfs(t[x][i], x);
        ans = min(ans, llabs(s -w[x][i] -2 * tmp));
        sum += tmp+w[x][i];
    }
    return sum;
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        int tmp = llabs(u - v);
        s += tmp;
        t[u].push_back(v);
        w[u].push_back(tmp);
        t[v].push_back(u);
        w[v].push_back(tmp);
    }
    dfs(1, 0);
    cout << ans << endl;
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