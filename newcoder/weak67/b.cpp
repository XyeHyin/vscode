#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int am = (c * b) / d;
        if ((c * b) % d == 0)  am -= 1;
        cout << a - am << " ";
    }
    return 0;
}