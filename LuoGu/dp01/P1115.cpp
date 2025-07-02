#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int pre = 0, ans = 0, l = 0;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
       if(ans<x){
        if(pre+l<i){
            ans = x;
            l = x-pre;
        }
       }else if(ans+x>ans&&pre+l==i){
              ans += x;
              l++;
       }
    }
    cout << ans << endl;
    return 0;
}