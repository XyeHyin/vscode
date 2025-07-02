#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for (int i = 0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        int b;
        cin >> b;
        cout<<a[b-1]<<endl;
    }
    return 0;
}