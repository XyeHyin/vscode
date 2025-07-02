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
    string s;
    cin >> s;
    int n;
    cin >> n;
    while (n--) {
        int l, r;
        cin >> l >> r;
        string tmp = s.substr(l-1, r - l+1);
        cout << tmp << endl;
        s.erase(l-1, r - l+1);
        string ll, rr;
        cin>>ll >> rr;
        int idx=0;
        while((idx=s.find(ll, idx))!= string::npos) {
            auto it2 = s.find(rr, idx+ll.size());
            if(idx==string::npos) break;
            if(it2!= string::npos&&it2 == idx+ll.size()) {
                s.insert(idx+ll.size(), tmp);
                goto out;
            } else {
                idx += ll.size();
            }
        }
        s+= tmp;
        out:;
    }
    cout << s << endl;
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