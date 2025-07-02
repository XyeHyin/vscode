#include <bits/stdc++.h>
using namespace std;
int main(){
    int x, n,ans=0;
    cin>>x>>n;
    while(n--){
        if(x!=6&&x!=7){
            ans+=250;
        }
        if(x==7){
            x=1;
        }else{
            x++;
        }
    }
    cout<<ans<<endl;
    return 0;
}