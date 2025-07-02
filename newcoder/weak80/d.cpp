#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define PII pair<int, int>
#define dbg(x) std::cout << #x << ":" << x << " "
#define MP make_pair
#define PB push_back
#define rep(i, x, n) for (int i = x; i <= n; i++)
#define dep(i, x, n) for (int i = x; i >= n; i--)
#define arrout(a, n) rep(i, 1, n) std::cout << a[i]
#define arrin(a, n) rep(i, 1, n) std::cin >> a[i]
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + (s[i] == '1' ? 1 : -1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for(int j=i+1;j<n;j++){
            int sum = 0;
            bool OK = 1;
            for (int k = 0; k < n; k++) {
                if(k==i&&s[k]=='0') sum+=2;
                if(k==j&&s[k]=='0') sum+=2;
                sum+=pre[k];
                if(sum<0){
                    OK = 0;
                    break;
                }
            }
            if(OK){
                ans++;
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}