#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, ss;
    cin >> s >> ss;
    int a = s[0] - 'a', b = ss[0] - 'a';
    if (s.size() != ss.size()) {
        cout << "False" << endl;
        return 0;
    }
    set<char> se;
    set<char> st;
    for(int i=0;i<s.size();i++){
        int aa=se.size(),bb=st.size();
        se.insert(s[i]);
        st.insert(ss[i]);
        if((se.size()==aa)^(st.size()==bb)){
            cout<<"False"<<endl;
            return 0;
        }
    }
    cout<<"True"<<endl;
    return 0;
}