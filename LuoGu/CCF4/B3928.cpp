#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int cnt = 0;
    vector<bool> vis(n, false);
    int j = 0;
    for(int i=0;i<n;i++){
       for(;j<n;j++){
           if(!vis[j] && a[j] > b[i]){
               vis[j] = true;
               cnt++;
               break;
           }
       }
    }
    cout << cnt << endl;
    return 0;
}