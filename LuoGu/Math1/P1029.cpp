#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    while (b ^= a ^= b ^= a %= b);
    return a;
}
int main() {
    int x, y;
    cin >> x >> y;
    if (y % x != 0) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    int z = y / x;
    for (int i = 1; i * i <= z; ++i) {
        if (z % i == 0) {
            int a = i, b = z / i;
            if (gcd(a, b) == 1) {
                ans += (a == b) ? 1 : 2;
            }
        }
    }

    cout << ans << endl;
    return 0;
}