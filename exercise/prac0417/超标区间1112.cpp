#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, t;
    cin >> n >> t;
    vector<int> a(n),ans;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int max = -1;
    bool flag = false;
    for (int i = 0; i < n;i++){
        if(a[i]>max) max = a[i];
        if(a[i]>t&&!flag){
           ans.push_back(i);
              flag = true;
        }
        if(a[i]<=t&&flag){
            ans.push_back(i - 1);
            flag = false;
        }
        if(i==n-1&&flag) ans.push_back(i);
    }
    if(ans.empty()) cout << max << endl;
    else{
        for (int i = 0; i < ans.size();i+=2){
            cout<<"["<<ans[i]<<", "<<ans[i+1]<<"]"<<endl;
        }
    }
    return 0;
}