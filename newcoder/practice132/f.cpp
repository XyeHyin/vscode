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
    vector<int> bian(3);
    for (int i = 0; i < 3; i++) cin >> bian[i];
    int ans = -1;
    for (int da = -100; da <= 100; da++) {
        int a = bian[0] + da;
        if (a <= 0) continue;
        for (int db = -100; db <= 100; db++) {
            int b = bian[1] + db;
            if (b <= 0)
                continue;
            for (int dc = -100; dc <= 100; dc++) {
                int c = bian[2] + dc;
                if (c <= 0)
                    continue;
                vector<int> s = {a, b, c};
                sort(s.begin(), s.end());
                if (s[0] * s[0] + s[1] * s[1] == s[2] * s[2]) {
                    int cost = abs(da) + abs(db) + abs(dc);
                    if (ans == -1 || cost < ans) {
                        ans = cost;
                    }
                }
            }
        }
    }
    cout << ans << endl;
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