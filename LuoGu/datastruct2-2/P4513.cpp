#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1000010;
int a[maxn], w[maxn * 4], lzy[maxn * 4];
struct Node {
    int sum, val, lv, rv;
};
Node t[maxn << 1];
void pushup(const int u) {
    int ls = u * 2, rs = u * 2 + 1;
    t[u].sum = t[ls].sum + t[rs].sum;
    t[u].val = max({t[ls].val, t[rs].val, t[ls].rv + t[rs].lv});
    t[u].lv = max(t[ls].lv, t[ls].sum + t[rs].lv);
    t[u].rv = max(t[rs].rv, t[rs].sum + t[ls].rv);
}
void build(const int u, int L, int R) {
    if (L == R) {
        t[u].sum = t[u].val = t[u].lv = t[u].rv = a[L];
        return;
    }
    int M = (L + R) / 2;
    build(u * 2, L, M);
    build(u * 2 + 1, M + 1, R);
    pushup(u);
}
void update(int u, int L, int R, int pos, int val) {
    if (L == R) {
        t[u].sum = t[u].val = t[u].lv = t[u].rv = val;
        return;
    }
    int M = (L + R) / 2;
    if (pos <= M)
        update(u * 2, L, M, pos, val);
    else
        update(u * 2 + 1, M + 1, R, pos, val);
    pushup(u);
}
Node query(int u, int L, int R, int l, int r) {
    if (l <= L && R <= r) return t[u];
    int M = (L + R) / 2;
    if (r <= M) return query(u * 2, L, M, l, r);
    if (l > M) return query(u * 2 + 1, M + 1, R, l, r);
    Node left = query(u * 2, L, M, l, r);
    Node right = query(u * 2 + 1, M + 1, R, l, r);
    Node res;
    res.sum = left.sum + right.sum;
    res.val = max({left.val, right.val, left.rv + right.lv});
    res.lv = max(left.lv, left.sum + right.lv);
    res.rv = max(right.rv, right.sum + left.rv);
    return res;
}
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    for (int t = 1; t <= m; t++) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) {
            if (a > b) swap(a, b);
            Node res = query(1, 1, n, a, b);
            cout << res.val << endl;
        } else if (op == 2) {
            update(1, 1, n, a, b);
        }
    }
    return 0;
}