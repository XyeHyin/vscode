#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int count = 1, ans = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] == 1) {
            count++;
        } else {
            ans = max(ans, count);
            count = 1;
        }
    }
    ans = max(ans, count);
    cout << ans << endl;
    return 0;
}