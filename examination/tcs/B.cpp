#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        auto it=find_if_not(s.begin(),s.end(),[](char c){return c=='0'||c=='1';});
        if(it!=s.end()){
            cout<<"INVALID"<<endl;
            continue;
        }
        int a, b;
        cin >> a >> b;
        string tmp=s;
        if (a <= b) sort(tmp.begin(), tmp.end());
        else sort(tmp.begin(), tmp.end(), greater<char>());
        int cnt = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != tmp[i]) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}