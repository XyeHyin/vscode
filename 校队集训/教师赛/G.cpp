#include <bits/stdc++.h>
using namespace std;
const int maxN = 100005;
int father[maxN], ans[maxN];
int maxx = -1;

int findFather(int x) {
    return x == father[x] ? x : father[x] = findFather(father[x]);
}

void merge(int x, int y) {
    int fx = findFather(x);
    int fy = findFather(y);
    if (fx != fy) {
        father[fx] = fy;
        ans[fy] = max(ans[fy], ans[fx] + 1);
        maxx = max(maxx, ans[fy]);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        ans[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        merge(i, x);
    }
    cout << maxx << endl;

    return 0;
}