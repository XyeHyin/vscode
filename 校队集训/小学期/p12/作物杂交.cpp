#include <bits/stdc++.h>
using namespace std;
const int N = 2020;
int n, m, k, t;
int a[N];
vector<pair<int, int>> g[N];
bool st[N], backup[N];
int d[N];
pair<int, int> p[N];

int main() {
    memset(d, 0x3f3f3f3f, sizeof d);
    cin >> n >> m >> k >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        st[x] = true;
        d[x] = 0;
    }
    for (int i = 0; i < k; i++) {
        int x, y, a;
        cin>>x>>y>>a;
        g[a].push_back(make_pair(x, y));
    }

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < (int)g[i].size(); j++)
            if (st[g[i][j].first] && st[g[i][j].second]) {
                int rd = d[i];
                d[i] = min(d[i], max(a[g[i][j].first], a[g[i][j].second]));
                if (d[i] < rd)
                    p[i] = make_pair(g[i][j].first, g[i][j].second);
            }

    for (int i = 1; i <= n; i++) {
        int minv = 0x3f3f3f3f;
        int v;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && d[j] < minv) {
                v = j;
                minv = d[j];
            }
        }
        st[v] = true;

        for (int j = 1; j <= n; j++)
            for (int l = 0; l < (int)g[j].size(); l++)
                if (!st[j] && st[g[j][l].first] && st[g[j][l].second]) {
                    int rd = d[j];
                    d[j] = min(d[j],
                               max(a[g[j][l].first], a[g[j][l].second]) + d[v]);
                    if (d[j] < rd)
                        p[j] = make_pair(g[j][l].first, g[j][l].second);
                }
    }

    cout << d[t] << endl;

    return 0;
}