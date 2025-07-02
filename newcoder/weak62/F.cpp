#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int main() {
    int n = read(), q = read();
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
        priority_queue<int> small;
        priority_queue<int, vector<int>, greater<int>> big;
    while (q--) {
        int l = read(), r = read();
        for (int i = l; i <= r; i++) {
            if (small.empty() || a[i] <= small.top()) {
                small.push(a[i]);
            } else {
                big.push(a[i]);
            }

            if (small.size() > big.size() + 1) {
                big.push(small.top());
                small.pop();
            } else if (big.size() > small.size()) {
                small.push(big.top());
                big.pop();
            }

            if ((i + 1) % 2 == 1) {
                cout << small.top() << endl;
            }
        }
    }

    return 0;
}