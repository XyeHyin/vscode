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
bool cmp(PII a, PII b){
    if(a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}
void solve(){
    int n;
    cin >> n;
    vector<PII> a(n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int cnt = count(s.begin(), s.end(), 'o');
        a[i] = {cnt, i};
    }
    sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < n; i++){
        cout << a[i].second + 1 << " ";
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