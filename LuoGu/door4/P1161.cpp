#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    vector<bool> flag(2000001,0);
    for (int i = 0; i < n; i++) {
        double a;
        int t;
        cin >> a >> t;
        for (int j = 1; j <= t; j++) {
            int b=(int) (a * j);
            flag[b] = !flag[b];
        }
    }
    for(int i = 1; i <= flag.size()-1; i++){
        if(flag[i]){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}