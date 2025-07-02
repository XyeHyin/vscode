#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define PII pair<int, int>
#define dbg(x) std::cout << #x << ":" << x << " "
#define MP make_pair
#define PB push_back
#define rep(i, x, n) for (int i = x; i <= n; i++)
#define dep(i, x, n) for (int i = x; i >= n; i--)
#define arrout(a, n) rep(i, 1, n) std::cout << a[i]
#define arrin(a, n) rep(i, 1, n) std::cin >> a[i]
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    string s;
    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        mp[c]=i;
        s += c;
    }
    char c=s[0];
    set<char> st;
    int i = 0;
    bool flag[26] = {0};
    for (;i<mp[c];i++){
        st.insert(s[i]);
        flag[s[i]-'A']=1;
        if(mp[s[i]]==i){
            i++;
            break;
        }
    }
    int cnt=st.size();
    for (int j = i; j < n; j++) {
        if(flag[s[j]-'A'])
            continue;
        cnt++;
    }
    cout << cnt << endl;

        return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}