#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
struct gold {
    int m, v;
    double vv;
};
bool cmp(gold a, gold b) { return a.vv > b.vv; }
int main() {
    int n, m;
    cin >> n >> m;
    vector<gold> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i].m >> g[i].v;
        g[i].vv = (double)g[i].v / g[i].m;
    }
    double ans = 0.0;
    sort(all(g), cmp);
    for (int i = 0; i < n; i++) {
        if (m >= g[i].m) {
            m -= g[i].m;
            ans += g[i].v;
        } else {
            ans += g[i].vv * m;
            break;
        }
    }
    printf("%.2f", ans);
    return 0;
}