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
const int MOD = 1e9+7;
int n, k;
void solve() {
    cin >> n >> k;
    vector<bool> vis(n + 1, false);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        vis[x] = true;
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dic(n + 1, 0);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] && !dic[i]) {
            cnt++;
            stack<int> st;
            st.push(i);
            dic[i] = cnt;
            while (!st.empty()) {
                int top = st.top();
                st.pop();
                for (auto nx : adj[top]) {
                    if (vis[nx] && !dic[nx]) {
                        dic[nx] = cnt;
                        st.push(nx);
                    }
                }
            }
        }
    }
    vector<int> cnt2(cnt + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            for (auto v : adj[i]) {
                if (!vis[v]) {
                    cnt2[dic[i]]++;
                }
            }
        }
    }
    int ans = 1;
    for (int i = 1; i <= cnt; i++) {
        if (cnt2[i] == 0) {
            cout << cnt << " 0"<<endl;
            return;
        }
        ans = (ans * cnt2[i]) % MOD;
    }
    cout << cnt << " " << ans << endl;
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