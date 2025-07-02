#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, a, b;
    cin >> n>>a>>b;
    int num=min(a,b);
    int cnt=0;
    while(n){
        if(n-num>=0){
            n-=num;
        }else{
            break;
        }
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}