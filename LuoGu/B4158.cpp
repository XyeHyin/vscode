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
bool isprime(int n) {
    if(n == 0||n==1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int cnt;
int ans = 0x3f3f3f3f;
void dfs(string s,int step){
    if(step==0){
        int num = stoll(s);
        if(isprime(num)){
            ans = min(ans,num);
        }
        return;
    }

    auto it = find(s.begin(),s.end(),'*');
    for (int i = 0; i <= 9;i++){
        s[it-s.begin()] = i+'0';
        dfs(s,step-1);
        s[it-s.begin()] = '*';
    }
}
void solve(){
    string s;
    cin >> s;
    cnt=count(s.begin(),s.end(),'*');
    dfs(s,cnt);
    if(ans==0x3f3f3f3f){
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;
    ans = 0x3f3f3f3f;
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