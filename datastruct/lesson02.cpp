#include <bits/stdc++.h>
using namespace std;
int DecimalToseven(int n){
    int res = 0;
    int base = 1;
    while(n){
        res += n%7*base;
        n/=7;
        base*=10;
    }
    return res;
}
int main(){
    int n = 1000000;
    n = DecimalToseven(n);
    cout<<n<<endl;
    int ans = 0;
    while(n){
        ans += n%10;
        n/=10;
    }
    cout<<ans<<endl;
    // int base = 1;
    // for (int i = 1;;i++){
    //     if(n<=0){
    //         cout << i << endl;
    //         cout<<n<<endl;
    //         break;
    //     }
    //     if(i%5==0){
    //         base*=7;
    //     }
    //     n-=base;
    // }
        return 0;
}