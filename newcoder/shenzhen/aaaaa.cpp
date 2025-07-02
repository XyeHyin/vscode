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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(26, 0);
    for (int i = 0; i < n;i++){
        a[s[i] - 'a']++;
    }
    int maxx = -1, pos = 0;
    for (int i = 0; i < 26;i++){
         if(maxx<a[i]){
             pos = i;
             maxx = a[i];
         }
    }
    char dic = pos + 'a';
    int ans = 0;
    s = ' ' + s;
    for (int i = k + 1; i <= n;i++){
        if(s[i]!=dic) {
            ans++;
            s[i] = dic;
        }
    }
    for (int i = 1; i <= n - k;i++){
        if (s[i] != dic) {
            ans++;
            s[i] = dic;
        }
    }
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