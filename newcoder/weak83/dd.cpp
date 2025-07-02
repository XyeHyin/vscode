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
    int t=1;
    cin >> t;
    map<string, int> mp;
    int j = 2;
    PII pos = {1,0};
    int fangxiang = 0;
    mp["0,0"] = 1;
    mp["1,0"] = 1;
    // 0=右,1=下,2=左,3=上
    int n=1;
    while (t--) {
        // cin >> n;
        if(n == 1) {
            cout << 0 << " " << 0 << endl;
            n++;
            continue;
        }
        for (int i = j; i < n; i++) {
           if (fangxiang == 0) {
               if(mp.count(to_string(pos.first) + "," + to_string(pos.second-1)) == 0) {
                   fangxiang = 1;
                   pos.second--;
                   mp[to_string(pos.first) + "," + to_string(pos.second)] = 1;
               } else {
                   pos.first++;
                   mp[to_string(pos.first) + "," + to_string(pos.second)] = 1;
               }
           } else if (fangxiang == 1) {
             if(mp.count(to_string(pos.first-1) + "," + to_string(pos.second)) == 0) {
                 fangxiang = 2;
                   pos.first--;
                   mp[to_string(pos.first) + "," + to_string(pos.second)] = 1;
               } else {
                   pos.second--;
                   mp[to_string(pos.first) + "," + to_string(pos.second)] = 1;
               }
           } else if (fangxiang == 2) {
                if(mp.count(to_string(pos.first) + "," + to_string(pos.second + 1)) == 0) {
                     fangxiang = 3;
                     pos.second++;
                     mp[to_string(pos.first) + "," + to_string(pos.second)] = 1;
                } else {
                     pos.first--;
                     mp[to_string(pos.first) + "," + to_string(pos.second)] = 1;
                }
           } else if (fangxiang == 3) {
                if(mp.count(to_string(pos.first + 1) + "," + to_string(pos.second)) == 0) {
                     fangxiang = 0;
                     pos.first++;
                     mp[to_string(pos.first) + "," + to_string(pos.second)] = 1;
                } else {
                     pos.second++;
                     mp[to_string(pos.first) + "," + to_string(pos.second)] = 1;
                }
           }
        }
        cout << pos.first << " " << pos.second << endl;
        j = n;
        n++;
    }
    
    return;
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