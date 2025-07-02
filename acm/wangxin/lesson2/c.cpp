#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(101,0);   
    for (int i = 0; i < n; i++){
        int aa;
        cin >> aa;
        a[aa]++;
    }
    cout<<count(a.begin(),a.end(),1)<<endl;
    return 0;
}