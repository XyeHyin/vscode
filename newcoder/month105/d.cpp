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
const int maxn = 2e5 + 10;
int father[maxn];
int find(int x) { return father[x] == x ? x : father[x] = find(father[x]); }
void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        father[fx] = fy;
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    arrin(a, n);
    rep(i, 1, n) father[i] = i;
    rep(i, 1, m) {
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }
    unordered_map<int, unordered_map<int, int>> mp;
    rep(i, 1, n) {
        int tmp = find(i);
        mp[tmp][a[i]]++;
    }
    int ans = 0;
    for (auto p : mp) {
        int tmp1 = 0, tmp2 = 0;
        for (auto q : p.second) {
            tmp1 = max(tmp1, q.second);
            tmp2 += q.second;
        }
        ans += tmp2 - tmp1;
    }
    cout << ans << endl;
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