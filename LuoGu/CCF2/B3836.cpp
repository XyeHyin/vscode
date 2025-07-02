#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y, z, n, m;
    cin >> x >> y >> z >> n >> m;

    int cnt = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            double ans = x * i * 1.0 + y * j * 1.0 + ((m - i - j) * 1.0 / z);
            if (ans == n * 1.0 && i + j <= m ) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}