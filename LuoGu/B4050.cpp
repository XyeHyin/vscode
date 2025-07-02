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
bool not_prime[10000001] = {true, true};
vector<int> prime;
void Euler(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!not_prime[i]) {
            prime.push_back(i);
        }
        for (int pri_j : prime) {
            if (i * pri_j > n)
                break;
            not_prime[i * pri_j] = true;
            if (i % pri_j == 0) {
                break;
            }
        }
    }
}
void solve() {
    int n;
    cin >> n;
    if(n==1) {
        cout << 1 << endl;
        return;
    }
    int len=log2(n);
    for (int i = 0;i<=len;i++) {
        int tmp=n-((1<<i)-1);
        auto it=binary_search(prime.begin(),prime.end(),tmp);
        if (it|| tmp==0) {
            cout << i+1 << endl;
            return;
        }
    }
    cout << -1 << endl;
        return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    Euler(100000);
    while (t--)
        solve();
    return 0;
}