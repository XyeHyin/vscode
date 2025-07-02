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
    int n = 9;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    for(int i=1; i <= n; i++){
        for (int j = 0;j<=10;j++){
            int id=i,k=j;
            if (a[id] < k - a[id] || a[id] > k + a[id]) {
                cout << -1 << endl;
                continue;
            }
            int huo = 0;
            int you = 0;
            for (int i = id; i <= n; i++) {
                huo |= a[i];
                if (huo > k + a[id]) {
                    you = i - 1;
                    break;
                }
                if (i == n) {
                    you = n;
                    break;
                }
            }
            int yu = a[id];
            int zuo = 0;
            for (int i = id; i >= 1; i--) {
                yu &= a[i];
                if (yu < k - a[id]) {
                    zuo = i + 1;
                    // cout<<"OK"<<endl;
                    break;
                }
                if (i == 1) {
                    zuo = 1;
                    break;
                }
            }
            cout << zuo << " " << you << endl;
        }
    }
   
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}