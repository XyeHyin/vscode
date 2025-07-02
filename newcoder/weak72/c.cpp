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
    int a, b, k;
    cin >> a >> b >> k;
    string s = "";
    if (k == 0 && (a && b)) {
        cout << -1 << endl;
        return;
    }
    if (k > a + b) {
        cout << -1 << endl;
        return;
    }
    int op = b > a;
    if (!op) {
        for (int i = 0; i <= k; i++) {
            if (!(i & 1)) {
                s += '0';
                a--;
            } else {
                s += '1';
                b--;
            }
        }
    } else {
        for (int i = 0; i <= k; i++) {
            if (i & 1) {
                s += '0';
                a--;
            } else {
                s += '1';
                b--;
            }
        }
    }
    if (a < 0 || b < 0) {
        cout << -1 << endl;
        return;
    }
    if(k==1){
        if(s=="01"){cout<<string(a,'0')+"01"+string(b,'1')<<endl;return;}
        else if(s=="10"){cout<<string(a,'1')+"10"+string(b,'0')<<endl;return;}
    }
    if (a) {
        for (int i = 0; i < a; i++) {
                s = s.substr(0, 1) + '0' + s.substr(1);
        }
    }
    if (b) {
        for (int i = 0; i < b; i++) {
                s = s.substr(0, s.size() - 1) + "10";
        }
    }
    cout << s << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    // while (t--)
    //     for (int i = 1;i<=10;i++){
    //         for(int j = 1;j<=10;j++){
    //             for(int k = 1;k<=10;k++){
    //                 cout << i << " " << j << " " << k << ":";
    //                 solve(i,j,k);
    //                 cout << endl;
    //             }
    //         }
    //     }
    while (t--) {
        solve();
    }
    return 0;
}