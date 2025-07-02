#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[] = {1, 0, 1, 0, 0, 0, 1, 0, 2, 1, 1};
    string s;
    cin>>s;
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        ans+=a[s[i]-'0'];
    }
    cout << ans;
    return 0;
}