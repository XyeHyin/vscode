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
string s1, s2;
void solve(){
    cin>>s1>>s2;
    int n = s1.size(), m = s2.size();
    vector<int> nxt(m+5, 0);
    s1.insert(s1.begin(), '0');
    s2.insert(s2.begin(), '0');
    for(int i = 2, j = 0; i <= m; i++){
        while(j && s2[i] != s2[j+1]) j = nxt[j];
        if(s2[i] == s2[j+1]) j++;
        nxt[i] = j;
    }
    for(int i = 1, j = 0; i <= n; i++){
        while(j && s1[i] != s2[j+1]) j = nxt[j];
        if(s1[i] == s2[j+1]) j++;
        if(j == m){
            cout<<i - m + 1<<endl;
        }
    }
    for(int i = 1; i <= m; i++) cout<<nxt[i]<<" ";
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