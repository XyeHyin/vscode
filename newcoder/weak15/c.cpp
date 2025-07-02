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
    if(s.size()>3){
        for (int i = 0;i<s.size();i++){
            if(isdigit(s[i])&&(s[i]-'0')&1){
                cout << -1 << endl;
                return;
            }
            if(s[i]=='?'){
                if(s[i-1]=='2'){
                    s[i]='0';
                }else{
                    s[i]='2';
                }
            }
            if(s[i]==s[i-1]){
                cout << -1 << endl;
                return;
            }
        }
        cout<<s<<endl;
    }else{
        if(s=="111") cout<<-1<<endl;
        else if(s=="222") cout<<-1<<endl;
        else if(s=="000") cout << -1 << endl;
        else if(s=="?00") cout << "-1" << endl;
        else if(s=="00?") cout << "-1" << endl;
        else if(s=="11?") cout << "-1" << endl;
        else if(s=="?11") cout << "-1" << endl;
        else if(s=="22?") cout << "-1" << endl;
        else if(s=="?22") cout << "-1" << endl;
        else if(s=="?02") cout << "202" << endl;
        else if(s=="?20") cout << "020" << endl;
        else if(s=="02?") cout <<"020" << endl;
        else if(s=="20?") cout << "202" << endl;
        else{
            cout<<-1<<endl;
        }

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