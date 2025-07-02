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
    vector<int> a(n+1);
    int l = 1, r = n;
    int cntl = 0, cntr = 0;
    a[r] = n;
    cntr++;
    r--;
    bool zuo = 1;
    for (int i = n-1; i >= 1; i--) {
        if(cntl<cntr){
            a[l] = i;
            cntl++;
            l++;
        }else if(cntl==cntr){
            if(zuo){
                a[l] = i;
                cntl++;
                l++;
                zuo = 0;
            }else{
                a[r] = i;
                cntr++;
                r--;
                zuo = 1;
            }
        }else{
            a[r] = i;
            cntr++;
            r--;
        }
    }
    for (int i = 1; i <= n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
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