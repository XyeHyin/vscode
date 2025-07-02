#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> mp;
    for(int i=0;i<n;i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    int cnt = 0;
    sort(a.begin(), a.end());
    int l = 0, r = 0;
    while (r < n) {
        if (a[r] - a[l] == k) {
            cnt += mp[a[l]] * mp[a[r]];
            l+=mp[a[l]];
            r+=mp[a[r]];
        } else if (a[r] - a[l] < k) {
            r++;
        } else {
            l++;
        }
    }
    cout<<cnt<<endl;
        return 0; 
}