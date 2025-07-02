#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    int len = 0;
    for (int i = 0; i < n;i++){
        len= std::max(len,(int)a[i].size());
    }
    for (int i = 0; i < n;i++){
        while(a[i].size()<len){
               a[i] = "0" + a[i];
        }
    }
        auto max = max_element(a.begin(), a.end());
    cout<<distance(a.begin(),max)+1<<endl<< *max<< endl;
    return 0;
}