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
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt = 0;
    for (int i = 0;i<n;i++){
        for (int j = i + 1;j<n; j++) {
                cnt+=((a[i]*a[j])%495==0);
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        a[i]++;
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cnt1 += ((a[i] * a[j]) % 495 == 0);
            }
        }
        ans = max(ans, cnt1);
        a[i]--;
    }
    cout << ans << endl;
        return 0;
}