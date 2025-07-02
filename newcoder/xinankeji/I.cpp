#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define PII pair<int, int>
#define dbg(x) std::cout << #x << ":" << x << " "
#define MP make_pair
#define PB push_back
#define rep(i,x,n) for(int i=x;i<=n;i++)
#define dep(i,x,n) for(int i=x;i>=n;i--)
#define arrout(a,n) rep(i,1,n)std::cout<<a[i]
#define arrin(a,n) rep(i,1,n)std::cin>>a[i]
#define endl '\n'

void solve(){
    vector<string> mp(3);
    int len;
    for (int i = 0; i < 3;i++){
        string s;
        cin >> s;
        len = s.size();
        for (int j = 0; j < len;j++){
            mp[i][j] = s[j];
        }
    }
    // for (int i = 0; i < 3;i++){
    //     for (int j = 0; j < len;j++){
    //         cout << mp[i][j];
    //     }
    //     cout << endl;
    // }
        for (int i = 0; i < len; i++) {
            vector<int> cnt(9, 0);
            for (int j = 0; j < 3; j++) {
                cnt[mp[j][i] - '0']++;
            }
            cout << max_element(cnt.begin(), cnt.end())-cnt.begin();
        }

        return;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)	solve();
    return 0;
}