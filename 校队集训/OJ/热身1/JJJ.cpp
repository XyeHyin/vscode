#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

void solve() {
    long long n, t;
    cin >> n;
    long long ans1 = 0, ans2 = 0;
    bool lst = true;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        if (t == 0)
            continue;
        ans1 += abs(t);
        if (lst and t < 0) {
            ans2++;
            lst = false;
        }
        if (t > 0)
            lst = true;
    }
    cout << ans1 << " " << ans2 << endl;
}
int main() {
    solve();
    return 0;
}