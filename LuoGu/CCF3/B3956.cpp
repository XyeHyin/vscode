#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    char a[n];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n;i++){
        if(islower(a[i])){
            ans+=a[i]-'a'+1;
        }
        if (isupper(a[i]))
        {
            ans -= a[i];
        }
        
    }
    cout << ans;
    return 0;
}