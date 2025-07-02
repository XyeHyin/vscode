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
    // vector<int> dic = {1, 2, 3, 4, 5};
    // for (int a = 0; a <= 10; a++) {
    //     for (int b = 0; b <= 10; b++) {
    //         for (int c = 0; c <= 10; c++) {
    //             for (int d = 0; d <= 10; d++) {
    //                 for (int e = 0; e <= 10; e++) {
    //                     for (int f = 0; f <= 10; f++) {
    //                         vector<int> tmp;
    //                         tmp.push_back(a ^ b^ c);
    //                         tmp.push_back(d ^ e^ f);
    //                         tmp.push_back(a ^ d);
    //                         tmp.push_back(b ^ e);
    //                         tmp.push_back(c ^ f);
    //                         sort(tmp.begin(), tmp.end());
    //                         if(tmp==dic){
    //                             cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
    //                             return;
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    int n, m;
    cin >> n >> m;
    bool okn = n&1, okm = m&1;
    if(okn+okm==0||okn+okm==2){
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i < n;i++){
        cout << i << " ";
        for(int j =1;j<m;j++){
            cout << 0 ;
            if(j!=m-1) cout << " ";
            else cout << endl;
        }
    }
    for (int i = n + m; i>n;i--){
        cout << i << " ";
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