#include <bits/stdc++.h>
using namespace std;
int main() {
    int w, n;
    cin >> w >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    int l = 0, r = n - 1;
     while(l<=r){
        if(l==r){
            cnt++;
            break;
        }
        if(a[l]+a[r]>w){
            r--;
            cnt++;
        }else if(a[l]+a[r]<=w){
            r--;
            l++;
            cnt++;
        }
     }
     cout << cnt;
     return 0;
}