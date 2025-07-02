#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    auto it=find_if_not(s.begin(),s.end(),[](char c){return c=='0';});
    s.erase(s.begin(),it);
    string ss = s;
    string sss;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            ss = s.substr(0, i);
            sss = s.substr(i);
            break;
        }
    }
    int j = 0;
    string ans = "";
    for (int i = ss.size() - 1; i >= 0; i--) {
        ans = ss[i] + ans;
        j++;
        if (j % 3 == 0) ans = "," + ans;
    }
    if (ans[0] == ',') ans = ans.substr(1);
    ans += sss;
    cout << ans << endl;
    return 0;
}