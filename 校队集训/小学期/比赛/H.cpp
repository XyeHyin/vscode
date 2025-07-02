#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<string> mp(n);
    int len = 0;
    for (int i = 0; i < n;i++){
        string  _;
        cin >> _;
        mp[i] = _;
        int tmp = mp[i].size();
        len = max(len, tmp);
    }
    map<string, int> mpp;
    map<string, int>  bb;
    for (int i = 0; i < n;i++){
        int j = 0;
        while(mp[i].size()<len){
            mp[i] = '0' + mp[i];
            j++;
        }
        // cout << j << endl;
        // cout << mp[i]<<endl;
        mpp[mp[i]] = j;
        // cout<<mpp[mp[i]]<<endl;
    }
    sort(mp.begin(), mp.end());

    string ans = "";
    for (int i = 0; i < n;i++){
        string s = mp[i];
        mp[i] = mp[i].substr(mpp[mp[i]], mp[i].size() - mpp[mp[i]]);
        ans += mp[i];
    }
    cout<<ans;
        return 0;
}