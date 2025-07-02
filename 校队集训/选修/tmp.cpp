#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string> s({"Bob","JOHN","alice","bob","ALICE","J","Bob"});
    map<string,int> mp;
    for (int i = 0; i < s.size();i++){
        if(s[i].size()>=2){
        transform(s[i].begin(), s[i].end(), s[i].begin(), ::tolower);
        s[i][0] = toupper(s[i][0]);
        mp[s[i]]++;
        }
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
        return 0;
}