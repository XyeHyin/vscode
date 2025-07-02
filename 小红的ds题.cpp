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
    int tmp = 1;
    deque<int> cen;
    deque<int> cen2;
    cen.push_back(1);
    cout << 1 << endl;
    int one;
    cin >> one;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++) {
            tmp++;
            cen2.push_back(tmp);
        }
        deque<int> tmp2 = cen2;
        for (int j = 0; j < cen.size(); j++) {
            if (cen2.empty()) {
                cout << -1 << " ";
            } else {
                cout << cen2.front() << " ";
                cen2.pop_front();
            }
            if (cen2.empty()) {
                cout << -1 << endl;
            } else {
                cout << cen2.front() << endl;
                cen2.pop_front();
            }
        }
        cen = tmp2;
    }
    for(int i = 0; i < cen.size(); i++) {
        cout << -1<<" "<<-1<<endl;
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