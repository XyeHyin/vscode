#include <bits/stdc++.h>
using namespace std;

#define yy cout << "YES\n"
#define no cout << "NO\n"
#define int long long
#define cf cin >> t;
int MOD = 1e9 + 7;
// int dis[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
// int dis[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
struct pos {
    string s;
    int a, b;
};
bool cmp(pos a, pos b) { return a.s < b.s; }
void solve() {
    int t;
    cin >> t;
    vector<pos> f;
    int sum = 0;
    int fi1 = 0;
    int fi2 = 0;
    int fi2_2 = 0;
    int max_lsy = 0, max_hxn = 0;
    for (int i = 0; i < t; ++i) {
        pos now;
        cin >> now.s >> now.a >> now.b;
        sum += now.b;
        f.push_back(now);
    }
    for (int i = 0; i < t; ++i) {
        pos now = f[i];
        int ne = sum - now.b + now.a * 2;
        if (ne > max_lsy) {
            fi1 = i;
            max_lsy = ne;
        }
    }
    for (int i = 0; i < t; ++i) {
        pos now = f[i];
        int ne = sum + now.b;
        int ma = 0;
        int id = 0;
        for (int j = 0; j < t; ++j) {
            if (j == i)
                continue;
            pos now1 = f[j];
            int neee = ne - now1.b + now1.a;
            if (neee > ma) {
                id = j;
                ma = neee;
            }
        }
        ne = ne - f[id].b + f[id].a;
        if (ne > max_hxn) {
            max_hxn = ne;
            fi2_2 = id;
            fi2 = i;
        }
    }
    vector<pos> ans;
    for (int i = 0; i < t; ++i) {
        if (max_lsy >= max_hxn) {
            if (i == fi1)
                continue;
        } else {
            if (i == fi2 || i == fi2_2) {
                continue;
            }
        }
        ans.push_back(f[i]);
    }
    std::sort(ans.begin(), ans.end(), cmp);

    if (max_lsy >= max_hxn) {
        cout << "LSY\n";
        cout << max(max_lsy, max_hxn) << '\n';
        cout << f[fi1].s << '\n';
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i].s << '\n';
        }
    } else {
        cout << "HXN\n";
        cout << max(max_lsy, max_hxn) << '\n';
        cout << f[fi2_2].s << '\n';
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i].s << '\n';
        }
        cout << f[fi2].s << '\n';
    }
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}