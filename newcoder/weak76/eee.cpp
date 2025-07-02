#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define PII pair<int, int>
#define dbg(x) std::cout << #x << ":" << x << " "
#define MP make_pair
#define PB push_back
#define rep(i,x,n) for(int i=x;i<=n;i++)
#define dep(i,x,n) for(int i=x;i>=n;i--)
#define arrout(a,n) rep(i,1,n)std::cout<<a[i]
#define arrin(a,n) rep(i,1,n)std::cin>>a[i]
#define endl '\n'
long long fastPow(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {
            if(result*base<result) return LLONG_MAX;
            result = (result * base);
        }
        if(base*base<base) return LLONG_MAX;
        base = (base * base);
        power >>= 1;
    }
    return result;
}
void solve(){
    int n, k;
    cin >> n >> k;
    if(n<=k){
        cout << 1 << endl;
        return;
    }
    if (k == 1) {
        cout << n << endl;
        return;
    }
    int l = 1, r = n, ans = 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int p=fastPow(mid, k);
        if(p==LLONG_MAX){
            p=n+1;
            continue;
        }
        if (p == n) {
            ans = mid;
            break;
        } else if (p < n) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (llabs(n - fastPow(ans + 1, k)) < llabs(n - fastPow(ans, k))) ans++;
    cout << ans << endl;
    return;
    }

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)	solve();
    return 0;
}