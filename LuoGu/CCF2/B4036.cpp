#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans+=s[i]-'0';
        }
        if(!(ans%7)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}