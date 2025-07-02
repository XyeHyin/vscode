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
    cin>>n;
    vector<int> a(n);
    vector<int> b(9,0);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        b[a[i]-1]++;
        if((i+1)%8==0){
            if(b[0]&&b[1]&&b[2]&&b[3]&&b[4]&&b[5]&&b[6]&&b[7]&&b[8]){
                NULL;
            }else{
                cout<<"NO"<<endl;
                return;
            }
            b.assign(9,0);
            arrout(b,8);
        }

        }
    cout<<"YES"<<endl;
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