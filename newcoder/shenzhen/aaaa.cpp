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
const int maxN = 10010;
int father[maxN], bird[maxN];
int findFather(int x) {
    return father[x] = (x == father[x] ? x : father[x] = findFather(father[x]));
}
void merge(int x, int y) {
    int fx = findFather(x);
    int fy = findFather(y);
    if (fx != fy)
        father[fx] = fy;
}
void solve(){
    
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