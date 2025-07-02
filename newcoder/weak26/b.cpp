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
    string s;
    cin >> s;
    string ss = s;
    for(int i = 0; i < s.size()-1; i++){
        if(s[i]=='1'){
            s[i]='0';
            if(s[i+1]=='0'){
                s[i+1]='1';
            }else{
                s[i+1]='0';
            }
        }
    }
    if(s[s.size()-1]=='0'){
        cout<<"Yes"<<endl;
        return;
    }
    for (int i = 0; i < ss.size() - 1; i++) {
        if (ss[i] == '0') {
            ss[i] = '1';
            if (ss[i + 1] == '1') {
                ss[i + 1] = '0';
            } else {
                ss[i + 1] = '1';
            }
        }
    }
    if(ss[ss.size() - 1] == '1') {
        cout << "Yes" << endl;
        return;
    }else{
        cout << "No" << endl;
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