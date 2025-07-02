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
int toDecimal(vector<int> num, int base) {
    int res = 0;
    for (int i = 0; i < num.size(); i++) {
        res = (res * base + num[i])%mod;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> num(a.size());
    int maxx = 0;
    for (int i = 0; i < a.size(); i++) {
        num[i] = Decimalto(a[i], k);
        maxx = max(maxx, (int)num[i].size());
    }
    for (int i = 0; i < a.size(); i++) {
        num[i].insert(num[i].begin(), maxx - num[i].size(), 0);
    }
    int ans = 0;
    for (int i = 0; i < maxx; i++) {
        int sum = 0;
        for (int j = 0; j < a.size(); j++) {
            sum = (sum + num[j][i]*(n*(n-1)/2))%k;
        }
        ans = (ans + (sum)*(int)pow(k, maxx - i - 1))%mod;
    }
    cout<<(ans)%mod<<endl;
    return 0;
}