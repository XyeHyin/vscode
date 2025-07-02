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
    int n;
    cin >> n;
    int num = 1;
    vector<int> a(n + 5);
    for (int i = 1; i <= n;i+=3){
        a[i] = num;
        a[i + 1] = num + 1;
        a[i + 2] = num;
        num += 2;
    }
    cout<<*max_element(a.begin(), a.begin() + n+1)<<endl;
    for (int i = 1; i <= n;i++){
        cout << a[i] << " ";
    }
        return;
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