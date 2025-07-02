#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0;i<n;i++){
        cin>>a[i];
    }
    int money;
    cin>>money;
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(a[i]<=money){
            cnt++;
            money-=a[i];
        }
    }
    cout<<cnt;
    return 0;
}