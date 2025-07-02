#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 1e9 + 7;
vector<int> Decimalto(int n, int base) {
    vector<int> res;
    while (n) {
        res.push_back(n % base);
        n /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    int m = a.size();
    vector<vector<int>> num(m);
    int maxx = 0;
    for (int i = 0; i < m; i++) {
        num[i] = Decimalto(a[i], k);
        maxx = max(maxx, (int)num[i].size());
    }
    for (int i = 0; i < m; i++) {
        num[i].insert(num[i].begin(), maxx - num[i].size(), 0);
    }
    vector<int> tmp(maxx, 1);
    for (int i = 1; i < maxx; i++)
        tmp[i] = tmp[i - 1] * k % mod;
    int anss = 0;
    for (int i = 0; i < maxx; i++) {
        int sum = 0;
        for (int j = i+1; j < m; j++) {
            sum = (sum + num[j][i]) % k;
        }
        anss = (anss + sum * tmp[maxx - i - 1]) % mod;
    }
    cout << anss << endl;
    return 0;
}