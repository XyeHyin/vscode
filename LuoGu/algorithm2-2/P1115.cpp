#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pos;
    for (int i = 0; i < n;i++){
       cin>>a[i];
       if(a[i]<0){
           pos.push_back(i);
       }
    }
    int ans = 0;
    int j = 0;
    int temp = 0;
    for (int i = 0; i < n;i++){
        ans += a[i];
        if(i==pos[j]){
            
        }

    }

        return 0;
}