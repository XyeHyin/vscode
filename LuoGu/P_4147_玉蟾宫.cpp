#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, _;
    cin >> n >> _;
    int ans = 0;
    vector<int> a(n + 1);
    while (_--) {
        for (int i = 1; i <= n; i++) {
            char ch;
            cin >> ch;
            ch == 'F' ? a[i]++ : a[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int minn = 0x3f3f3f3f;
            for (int j = i; j <= n; j++) {
                if (!a[j])
                    break;
                ans += minn = min(minn, a[j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}