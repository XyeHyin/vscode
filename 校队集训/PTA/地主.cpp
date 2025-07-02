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
int m, n;
char mp[101][101];
int vis[101][101] = {0};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int dfs(int x,int y){
    vis[x][y] = 1;
    int cnt = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && mp[nx][ny] == 'O' && !vis[nx][ny]){
            cnt += dfs(nx, ny);
        }
    }
    return cnt;
}
void solve(){
    cin>>m>>n;
    int initx, inity;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>mp[i][j];
            if(mp[i][j] == '@'){
                initx = i;
                inity = j;
            }
        }
    }
   
    cout<<dfs(initx, inity)<<endl;
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