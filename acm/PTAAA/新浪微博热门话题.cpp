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
    getchar();
    map<string, int> mp;
    while (n--) {
        string s;
        getline(cin, s);
        if (s.size() > 40)
            s = s.substr(0, 40);
        int i = 0;
        set<string> st;
        while (s.find('#', i) != string::npos) {
            int j = s.find('#', i);
            int k = s.find('#', j + 1);
            if (k == string::npos) break;
            string tmp = s.substr(j + 1, k - j - 1);
            string ans = "";
            for (int i = 0; i < tmp.size(); i++) {
                if (isupper(tmp[i]))
                    ans += tolower(tmp[i]);
                else if (isalnum(tmp[i]))
                    ans += tmp[i];
                else if (!ans.empty() && ans.back() != ' ')
                    ans += " ";
            }
            if (!ans.empty())
                ans[0] = toupper(ans[0]);
            if (ans.back() == ' ')
                ans.pop_back();
            st.insert(ans);
            i = k + 1;
        }
        for (auto i : st) {
            mp[i]++;
        }
    }
    vector<pair<string, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    });
    cout << v[0].first << endl << v[0].second << endl;
    int cnt = 0;
    for (auto it = v.begin() + 1; it != v.end(); it++) {
        if (it->second == v[0].second) {
            cnt++;
        }
    }
    if (cnt)
        cout << "And " << cnt << " more ..." << endl;
    return;
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}