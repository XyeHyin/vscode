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
struct XyeHyin {
    string school;
    string team;
    int id;
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<XyeHyin> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].school >> a[i].team >> a[i].id;
    }
    int bs;
    cin >> bs;
    unordered_set<string> b;
    for (int i = 0; i < bs; i++) {
        string bb;
        cin >> bb;
        b.insert(bb);
    }
    int cs;
    cin >> cs;
    unordered_set<string> c;
    for (int i = 0; i < cs; i++) {
        string cc;
        cin >> cc;
        c.insert(cc);
    }
    int tmpa = m * 60 / 100;
    int tmpb = m * 30 / 100;
    int tmpc = m * 10 / 100;
    unordered_map<string, int> mp;
    vector<XyeHyin> ansa, ansb, ansc;
    for (int i = 0; i < n; i++) {
        if (mp[a[i].school] >= 3)
            continue;
        if (tmpa > 0) {
            ansa.push_back(a[i]);
            tmpa--;
            mp[a[i].school]++;
        }
        else if (b.count(a[i].school) && tmpb > 0) {
            ansb.push_back(a[i]);
            tmpb--;
            mp[a[i].school]++;
        }
        else if (c.count(a[i].school) && tmpc > 0) {
            ansc.push_back(a[i]);
            tmpc--;
            mp[a[i].school]++;
        }
        if (tmpa + tmpb + tmpc == 0)
            break;
    }
    cout << ansa.size() << endl;
    for (int i = 0; i < ansa.size(); i++) {
         cout << ansa[i].school << " " << ansa[i].team << " " << ansa[i].id << endl;
    }
    cout << ansb.size() << endl;
    for (int i = 0; i < ansb.size(); i++) {
         cout << ansb[i].school << " " << ansb[i].team << " " << ansb[i].id << endl;
    }
    cout << ansc.size() << endl;
    for (int i = 0; i < ansc.size(); i++) {
         cout << ansc[i].school << " " << ansc[i].team << " " << ansc[i].id << endl;
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