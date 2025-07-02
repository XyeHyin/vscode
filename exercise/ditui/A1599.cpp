#include <bits/stdc++.h>
using namespace std;
int main(){
    int m;
    cin >> m;
    for (int i = 0; i < m;i++){
        int n;
        cin >> n;
        int dp[n];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        int sum = 3;
        if (n > 3){
            for (int i = 3; i < n;i++){
                dp[i] = dp[i - 1] + dp[i - 2];
                sum += dp[i];
            }
            cout << sum;
            continue;
        }else{
            cout << n << endl;
            continue;
        }
    }
}