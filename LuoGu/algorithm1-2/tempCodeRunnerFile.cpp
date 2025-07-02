#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    set<int> s(a.begin(),a.end());
    cout<<s.size()<<endl;
    sort(a.begin(),a.end());
    for (int i = 0; i < a.size();i++){
        cout<<a[i]<<" ";
    }
    return 0;
}