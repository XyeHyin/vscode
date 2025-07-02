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
set<string> ans;
void calc(string s){
    int anss = -1;
    string tmp = "";
    bool flag = false;
    char c;
    //cout << s << endl;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (!flag) {
            if (s[i] == ' ') {
                continue;
            }
            if (ispunct(s[i])) {
                flag = true;
                c = s[i];
                anss = stoi(tmp);
                tmp = "";
                continue;
            }
            tmp += s[i];
            continue;
        }
        if (isdigit(s[i])) {
            tmp += s[i];
        } else if (s[i] == ' ') {
            continue;
        } else {
            if (c == '-') {
                anss -= stoll(tmp);
                tmp = "";
                c = s[i];
            } else if (c == '+') {
                anss += stoll(tmp);
                tmp = "";
                c = s[i];
            }
        }
    }
    if (tmp != "") {
        if (c == '-') {
            anss -= stoll(tmp);
        } else if (c == '+') {
            anss += stoll(tmp);
        }
    }
    // cout<<"s:"<<s<<endl;
    // cout<<"anss:"<<anss<<endl;
    if (anss == 0) {
        ans.insert(s);
    }
}
void dfs(string s, int step) {
    if (step == 0) {
        calc(s);
        return;
    }
    auto it = find(s.begin(), s.end(), '^');
    if (it == s.end()) {
        return;
    }
    s[it - s.begin()] = '+';
        // dbg(s);
        dfs(s, step - 1);
        s[it - s.begin()] = '-';
        // dbg(s);
        dfs(s, step - 1);
        s[it - s.begin()] = ' ';
        // dbg(s);
        dfs(s, step - 1);
    
    return;
}
void solve() {
    int n;
    cin >> n;
    string dic = "";
    for (int i = 1; i < n; i++) {
        dic += i + '0';
        dic += "^";
    }
    dic += n + '0';
    dfs(dic, n - 1);
    for (auto i : ans) {
        cout << i << endl;
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