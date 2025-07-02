#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != -999) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << n / 2 << " " << 0 << endl;
        return 0;
    }

    // 处理最大寒潮次数
    vector<int> b = a;
    for (int i = 0; i < n; i++) {
        if (b[i] == -999) {
            if (i == 0) {
                b[i] = 50;
            } else {
                b[i] = b[i - 1] - x;
            }
        }
    }
    int ansa = 0;
    for (int i = 1; i < n; i++) {
        if (b[i - 1] - b[i] >= x)
            ansa++;
    }

    // 处理最小寒潮次数
    vector<int> c = a;
    for (int i = 0; i < n; i++) {
        if (c[i] == -999) {
            if (i == 0) {
                c[i] = 50;
            } else {
                c[i] = c[i - 1];
            }
        }
    }
    int ansb = 0;
    for (int i = 1; i < n; i++) {
        if (c[i - 1] - c[i] >= x)
            ansb++;
    }

    cout << ansa << " " << ansb << endl;
    return 0;
}