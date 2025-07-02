#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
   vector<int> dp(n+1,0);
   dp[0] = 0;
   dp[1] = 1;
   for (int i = 2; i <= n;i++){
       for (int j = 1; j <= i / 2;j++){
           dp[i] += dp[j];
       }
       dp[i]++;
   }
   cout << dp[n];
   return 0;
}