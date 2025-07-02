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
const int maxn = 1e3+10;
int grid[maxn][maxn];
void solve(){
    int a, b, n;
    cin>>a>>b>>n;
    for (int i = 1;i<=a;i++){
        for(int j = 1;j<=b;j++){
            cin>>grid[i][j];
        }   
    }
    deque<deque<PII>> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            
        }
    }    
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