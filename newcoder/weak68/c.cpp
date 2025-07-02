#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    set<int> se;
    set<int> se1;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        se.insert(x);
        st.insert(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        se1.insert(x);
        st.insert(x);
    }
    int m=abs((int)(se.size()-se1.size()));
    int ans=max(n-se.size(),n-se1.size());
    if(se.size()+se1.size()-st.size()>m){
        ans += (se.size() + se1.size() - st.size() - m + 1) / 2;
    }
    cout << ans << endl;

    return 0;
}