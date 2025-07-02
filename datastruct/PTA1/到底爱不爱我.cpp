#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
vector<int> b;
int j;
bool dfs(int i, string s) {
    if (i == 0) {
        j++;
        return s[j] == '1';
    }
    if (b[i] == 1) return dfs(a[0][i], s) & dfs(a[1][i], s);
    else if (b[i] == 2) return dfs(a[0][i], s) | dfs(a[1][i], s);
    else if (b[i] == 3) return !dfs(a[0][i], s);
    return 0;
}
int main() {
    int n;
    cin >> n;
    a.resize(2, vector<int>(n + 1));
    b.resize(n + 1);
    vector<bool> flag(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;
        if (op == 1 || op == 2) {
            int l, r;
            cin >> l >> r;
            b[i + 1] = op;
            a[0][i + 1] = l;
            a[1][i + 1] = r;
            flag[l] = 1;
            flag[r] = 1;
        } else if (op == 3) {
            int x;
            cin >> x;
            b[i + 1] = op;
            a[0][i + 1] = x;
            flag[x] = 1;
        }
    }
    int ini;
    auto it = find(flag.begin(), flag.end(), 0);
    if (it != flag.end()) ini = distance(flag.begin(), it);
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        j = -1;
        if (dfs(ini, s)) cout << "Ai" << endl;
        else cout << "BuAi" << endl;
    }
    return 0;
}