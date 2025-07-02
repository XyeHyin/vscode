#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> sum1(n+1);
    int sum=0;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        sum1[i] = a[i]+sum1[i-1];
        sum+=a[i];
    }
    int cnt = 0;
    for (int i = 1; i < n;i++){
       if(sum1[i]==sum-sum1[i]){
           cnt++;
       }
    }
    cout << cnt << endl;
        return 0;
}