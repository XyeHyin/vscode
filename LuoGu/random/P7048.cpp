#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h, w;
    cin >> h >> w;
    printf("%f", max(min(min(h,w)*1.0, max(h,w) / 3.0), min(h,w) / 2.0));

    return 0;
}