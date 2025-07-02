#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
signed main() {
    int x, y;
    cin >> x >> y;
    vector<int> d;
    for (int a = 1; a <= 10; a++) {
        d.push_back(a);
        d.push_back(-a);
    }
    for (int a = 1; a <= 5; a++) {
        for (int b = 1; b <= 5; b++) {
            d.push_back(a + b);
            d.push_back(a - b);
            d.push_back(-a + b);
            d.push_back(-a - b);
        }
    }
    vector<int> a(2001, 0);
    a[1000] = 1;
    y++;
    while(y--) {
        vector<int> tmp(2001, 0);
        for (int i = 0; i <= 2000; i++) {
            if (a[i]) {
                for(int j = 0;j < d.size(); j++){
                    int n = i + d[j];
                    if (n >= 0 && n <= 2000) {
                        tmp[n] = (tmp[n] + a[i]) % MOD;
                    }
                }
            }
        }
        a = tmp;
    }
    cout << a[x + 1000] % MOD;
}