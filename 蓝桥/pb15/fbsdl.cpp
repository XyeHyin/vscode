#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    vector<int> pos(n, 0);
    vector<vector<int>> a(n);
    string s;
    while (cin >> s) {
        if (s == "add") {
            int num;
            cin >> num;
            a[0].push_back(num);
        } else if (s == "sync") {
            int num;
            cin >> num;
            if (a[num].size() < a[0].size())
            a[num].push_back(a[0][pos[num]]);
            pos[num]++;
        } else {
            int minn = LLONG_MAX;
            for (int i = 0; i < n; i++) {
                minn = min(minn, (int)a[i].size());
            }
            cout << minn << endl;
        }
    }

    return 0;
}