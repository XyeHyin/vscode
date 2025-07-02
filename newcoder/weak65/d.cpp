#include <bits/stdc++.h>
using namespace std;
#define int long long
int toDecimal(string s) {
    int num = 0;
    for (char c : s) {
        num = (num << 1) | (c - '0');
    }
    return num;
}
signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i] = toDecimal(s);
    }
    int k;
    cin >> k;
    vector<int> b(k);
    int tot = 0;
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        b[i] = toDecimal(s);
        tot |= b[i];
    }
    for (int i = 0; i < n; i++) {
        if(a[i] == 0) {
            cout << 0 << endl;
            continue;
        }
        if ((a[i] | tot) != tot) {
            cout << -1 << endl;
            continue;
        }
        int minn = LLONG_MAX;
        for (int l = 1; l < (1 << k); l++) {
            int tmp = 0;
            int cnt = 0;
            for (int j = 0; j < k; j++) {
                if (l & (1 << j)) {
                    tmp |= b[j];
                    cnt++;
                }
            }
            if ((a[i] | tmp) == tmp) {
                minn = min(minn, cnt);
            }
        }
        cout << minn << endl;
    }
    return 0;
}