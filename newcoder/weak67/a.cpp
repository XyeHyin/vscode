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
    string s, a, b, c;
    cin>>s;
    for(int i = 0; i < n; i++){
        if(islower(s[i])){
            a += s[i];
        }else if(isdigit(s[i])){
            b += s[i];
        }else{
            c += s[i];
        }
    }
    cout<<a+b+c<<endl;
    return 0;
}