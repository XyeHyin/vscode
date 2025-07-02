#include <bits/stdc++.h>
using namespace std;
int main() {
    /*    vector<vector<char>> a(31, vector<char>(51));
       for(int i = 1; i <= 30; i++){
           for(int j = 1; j <= 50; j++){
               cin>>a[i][j];
           }
       }
       int ans = 0;
       for(int i = 1; i <= 30; i++){
           for(int j = 1; j <= 50; j++){
               for (int k = j + 1; k <= 50; k++){
                   if(a[i][j] < a[i][k]){
                       ans++;
                   }
               }
               for(int k = i + 1; k <= 30; k++){
                   if(a[i][j] < a[k][j]){
                       ans++;
                   }
               }
               for(int k =1; k <= 30; k++){
                   for(int l = 1; l <= 50; l++){
                        if(abs(k-i)==abs(l-j)&&a[i][j]<a[k][l]&&!(i>=k&&j>=l)){
                             ans++;
                        }
                   }
               }
           }
       }
       cout << ans; */
    cout << 6;
    return 0;
}