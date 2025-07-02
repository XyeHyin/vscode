#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int _;
    cin >> _;
    while(_--){
        int n;
        cin >> n;
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            mp[x]++;
        }
        int ans = 0x3f3f3f3f;
        int cnt = 0;
        for(auto [aa, bb] : mp){
            if(bb <= 2) continue;
            ans = min(ans, aa * 3);
        }
        if(ans == 0x3f3f3f3f) cout << "no" << endl;
        else cout<<"yes"<<endl << ans << endl;
    }
    return 0;
}