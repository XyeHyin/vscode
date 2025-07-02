#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    cout << count(s.begin(), s.end(), '0') << endl;
    return 0;
}