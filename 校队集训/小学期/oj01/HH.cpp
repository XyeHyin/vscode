#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int a, b;
    cin >> a >> b;
    if (a == 0 || b == 0) {
        cout << 0 << endl;
        return 0;
    } else {
        int cnt = 0;
        for (int x = 0; x < b; x++) {
            for (int y = 1; y <= a; y++) {
                double temp = (-a / (double)b) * y + a;
                if (temp >= x) {
                    cnt++;
                }
            }
        }
        cout << cnt;
    }
    return 0;
}