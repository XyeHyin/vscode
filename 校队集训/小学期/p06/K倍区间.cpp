#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k ;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0;i<n;i++){
        cin >> v[i];
    }
    vector<int> ans;
    int cnt = 0;
    for(int k=n-1;k>=0;k--){
    for (int j = 0; j+k<n;j++){
        partial_sum(v.begin()+j, v.end()-k, back_inserter(ans));
    for (int i = 0; i < ans.size() - 1; i++) {
        cout << ans[i] << " ";
        if(ans[i] % k == 0){
            cnt++;
        }
   }
    }
    }
    cout << cnt;
        
    return 0;
}