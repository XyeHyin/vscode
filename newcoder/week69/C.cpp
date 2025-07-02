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
int gcd(int a, int b) {
    while(b^=a^=b^=a%=b);
    return a;
}
struct XyeHyin{
    int x, y, z;
};
void solve() {
    int n, h;
    cin >> n >> h;
    vector<XyeHyin> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    for(int i=0;i<n;i++){
       int g=gcd(gcd(a[i].x,a[i].y),2*h-a[i].z);
       int aa=a[i].x/g,bb=a[i].y/g,cc=(2*h-a[i].z)/g;
       cout<<aa<<" "<<bb<<" "<<cc<<endl;
    }
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}