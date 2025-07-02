#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cnt = 0;
    for (int i = 1;i<=n;i++){
        for(int j = i;j<=n;j++){
            int ans = i * i + j * j;
            if(sqrt(ans)==(int)sqrt(ans)&&sqrt(ans)<=n){
                cnt++;
            }
        }

    }
    cout<<cnt
    ;
    return 0;
}