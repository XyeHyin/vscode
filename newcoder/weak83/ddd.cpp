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
    n--;
    if(n==0){
        cout << 0 << " " << 0 << endl;
        return;
    }
    int k=(int)(sqrt(n)+1)/2;
    int t=4*k*(k-1)+1;
    int side=(n-t)/k;
    int pos=(n-t)%k;
    if (side == 0) { 
        cout<<"side0"<<endl;
        cout << k << " " << pos - (k - 1) << endl;
    } else if (side == 1) { 
        cout<<"side1"<<endl;
        cout << k - pos - 1 << " " << -k << endl;
    } else if (side == 2) { 
        cout<<"side2"<<endl;
        cout <<(k - pos - 1) << " " << -k << endl;
    } else {
        cout<<"side3"<<endl;
        cout << -(k - pos - 1) << " " << k << endl;
    }
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