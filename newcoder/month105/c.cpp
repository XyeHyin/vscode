#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int, int>
#define dbg(x) std::cout << #x << ":" << x << " "
#define MP make_pair
#define PB push_back
#define rep(i, x, n) for (int i = x; i <= n; i++)
#define dep(i, x, n) for (int i = x; i >= n; i--)
#define arrout(a, n) rep(i, 1, n) std::cout << a[i]
#define arrin(a, n) rep(i, 1, n) std::cin >> a[i]
#define endl '\n'
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int n;
const int maxn = 2e5 + 10;
vector<vector<int>> mp;
vector<vector<bool>> flag;

void dfs(int x, int y) {
    flag[x][y] = 1;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx >= 1 && nx <= 2 && ny >= 1 && ny <= n && mp[nx][ny] == 0 && !flag[nx][ny]) {
            dfs(nx, ny);
        }
    }
}
 bool check(int x, int y) {
    flag.resize(3, vector<bool>(n + 1, 0));
    fill(flag.begin(), flag.end(), vector<bool>(n + 1, 0));
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx >= 1 && nx <= 2 && ny >= 1 && ny <= mp[0].size() - 2 && mp[nx][ny] && !flag[nx][ny]) {
            return false;
        }
    }
    return true;
}
void solve() {
    cin >> n;
    mp.resize(3, vector<int>(n + 1));
    fill(mp.begin(), mp.end(), vector<int>(n + 1, 0));
    rep(i, 1, 2) rep(j, 1, n) {
        char x;
        cin >> x;
        if (x == 'x')
            mp[i][j] = 0;
        else
            mp[i][j] = 1;
    }
    int cnt = 0;
    rep(i, 1, 2) rep(j, 1, n) {
        if (mp[i][j]) {
            mp[i][j] = 0;
            if (!check(i, j)) cnt++;
            mp[i][j] = 1;
        }
    }
    cout << cnt/2 << endl;
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