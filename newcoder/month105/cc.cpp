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
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> mp(4, vector<int>(n + 2, 0));
    rep(i, 1, 2) rep(j, 1, n) {
        char x;
        cin >> x;
        if (x == 'x')mp[i][j] = 0;
        else mp[i][j] = 1;
    }
    int cnt = 0;
    rep(i,1,2) rep(j,1,n){
        if(mp[i][j]){
            int cnt1=0,cnt2=0;
            for(int k=0;k<4;k++){
                int nx=i+dx[k],ny=j+dy[k];
                if(mp[nx][ny])cnt1++;
            }
            if(cnt1){
                if(j==1){
                    if(i==1){
                    if(!mp[2][j+1]&&mp[1][j+1])cnt++;
                    else if(!mp[2][j+1]&&mp[2][j])cnt++;
                    }else{
                        if(!mp[1][j+1]&&mp[2][j+1])cnt++;
                        else if(!mp[1][j+1]&&mp[1][j])cnt++;
                    }
                    continue;
                }else if(j==n){
                    if(i==1){
                        if(!mp[2][j-1]&&mp[1][j-1])cnt++;
                        else if(!mp[2][j-1]&&mp[2][j])cnt++;
                    }else{
                        if(!mp[1][j-1]&&mp[2][j-1])cnt++;
                        else if(!mp[1][j-1]&&mp[1][j])cnt++;
                    }
                    continue;
                }else{ 
                if(i==1){
                    if(!mp[2][j-1]&&mp[1][j-1])cnt++;
                    else if(!mp[2][j+1]&&mp[1][j+1])cnt++;
                    else if(!mp[2][j-1]&&!mp[2][j]&&mp[2][j])cnt++;
               }else{
                     if(!mp[1][j-1]&&mp[2][j-1])cnt++;
                     else if(!mp[1][j+1]&&mp[2][j+1])cnt++;
                     else if(!mp[1][j-1]&&!mp[1][j]&&mp[1][j])cnt++;
               }
                }
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