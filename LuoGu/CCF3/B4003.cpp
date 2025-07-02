#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ans(26, ' ');
    for (int i = 0; i < 26;i++){
       ans[i]=s[(i+n)%26];
    }
    cout << ans;
    return 0;
}