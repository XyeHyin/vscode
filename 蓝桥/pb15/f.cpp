#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e5 + 5;
int n, m;
int L, R;
int father[MAXN];
int sz[MAXN];
struct XyeHyin {
    int u, v;
    int w;
};
int findFather(int x) {
    return father[x] = (x == father[x] ? x : findFather(father[x]));
}
int merge(int x, int y) {
    int fx = findFather(x);
    int fy = findFather(y);
    if (fx != fy) {
        int res = sz[fx] * sz[fy];
        father[fy] = fx;
        sz[fx] += sz[fy];
        return res;
    }
    return 0;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> L >> R;
    vector<XyeHyin> a(m);
    set<int> se;
    map<int, vector<XyeHyin>> mp;
    for (int i = 0; i < m; i++) {
        cin >> a[i].u >> a[i].v >> a[i].w;
        mp[a[i].w].push_back(a[i]);
        se.insert(a[i].w);
    }
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        sz[i] = 1;
    }
    map<int, int> cnt;
    for (int w : se) {
        int tmp = 0;
        for (auto i : mp[w]) {
            tmp += merge(i.u, i.v);
        }
        cnt[w] = tmp;
    }
    int ans = 0;
    for (int w = L; w <= R; w++) {
        if (cnt.count(w))
            ans += cnt[w];
    }
    cout << ans << endl;
    return 0;
}