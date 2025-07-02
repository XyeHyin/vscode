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
string f(string s){
    auto it = s.find('.');
    if (it == string::npos) {
        s += ".000000";
    } else {
        s = s.substr(0, it + 7);
        while (s.size() - it - 1 < 6) {
            s += '0';
        }
    }
    return s;
}
void solve(){
    string a, b;
    cin >> a >> b;
    a = f(a);
    b = f(b);
    if (a == b) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)	solve();
    return 0;
}