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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    n = read();
    vector<int> a(n);
    vector<int> b(1000000, 0);
    for (int i = 0; i < n; i++) {
        a[i]=read();
    }
    for (int i = 0; i < n; i++) {
        b[a[i]]++;
        if (b[a[i]] > 1) {
          b[a[i]]--;
          auto it = find(b.begin()+a[i], b.end(), 0);
          *it = 1;
            a[i] = it - b.begin();
        }
        cout << a[i] << " ";
    }
    return 0;
}