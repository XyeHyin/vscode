#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)  cin >> a[i];
    int maxx = 0;
    int x1, y1, x2, y2;
    for (int i1 = 0; i1 < n; i1++) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int i2 = i1; i2 < n; i2++) {
                for (int j2 = j1; j2 < m; j2++) {
                    bool flag = 0;
                    for (int i = i1; i <= i2; i++) {
                        for (int j = j1; j <= j2; j++) {
                            if (a[i][j] == '*') {
                                flag = 1;
                                break;
                            }
                        }
                    }
                    if (!flag) {
                        int s = (i2 - i1 + 1) * (j2 - j1 + 1);
                        if (s > maxx) {
                            maxx = s;
                            x1 = i1 + 1;
                            y1 = j1 + 1;
                            x2 = i2 + 1;
                            y2 = j2 + 1;
                        }
                    }
                }
            }
        }
    }
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    return 0;
}