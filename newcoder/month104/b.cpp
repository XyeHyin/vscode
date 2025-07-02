#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    double n, r, sr, ssr, ur;
    cin >> n >> r >> sr >> ssr >> ur;
    double p = ssr + ur;
    double ans = 1.0 - pow(1.0 - p, 10) - 10.0 * p * pow(1.0 - p, 9);
    printf("%.10f\n", ans);
    return 0;
}