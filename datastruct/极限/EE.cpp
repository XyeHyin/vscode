#include <bits/stdc++.h>
using namespace std;
int main() {
    int cnt = 0, ans=0,tmp=0;
    for (int i = 0; i < 7; i++) {
        int a, b;
        cin >> a >> b;
        int s=a+b;
        if(s>8){
            if(s>tmp){
                tmp=s;
                ans=i+1;
                cnt = 1;
            }
        }
    }
    if(cnt)cout<<ans<<endl;
    else cout<<0<<endl;
    return 0;
}