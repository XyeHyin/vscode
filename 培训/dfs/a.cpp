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
bool flag[1005][1005];
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
int n, m;
int a[1005][1005];
int cnt = 0;
bool check(int x, int y){
        if (x >= 0 && x < n && y >= 0 && y < m) return 1;
        return 0;
    };
void dfs(int x, int y){
    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(check(nx, ny)){
            if(a[nx][ny] == 0) continue;
            a[nx][ny] = 0;
            dfs(nx, ny);
        }else{
            continue;
        }
    }
}
long long fastPow(long long base, long long power, long long mod) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        power >>= 1;
    }
    return result;
}
int gcd(int a, int b) {
    while (b ^= a ^= b ^= a %= b);
    return a;
}
void solve(){
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            if(c == 'W') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 1){
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << endl;
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