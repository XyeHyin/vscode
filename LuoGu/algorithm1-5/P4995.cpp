#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    vector<int> biga = a;
    vector<int> smalla = a;
    sort(biga.begin(), biga.end(),greater<int>());
    sort(smalla.begin(), smalla.end());
    vector<int> ans;
    for (int i = 0; i < n/2;i++){
        ans.push_back(biga[i]);
        ans.push_back(smalla[i]);
    }
    if(n%2==1){
        ans.push_back(biga[n/2]);
    }
    int res = ans[0]*ans[0];
    for (int i = 1; i < n;i++){
        res += (ans[i] - ans[i - 1])* (ans[i] - ans[i - 1]);
    }
    cout << res;
    return 0;
}