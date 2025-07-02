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
const int maxN = 100005;
int father[maxN];
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
    int n;
    cin >> n;
    if(n<=4) {
        cout << "No" << endl;
        return;
    }
    int mp[n+1]={0};
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        mp[x]++;
        mp[y]++;
    }
    bool ok = 0;
    for(int i = 1; i <= n; i++){
        if(mp[i] == n-1){
            ok = 1;
            break;
        }
    }
    if(ok){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
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