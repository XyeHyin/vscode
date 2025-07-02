#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(k,0);
    ll x, y=0;
    for(ll i = 0;i<n;i++){
        cin >> x;
        y=(y+x)%k;
        a[y]++;
    }
    ll sum = 0;
    for(ll i = 0;i<k;i++){
        sum += a[i]*(a[i]-1)/2;
    }
    sum += a[0];
    cout << sum;
    return 0;
}