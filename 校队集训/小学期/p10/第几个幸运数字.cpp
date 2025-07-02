#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int cnt = 0;
    int ans = 59084709587505;
    for (int i = 0; pow(7, i) <= ans; i++) {
        for (int j = 0; pow(5, j) <= ans; j++) {
            for (int k = 0; pow(3, k) <= ans; k++) {

                if (pow(3, k) * pow(5, j) * pow(7, i) < ans)
                    cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}