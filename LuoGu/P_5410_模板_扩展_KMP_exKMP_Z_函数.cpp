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
const int N = 2e7+5;
int z[N],p[N];
void get_z(string s,int n){
    z[1]=n;
    for(int i=2,l,r=0;i<=n;i++){
        if(i<=r) z[i]=min(r-i+1,z[i-l+1]);
        while(i+z[i]<=n&&s[z[i]+1]==s[i+z[i]]) z[i]++;
        if(i+z[i]-1>r) l=i,r=i+z[i]-1;
    }
}
void get_p(string s,int n,string t,int m){
    for(int i=1,l,r=0;i<=m;i++){
        if(i<=r) p[i]=min(r-i+1,z[i-l+1]);
        while(1+p[i]<=n&&i+p[i]<=m&&s[1+p[i]]==t[i+p[i]]) p[i]++;
        if(i+p[i]-1>r) l=i,r=i+p[i]-1;
    }
}
void solve(){
    string a, b;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    int n = b.size() - 1, m = a.size() - 1;
    get_z(b, n);
    get_p(b, n, a, m);
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++)  ans1 ^= (i * (z[i] + 1));
    for (int i = 1; i <= m; i++)  ans2 ^= (i * (p[i] + 1));
    cout << ans1 << endl << ans2 << endl;
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