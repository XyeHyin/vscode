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
const int maxN = 100010;
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
    vector<int> a(n);
    for(int i=0;i<n;i++) father[i] = i;
    for(int i=0;i<n;i++) cin >> a[i];
    vector<vector<int>> pos(64);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 64; j++) {
            if (a[i] & (1LL << j)) {
                pos[j].push_back(i);
            }
        }
    }
    for (int b = 0; b < 64; b++) {
        if (pos[b].size() > 1) {
            for (int i = 1; i < pos[b].size(); i++) {
                merge(pos[b][i], pos[b][0]);
            }
        }
    }
    unordered_map<int, int> cnt;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        cnt[findFather(i)]++;
        ans = max(ans, cnt[findFather(i)]);
    }
    cout << ans << endl;
    return;
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