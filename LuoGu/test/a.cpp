#include <bits/stdc++.h>
using namespace std;
#define int long long
// int dis[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
// int dis[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
#define yy cout << "YES\n"
#define no cout << "NO\n"

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (m == 1)
            return cout << "YES", 0;
        if (n == 1)
            return cout << "NO", 0;
        if (n % 2 == 0)
            cout << "YES";
        else if(m&1) cout << "YES";
        else  cout << "NO";
    }
    return 0;
}