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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, vector<int>> mp;
    for (int i = 0;i<n;i++) mp[__builtin_popcountll(a[i])].push_back(a[i]);
    int name = -1, ans = -1;
    for (auto it=mp.begin(); it!=mp.end(); it++) {
        vector<int> v = it->second;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        if ((int)v.size() > ans) {
            ans = v.size();
            name = it->first;
        }
    }
    auto anss = mp[name];
    cout << ans << endl;
    sort(anss.begin(), anss.end());
    for(int i = 0; i < ans; i++) cout << anss[i] << " ";
    cout << endl;
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