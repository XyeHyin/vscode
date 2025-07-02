#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000000;
int main() {
    int n;
    cin >> n;
    vector<int> count(maxn + 1, 0);
    for (int i = 2; i <= maxn; i++) {
        if (count[i] == 0) {
            for (int j = i; j <= maxn; j += i) {
                count[j]++;
            }
        }
    }
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (count[i] > 1) {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}