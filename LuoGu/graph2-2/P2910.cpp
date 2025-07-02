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
    vector<int> dic(m + 1);
    for(int i = 1; i <= m; i++){
        cin >> dic[i];
    }
    vector<vector<int>> edge(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
    for(int i = 1; i <= n; i++){
        edge[i][i] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>> edge[i][j];
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 2;i<= m; i++){
        ans+= edge[dic[i-1]][dic[i]];
    }
    cout << ans << endl;
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