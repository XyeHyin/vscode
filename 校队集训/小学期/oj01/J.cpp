#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int ans = 0;
    do{
        ans=max(ans,stoi(s));
    }while(next_permutation(s.begin(),s.end()));
         
     cout<<ans<<endl;
    return 0;
}