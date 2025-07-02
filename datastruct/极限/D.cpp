#include <bits/stdc++.h>
using namespace std;
struct XyeHyin {
    int a, b, aa, bb;
};
int main() {
    int n;
    cin >> n;
    vector<XyeHyin> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].a >> a[i].b >> a[i].aa >> a[i].bb;
    int x, y;
    cin >> x >> y;
    for (int i = n - 1; i >= 0; i--) {
        if (x >= a[i].a && x <= a[i].a + a[i].aa &&y >= a[i].b && y <= a[i].b + a[i].bb) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}