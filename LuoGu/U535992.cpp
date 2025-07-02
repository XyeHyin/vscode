/* #include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define PII pair<int, int>
#define dbg(x) std::cout << #x << ":" << x << " "
#define MP make_pair
#define PB push_back
#define rep(i, x, n) for (int i = x; i <= n; i++)
#define dep(i, x, n) for (int i = x; i >= n; i--)
#define endl '\n'
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int len = n - k;
    if (len <= 1) {
        cout << 0 << endl;
        return;
    }
    if(n==1){
        cout << a[0] << endl;
        return;
    }
    if(n==2){
        cout << a[1] - a[0] << endl;
        return;
    }
    int l = 0, r = n - 1;
    int ans = a[r] - a[l];
    int zuo = 0, you = 0;
    bool iszuo = true;
    if (a[l + 1] - a[l] <= a[r] - a[r - 1]) {
        iszuo = false;
    }
    while (k>0) {
        if(l >= r) {
            break;
        }
        if (l == r) {
            ans = 0;
            break;
        }
        if (iszuo) {
            if (l + you + 1 >= n || k <= 0) {
                l++;
                ans = min(ans, a[r] - a[l]);
                k--;
                continue;
            }
            if (a[l + you + 1] - a[l] >= a[r] - a[r - 1]) {
                you++;
                l++;
                ans = min(ans, a[r] - a[l]);
                k--;
            } else if (a[l + you + 1] - a[l] < a[r] - a[r - 1]) {
                zuo += you+1;
                k -= you + 1;
                you = 0;
                iszuo = false;
                r--;
                ans = min(ans, a[r] - a[l]);
            }
        } else {
            if(l >= r) {
            break;
        }
        if (l == r) {
            ans = 0;
            break;
        }
            if (r - you - 1 < 0 || k <= 0) {
                r--;
                ans = min(ans, a[r] - a[l]);
                k--;
                continue;
            }
            if (a[l + 1] - a[l] > a[r] - a[r - you - 1]) {
                you += zuo+1;
                k -= zuo + 1;
                zuo = 0;
                iszuo = true;
                l++;
                ans = min(ans, a[r] - a[l]);
            } else if (a[l + 1] - a[l] <= a[r] - a[r - you - 1]) {
                zuo++;
                r--;
                ans = min(ans, a[r] - a[l]);
                k--;
            }
        }
    }
    cout << ans << endl;
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
} */
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int len = n - k;
    if (len <= 1) {
        cout << 0 << endl;
        return;
    }
    if (n == 1) {
        cout << a[0] << endl;
        return;
    }
    if (n == 2) {
        cout << a[1] - a[0] << endl;
        return;
    }
    sort(a.begin(), a.end());
    int ans = LLONG_MAX;
    for (int l = 0; l < n; l++) {
        int r = 0;
        if (k - 2 *l >= l){
            r = k-2*l;
        }else r=(k-l)/2;
        r=min(r, n - 2 - l);
        if(r < 0) continue;
        int rr = n - 1 - r;
        if(rr<=l) continue;
        ans = min(ans, a[rr] - a[l]);
    }
    cout << ans << endl;
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