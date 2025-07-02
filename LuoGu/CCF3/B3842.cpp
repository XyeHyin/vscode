#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    set<int> s;
    while(m--){
        int a;
        cin>>a;
        s.insert(a);
    }
    if(s.size() == n){
        cout << n;
    }else{
        for(int i = 0;i<n;i++){
            if(s.find(i) == s.end()){
                cout<<i<<" ";
            }
        }
    }
    return 0;
}