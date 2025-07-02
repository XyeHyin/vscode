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
    stack<char> st;
    for (int i = 0;i<s.size();i++) {
        if(st.empty()) {
            st.push(s[i]);
        } else {
            if (st.top() == s[i]) {
                while(!st.empty() && st.top() == s[i]) {
                    st.pop();
                }
            } else {
                st.push(s[i]);
            }
        }
    }
    s = "";
    while(!st.empty()) {
        s = st.top() + s;
        st.pop();
    }
        if (s.size() <= 1) {
            cout << 0 << endl;
            return;
        }
    if (s.size()&1) {
        int aa = 0, bb = 0;
        for (int i = 0; i < s.size()-1; i += 2) {
            if (s[i] != s[i + 1]) aa++;
        }
        for (int i = 1; i  < s.size()-1; i += 2) {
            if (s[i] != s[i + 1]) bb++;
        }
        cout << min(aa, bb) << endl;
    } else {
        int aa = 0;
        for (int i = 0; i < s.size()-1; i += 2) {
            if (s[i] != s[i + 1]) aa++;
        }
        cout << aa << endl;
    }
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}