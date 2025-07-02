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
void solve() {
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    bool flag = false;
    if (xa == 0 && (xb + xc) == 0)flag = true;
    if (ya == 0 && (yb + yc) == 0)flag = true;
    if (xb == 0 && (xa + xc) == 0)flag = true;
    if (yb == 0 && (ya + yc) == 0)flag = true;
    if (xc == 0 && (xa + xb) == 0)flag = true;
    if (yc == 0 && (ya + yb) == 0)flag = true;
    cout << (flag ? "YES" : "NO") << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)	solve();
    return 0;
}