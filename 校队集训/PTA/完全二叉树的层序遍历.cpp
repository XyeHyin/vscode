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
vector<int> a;
vector<int> g; 
void build(int be, int n, int it) {
    if (n <= 0) return;
    int len = log2(n+1);
    int l = (1 << (len - 1)) - 1 + min(n - ((1LL << len) - 1), 1LL << (len - 1));
    build(be, l, it * 2);
    build(be + l, n - 1 - l, it * 2 + 1);
    g[it] = a[be + n - 1];
}

void solve() {
    int n;
    cin >> n;
    a.assign(n,0);
    for (int i = 0; i < n; i++)  cin >> a[i];
    g.assign(n + 1,0);
    build(0, n, 1);
    for (int i = 1; i <= n; i++) {
        cout << g[i]<<" "[i == n];
    }
    cout << endl;
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