#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    while (b ^= a ^= b ^= a %= b);
    return a;
}
int main(){
    int n,flag;
    cin >> n;
    vector<int> dp(10001, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        flag=gcd(flag,x);
        dp[x] = 1;
    }
    if(flag!=1){
        cout << "INF" << endl;
        return 0;
    }
    int cnt = 0;
    dp[0] = 1;

    for (int i = 1; i <= 9710;i++){
        for (int j = 0; j <= i/2;j++){
            dp[i] =dp[i]||dp[j]&&dp[i - j];
            if (dp[i]) break;
        }
        if(!dp[i]) cnt++;
    }
    cout << cnt << endl;
       
    return 0;
}