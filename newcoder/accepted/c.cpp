#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 100000;
int n, m, q;
vector<int> a, b;
int father[N + 5], rk[N + 5];
int findFather(int x) {
    if (x != father[x]) {
        father[x] = findFather(father[x]);
    }
    return father[x];
}

void merge(int x, int y) {
    int fx = findFather(x);
    int fy = findFather(y);
    if (fx != fy) {
        if (rk[fx] < rk[fy]) {
            father[fx] = fy;
        } else if (rk[fx] > rk[fy]) {
            father[fy] = fx;
        } else {
            father[fy] = fx;
            rk[fx]++;
        }
    }
}

int work(int l, int r, int k) {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        rk[i] = 0;
    }
    for (int i = l; i <= r; i++) {
        merge(a[i], b[i]);
    }
    return findFather(k);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    a.resize(m + 1);
    b.resize(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
    }
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << work(l, r, k) << endl;
    }
    return 0;
}