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
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        if (s[i] == s[(i + 1)]) {
            cout << 0 << endl;
            return;
        }
        mp[s[i]].PB(i);
    }
    int ans = n + 1;
    for (auto p : mp) {
        for (int i = 0; i < p.second.size(); i++) {
            int d =(p.second[(i + 1) % p.second.size()] - p.second[i] - 1 + n) % n;
            ans = min(ans, d);
        }
    }
    if (ans >= n - 1)  cout << -1 << endl;
    else  cout << ans << endl;
    
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