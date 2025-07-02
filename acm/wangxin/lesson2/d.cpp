#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int c(int n,int m){
    if(n==m||m==0){
        return 1;
    }
    return c(n-1,m-1)+c(n-1,m);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(101,0);   
    for (int i = 0; i < n; i++){
        int aa;
        cin >> aa;
        a[aa]++;
    }
    int ans=0;
    for(int i=0;i<101;i++){
        if(a[i]>1){
            ans+=c(a[i],2);
        }
    }
    cout<<ans<<endl;
    return 0;
}