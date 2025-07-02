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

void solve(){
    int a, b;
    scanf("%lld.%lld", &a, &b);
    string s = to_string(a);
    reverse(s.begin(), s.end());
    string ss = to_string(b);
    reverse(ss.begin(), ss.end());
    cout << s << "." << ss << endl;
    return;
}

signed main(){
    int t = 1;
    // cin >> t;
    while(t--)	solve();
    return 0;
}