#include <bits/stdc++.h>
using namespace std;
int _;
vector<int>v;
int cnt = 0;    
void dfs(int n){
    if(v.size() >=1){
        cnt++;
    }
    
    for (int i = 1;i<=n/2;i++){
        v.push_back(i);
        dfs(i);
        v.pop_back();
    }
}
int main(){
    
    cin>>_;
      v.push_back(_);
    dfs(_);
    cout<<cnt;
    return 0;
}