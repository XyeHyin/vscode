#include <bits/stdc++.h>
using namespace std;
vector<int> a, b;
vector<vector<int>> cen;
void build(int l1, int r1, int l2, int r2, int n) {
    if (l1 > r1 || l2 > r2)
        return;
    int root = b[r2];
    int pos = find(a.begin() + l1, a.begin() + r1 + 1, root) - a.begin();
    cen[n].push_back(root);
    build(pos + 1, r1, l2 + pos - l1, r2 - 1, n + 1);
    build(l1, pos - 1, l2, l2 + pos - l1 - 1, n + 1);
}
int main() {
    int n;
    cin >> n;
    a.resize(n);
    b.resize(n);
    cen.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    build(0, n - 1, 0, n - 1, 0);
    cout << "R:";
    for (int i = 0; i < cen.size(); i++) {
        if (!cen[i].empty()) {
            cout << " " << cen[i].front();
        }
    }
    cout << endl << "L:";
    for (int i = 0; i < cen.size(); i++) {
        if (!cen[i].empty()) {
            cout << " " << cen[i].back();
        }
    }
    cout << endl;

    return 0;
}