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
    int n;
    cin >> n;
    vector<int> a(n);   
    vector<int> b(n);
    vector<int> c(n);
    priority_queue<PII> q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]=a[i]*(i+1);
        q.push({a[i], i});
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    sort(b.begin(), b.end(), greater<int>());
    for(int i = 0; i < n; i++){
        auto[ x, y] = q.top();
        c[y] = b[i];
        q.pop();
    }
    for(int i = 0; i < n; i++){
        cout << c[i] << " ";
    }
    return;
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