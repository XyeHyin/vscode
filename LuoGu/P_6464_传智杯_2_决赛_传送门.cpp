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

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mp(n + 1, vector<int>(n + 1,0x3f3f3f3f));
    for(int i = 1; i <= m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        mp[x][y] = min(mp[x][y], z);
        mp[y][x] = min(mp[y][x], z);
    }
    for(int i = 1; i <= n; i++) mp[i][i] = 0;
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
    int minn=LLONG_MAX;
    vector<vector<int>> a;
    for(int i=1; i <= n; i++){
        for(int j=1; j <= n; j++){
            a = mp;
            a[i][j] = a[j][i] = 0;
            for(int x=1; x <= n; x++){
                for(int y=1; y <= n; y++){
                    a[x][y] = min(a[x][y], a[x][i] + a[i][y]);
                }
            }
            for(int x=1; x <= n; x++){
                for(int y=1; y <= n; y++){
                    a[x][y] = min(a[x][y], a[x][j] + a[j][y]);
                }
            }
            int tmp = 0;
            for(int x=1; x <= n; x++){
                for(int y=x+1; y <= n; y++){
                    tmp += a[x][y];
                }
            }
            minn = min(minn, tmp);
        }
    }
    cout << minn << endl;
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