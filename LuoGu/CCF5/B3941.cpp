#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=lcm(a[0],a[1]);
    for (int i = 2;i<n;i++){
         ans=lcm(ans,a[i]);
    }
    cout<<ans<<endl;
        return 0;
}