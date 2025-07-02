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
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void solve(){
    vector <vector<int>> flag(3,vector<int>(3,0));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin>>flag[i][j];
        }
    }
    int cnt = 0x3f3f3f3f;
        for (int i = 0; i < (1 << 9); i++) {
        vector <vector<int>> ans=flag;
        for(int j = 0;j<9;j++){
            if (i&(1<<j)){
                int x = j/3;
                int y = j%3;
                ans[x][y] = !ans[x][y];
                for (int k = 0;k<4;k++){
                    int xx = x+dx[k];
                    int yy = y+dy[k];
                    if (xx>=0 && xx<3 && yy>=0 && yy<3){
                        ans[xx][yy] = !ans[xx][yy];
                    }
                }
            }
        }
        bool ok = true;
        for (int j = 0;j<3;j++){
            for (int k = 0;k<3;k++){
                if (!ans[j][k]){
                    ok = false;
                }
            }
        }
        if(ok){
            cnt = min(cnt, (int)__builtin_popcount(i));
        }
    }
    cout<<cnt<<endl;
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