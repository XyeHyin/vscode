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
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void solve(){
    int n;
    cin >> n;
    vector<vector<char>> mp(n, vector<char>(n));
    rep(i, 0, n - 1){
        rep(j, 0, n - 1){
            cin >> mp[i][j];
        }
    }
    vector<vector<int>> bai(n, vector<int>(n, -1));
    vector<int> dic;
    vector<unordered_set<int>> adj;
    int cntt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mp[i][j] == '*' && bai[i][j] < 0) {
                int cnt = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                bai[i][j] = cntt;
                unordered_set<int> st;
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    cnt++;
                    for (int i = 0; i < 4; i++) {
                        int nx = x + dx[i], ny = y + dy[i];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (mp[nx][ny] == '.') {
                            st.insert(nx*n+ny);
                        } else if (mp[nx][ny] == '*' && bai[nx][ny] < 0) {
                            bai[nx][ny] = cntt;
                            q.push({nx, ny});
                        }
                    }
                }
                dic.push_back(cnt);
                adj.push_back(st);
                cntt++;
            }
        }
    }
    unordered_map<int, int> sum;
    int ans = 0;
    for (int i = 0; i < cntt; i++) {
        if (adj[i].size() == 1) {
            sum[*(adj[i].begin())] += dic[i];
            ans = max(ans, sum[*(adj[i].begin())]);
        }
    }
    cout << ans << endl;
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