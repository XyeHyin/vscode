#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define PII pair<int, int>
#define dbg(x) std::cout << #x << ":" << x << " "
#define MP make_pair
#define PB push_back
#define rep(i, x, n) for (int i = x; i <= n; i++)
#define dep(i, x, n) for (int i = x; i >= n; i--)
#define arrout(a, n) rep(i, 1, n) std::cout << a[i]
#define arrin(a, n) rep(i, 1, n) std::cin >> a[i]
#define endl '\n'

void solve() {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    auto survive = [&](__int128 x) {
        __int128 removed = 0;
        for (long long round = 0; round < k; round++) {
            __int128 pos = x - removed;
            // pos <= 0 说明前面的都被掏空了，必定安全
            if (pos <= 0)
                return true;
            int j = static_cast<int>(lower_bound(a.begin(), a.end(), (long long)pos) -
                        a.begin());
            if (j < n && a[j] == (long long)pos)
                return false;
            if (j == 0)
                return true;
            removed += j;
        }
        return true;
    };

    __int128 l = 1, r = (__int128)n * k + 1;
    while (l < r) {
        __int128 mid = (l + r) / 2;
        if (survive(mid))
            r = mid;
        else
            l = mid + 1;
    }
    // 输出要 cast 回 long long
    cout << (long long)l << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}