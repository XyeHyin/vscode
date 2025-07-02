#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;
    cin >> n >> s;
    if (n < 2) {
        cout << 0;
        return 0;
    }

    // Manacher for "anti-palindrome" even centers
    vector<int> d2(n, 0);
    for (int i = 0, l = 0, r = -1; i < n; ++i) {
        int k = (i > r ? 0 : min(d2[l + r - i + 1], r - i + 1));
        while (i - k >= 0 && i + k + 1 < n && s[i - k] != s[i + k + 1]) {
            ++k;
        }
        d2[i] = k;
        if (i + k - 1 > r) {
            l = i - k + 1;
            r = i + k - 1;
        }
    }

    // f[i]: length of longest valid parentheses ending at i
    vector<int> f(n, 0);
    for (int i = 0; i < n; ++i) {
        if (s[i] == ')' && i - 1 >= 0) {
            int prev = f[i - 1];
            int j = i - prev - 1;
            if (j >= 0 && s[j] == '(') {
                f[i] = prev + 2;
                if (j - 1 >= 0)
                    f[i] += f[j - 1];
            }
        }
    }

    long long ans = 0;
    // enumerate all valid parentheses substrings by jumping via f
    for (int r = 0; r < n; ++r) {
        int cur = r;
        while (cur >= 0 && f[cur] > 0) {
            int len = f[cur];
            int l = cur - len + 1;
            int half = len / 2;
            int p = (l + cur) / 2;
            if (d2[p] >= half) {
                ans++;
            }
            cur = l - 1;
        }
    }

    cout << ans;
    return 0;
}