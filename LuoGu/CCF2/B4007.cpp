#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        string s=to_string(i);
        for(int j=0;j<s.size();j++){
            if(s[j]-'0'==k){
                cnt++;
            }
        }
    }
    cout << cnt;
    
    return 0;
}