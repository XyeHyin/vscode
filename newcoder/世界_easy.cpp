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
    string ans = "";
    stack<char> st;
    queue<string> kuohao;
    stack<char> stt;
    for (int i = 0; i < n; i++) {
        if (isalpha(s[i]))
            ans += s[i];
        else if (s[i] == '+') {
            if (!st.empty()) {
                char c = st.top();
                st.pop();
                ans += c;
            } else {
                NULL;
            }

        } else if (s[i] == '-') {
            if (ans.empty()) {
                NULL;
            } else {
                char c = ans.back();
                ans.pop_back();
                st.push(c);
            }
        }
    }
    while (!st.empty()) {
        char c = st.top();
        st.pop();
        ans += c;
    }
    cout << ans << endl;
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