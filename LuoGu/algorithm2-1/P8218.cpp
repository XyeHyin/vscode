#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> pre(n+1);
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << endl;
    }
    return 0;
}