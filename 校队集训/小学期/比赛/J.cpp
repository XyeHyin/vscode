#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> a(n + 1);
    vector<int> b(m + 1);
    int suma = 0, sumb = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        suma += a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        sumb += b[i];
    }

    cout << (((sumb* suma)%1000000007)* c) %1000000007;

    return 0;
}