#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    vector<int> v(61);
    v[1] = 1;
    v[2] = 2;
    v[3] = 4;
    for (int i = 4; i <= 60; i++) {
        v[i] = v[i - 1] + v[i - 3]+v[i-2];
    }
    int n;
    cin >> n;
    cout << v[n] << endl;
    return 0;
}