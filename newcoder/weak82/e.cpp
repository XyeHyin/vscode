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
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    vector<int> b(n+1);
    priority_queue<int> c;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    vector<int> aa(n + 1);
    vector<int> bb(n + 1);
    for(int i = 1; i <= n; i++){
        if(i==1) {
            c.push(a[i]);
            aa[i]=a[i];
        }
        else if(c.size() < m){
            c.push(a[i]);
            aa[i]=aa[i-1]+a[i];
        }else{
            if(c.top() < a[i]){
                aa[i] = aa[i - 1];
            }else{
                aa[i] = aa[i - 1] + a[i]-c.top();
                c.pop();
                c.push(a[i]);
                
            }
        }
        // dbg(aa[i]);
    }
    while(!c.empty()) c.pop();
    for(int i = n; i >= 1; i--){
        if(i==n) {
            c.push(b[i]);
            bb[i]=b[i];
        }
        else if(c.size() < m){
            c.push(b[i]);
            bb[i]=bb[i+1]+b[i];
        }else{
            if(c.top() < b[i]){
                bb[i] = bb[i + 1];
            }else{
                bb[i] = bb[i + 1] + b[i]-c.top();
                c.pop();
                c.push(b[i]);
            }
        }
        // dbg(bb[i]);
    }
    int ans = 0x3f3f3f3f;
    for(int i = m; i <= n-m; i++){
        ans = min(ans, aa[i] + bb[i + 1]);
    }
    cout << ans << endl;
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