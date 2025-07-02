#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
const int maxN = 200010;
int water[maxN];
int father[maxN];
int big[maxN];
int ne[maxN];
int findFather(int x) {
    return father[x] = (x == father[x] ? x : findFather(father[x]));
}
void merge(int l, int r) {
    int w = findFather(r);
    while (l <= r) {
        int tmp = ne[l];
        father[findFather(l)] = w;
        big[w] += big[findFather(l)];
        ne[l] = ne[r];
        l = tmp;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        big[i] = 1;
        water[i] = read();
        ne[i] = i + 1;
    }
    while (m--) {
        int op;
        op = read();
        if (op == 1) {
            int l = read(), r = read();
            merge(l, r);
        } else {
            int i = read();
            int ans = findFather(i);
            double avg = 1.0 * water[ans] / big[ans];
            printf("%.10lf\n", avg);
        }
    }
}