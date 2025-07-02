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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    map<int, int> mp;
    unordered_map<int, int> cnt; 
    auto add = [&](int x) {
        if (cnt[x]++ > 0) return;
        bool L = cnt[x - 1] > 0, R = cnt[x + 1] > 0;
        if (L && R) {
            auto itl = prev(mp.upper_bound(x));
            auto itr = mp.upper_bound(x);
            int l = itl->first;
            int r = itr->second;
            mp.erase(itl);
            mp.erase(itr);
            mp[l] = r;
        } else if (L) {
            auto itl = prev(mp.upper_bound(x));
            itl->second++;
        } else if (R) {
            auto itr = mp.upper_bound(x);
            int r = itr->second;
            mp.erase(itr);
            mp[x] = r;
        } else {
            mp[x] = x;
        }
    };
    auto remove = [&](int x) {
        if (--cnt[x] > 0)
            return;
        auto it = prev(mp.upper_bound(x));
        int l = it->first, r = it->second;
        mp.erase(it);
        if (l < x)
            mp[l] = x - 1;
        if (x < r)
            mp[x + 1] = r;
    };
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(a[i]);
    }

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            remove(a[x]);
            a[x] = y;
            add(y);
        } else {
            int x;
            cin >> x;
            auto it = mp.upper_bound(x);
            if (it != mp.begin()) {
                auto itl = prev(it);
                if (itl->first <= x && x <= itl->second) {
                    cout << itl->second + 1 << endl;
                    continue;
                }
            }
            cout << x << endl;
        }
    }
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