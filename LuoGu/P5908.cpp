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
    vector<int> adj[100005];
    vector<int> vis(100005, 0);
    int n, dd;
    int dfs(int x,int step) {
        int ans = step;
        vis[x] = 1;
        for (auto a : adj[x]) {
            if (vis[a])continue;
            ans+=dfs(a,step+1);
        }
        return ans;
    }
    void solve() {
        cin >> n;
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].PB(y);
            adj[y].PB(x);
        }
        int minn = 0x3f3f3f3f, ans;
        for(int i = 1; i <= n; i++) {
            vis.assign(n+1, 0);
            int tmp=dfs(i,0);
            // dbg(tmp) << endl;
            if(tmp<minn){
                ans=i;
            }
            minn=min(minn,tmp);
        }
        cout<<ans<<" " << minn << endl;
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