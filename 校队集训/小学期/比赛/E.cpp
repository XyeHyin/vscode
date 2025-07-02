#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        int ans =sqrt(a);
        cout << a-ans << endl;
    }
    return 0;
}