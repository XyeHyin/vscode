#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
bool iswqpf(int n) { return sqrt(n) == (int)sqrt(n); }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = read(), q = read();
    vector<int> a(n + 1);
    vector<int> sum(n + 1, 0);
    vector<int> dic(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        sum[i] = sum[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++) {
        int ans = 0;
        for(int j = i; j <= n; j++) {
            ans+=a[j];
            if(iswqpf(ans)) {
                dic[j+1]--;
                dic[i]++;
            }
        }
    }
    while (q--) {
        int x = read();
        int cnt = 0;
        for (int i = 1; i <= x; i++) {
            for (int j = x; j <= n; j++) {
                int ans = sum[j] - sum[i - 1];
                if (iswqpf(ans)) {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}