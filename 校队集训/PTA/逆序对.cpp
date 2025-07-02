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
#define lowbit(x) (x & (-x))
int n;
vector<int> c;
void add(int x, int y) {
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += y;
}
int sum(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += c[i];
    return res;
}
void solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 0; i < n;i++){
        for(int j = i + 1; j < n; j++){
            if (a[i] > a[j]){
                cnt++;
            }
        }
    }
    vector<int> ans;
    for(int i = 0; i < n; i++){
        c.assign(n + 1, 0);
        int res = 0;
        for (int j = i; j < n; j++){
            res+= sum(n) - sum(a[j]);
            add(a[j], 1);
            int len= j - i + 1;
            ans.push_back((len*(len-1)/2)-res*2 + cnt);
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    }
    cout << endl;
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