#include <bits/stdc++.h>
using namespace std;
int main(){
    int k, l, r;
    cin >> k >> l >> r;
    int ans = 0;
    for(int i=l;i<=r;i++){
        string s=to_string(i);
        if(i%k==0||s[s.size()-1]-'0'==k){
            ans += i;
        }
    }
    cout<<ans<<endl;
    return 0;
}