#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, n;
    cin >> t>>n;
    vector<int> a(t);
    for(int i=0; i<t; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}