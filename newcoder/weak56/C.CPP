#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        if (a == 1) {
            cout << 5 << " " << 4 << endl;
            continue;
        } else if (a == 1000000000) {
            cout << 999999999 << " " << 1024 << endl;
            continue;
        } else {
            cout << (a ^ 1) << " " << 1 << endl;
        }
    }
    return 0;
}