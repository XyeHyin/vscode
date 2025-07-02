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
    map<int, vector<pair<int, int>>> dic;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dic[c].PB({a, b});
    }
    priority_queue<int> q;
    for (auto &i : dic) {
        vector<PII> a = i.second;
        sort(a.begin(), a.end());
        dic[i.first] = a;
        q.push(i.first);
    }
    int x, y;
    cin >> x >> y;
    while (!q.empty()) {
        int tp = q.top();
        q.pop();
        if (tp > y)
            continue;
        int l = 0, r = dic[tp].size() - 1;
        int mid;
        while (l < r) {
            mid = l + r + 1 >> 1;
            if (dic[tp][mid].first<x){
                l = mid;
            }else
                r = mid - 1;
        }
        if(dic[tp][l].first<x){
            for (int i = l; i < dic[tp].size();i++){
                  if(x>dic[tp][i].first)
                      x = max(x, dic[tp][i].second);
            }
        }
    }
    cout << x << endl;

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