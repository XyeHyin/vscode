#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    if (m < n / 2) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> a(n);
    int tmp = m;
    int k = (m - n / 2) / n;
    if (n & 1) {
        if ((m % k) & 1)
            k--;
        if (!((m - n / 2) & 1)) {
            for (int i = 0; i < n; i++) {
                if (i & 1) {
                    a[i] = 0 + k;
                    tmp -= k;
                } else {
                    a[i] = 1 + k;
                    tmp -= k + 1;
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (i & 1) {
                    a[i] = 1 + k;
                    tmp -= k + 1;
                } else {
                    a[i] = 0 + k;
                    tmp -= k;
                }
            }
        }
        while (tmp) {
            auto it = distance(a.begin(), min_element(a.begin(), a.end()));
            a[it] += 2;
            tmp -= 2;
        }

    } else {
        if ((m - n / 2) & 1) {
            cout << -1 << endl;
            return 0;
        } else {
            for (int i = 0; i < n; i++) {
                if (i & 1) {
                    a[i] = 1 + k;
                    m -= k + 1;
                } else {
                    a[i] = 0 + k;
                    m -= k;
                }
            }
            while (m) {
                auto it = distance(a.begin(), min_element(a.begin(), a.end()));
                a[it] += 2;
                m -= 2;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}