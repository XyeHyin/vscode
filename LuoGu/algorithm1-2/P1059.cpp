#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    cout<<unique(a.begin(),a.end())-a.begin()<<endl;
    for(auto i = a.begin();i<unique(a.begin(),a.end());i++){
        cout<<*i<<" ";
    }
    return 0;
}