// #include <bits/stdc++.h>
// using namespace std;
// vector<pair<int,int>> a;
// int n;
// int minn = 0x3f3f3f3f;
// void dfs(int step,int suan,int ku){
//       if(step>=n){
//         if(suan == 1 && ku == 0) return;
//           minn = min(minn, abs(suan - ku));
//           return;
//       }
//           dfs(step + 1, suan * a[step].first, ku + a[step].second);
//           dfs(step + 1, suan, ku);
// }
// int main(){

//     cin >> n;
//     a.resize(n);
//     for (int i = 0; i < n;i++){
//         cin >> a[i].first >> a[i].second;
//     }
//     dfs(0, 1, 0);
//     cout << minn;

//     return 0;
// }
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
    vector<PII> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    int ans = 0x3f3f3f3f;
    for (int i = (1 << n) - 1; i >0; i--) {
        int suan = 1, ku = 0;
        // dbg(i);
        for (int j = n-1; j >= 0; j--) {
            if ((i >> j) & 1) {
                suan *= a[j].first;
                ku += a[j].second;
            }
        }
        int tmp = ans;
        ans = min(ans, abs(suan - ku));
        
    }
    cout << ans << endl;
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
// #include <bits/stdc++.h>
// using namespace std;

// #define int long long
// #define double long double
// #define PII pair<int, int>
// #define dbg(x) std::cout << #x << ":" << x << " "
// #define MP make_pair
// #define PB push_back
// #define rep(i,x,n) for(int i=x;i<=n;i++)
// #define dep(i,x,n) for(int i=x;i>=n;i--)
// #define arrout(a,n) rep(i,1,n)std::cout<<a[i]
// #define arrin(a,n) rep(i,1,n)std::cin>>a[i]
// #define endl '\n'

// void solve(){
//     int n=100;
//     for(int i = 1; i <= n; i++){
//         cout<<i<<": "<<(int)__lg(i)+1;
//         cout << endl;
//     }
//     return;
// }

// signed main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int t = 1;
//     // cin >> t;
//     while(t--)	solve();
//     return 0;
// }