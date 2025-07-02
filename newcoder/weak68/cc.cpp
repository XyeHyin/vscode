#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    unordered_map<int, int> mp1, mp2;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp1[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        mp2[b[i]]++;
    }
    int tmp1 = 0, tmp2 = 0;
    for(auto it=mp1.begin();it!=mp1.end();it++){
        tmp1+=it->second -1;
    }
    for (auto it = mp2.begin(); it != mp2.end(); it++) {
        tmp2 += it->second - 1;
    }
    set<int> se(a.begin(), a.end());
    set<int> st(b.begin(), b.end());
    int cnt = 0;
    for (auto it = se.begin(); it != se.end(); it++) {
        if (st.count(*it)) cnt++;
    }
    int tmp = tmp2 - tmp1 + cnt;
    int ma = (tmp + 1) / 2;
    int mb = cnt - ma;
    int ans = max(tmp1+ma, tmp2+mb);
    cout << ans << endl;
    return 0;
}