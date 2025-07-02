#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int maxn = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    maxn = a[n - 1];
    int cnt;
    int l = 0, r = maxn;
    while(l <= r){
        int mid = (l + r) / 2;
        cnt = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > mid){
                cnt += a[i] - mid;
            }
        }
        if(cnt >= m){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << r << endl;
    return 0;
}