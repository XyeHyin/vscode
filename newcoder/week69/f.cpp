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
    int n, q;
    cin >> n >> q;
    string s, ss;
    cin >> s >> ss;
    while (q--) {
        string s1 = '0' + s, s2 = '0' + ss;
        int x;
        cin >> x;
        swap(s1[x], s2[x]);
        vector<vector<int>> dp1(n + 1, vector<int>(3, 0));
        for (int i = 1; i <= n; i++) {
            dp1[i][0] = dp1[i - 1][0] + (s1[i] == 'r');
            dp1[i][1] = dp1[i - 1][1] + (s1[i] == 'e' ? dp1[i - 1][0] : 0);
            dp1[i][2] = dp1[i - 1][2] + (s1[i] == 'd' ? dp1[i - 1][1] : 0);
        }
        int cnt1 = dp1[n][2];
        vector<vector<int>> dp2(n + 1, vector<int>(3, 0));
        for (int i = 1; i <= n; i++) {
            dp2[i][0] = dp2[i - 1][0] + (s2[i] == 'r');
            dp2[i][1] = dp2[i - 1][1] + (s2[i] == 'e' ? dp2[i - 1][0] : 0);
            dp2[i][2] = dp2[i - 1][2] + (s2[i] == 'd' ? dp2[i - 1][1] : 0);
        }
        int cnt2 = dp2[n][2];
        cout << cnt1 - cnt2 << endl;
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