#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    while(n--){
        int nn, k;
        cin >> nn >> k;
        string s=to_string(nn);
        int wei = s.size();
        pair<int, int> ans = {0, 0};
        for (int i = 0; i <= k;i++){
            for(int j=0;j<wei;j++){
                int tmp = i * pow(10, j) + nn;
                vector<int> a(10, 0);
                while(tmp){
                    a[tmp % 10]++;
                    tmp /= 10;
                }
                for(int l=0;l<10;l++){
                    if(a[l]==0){
                        if(ans.first<l){
                            ans.first = l;
                            ans.second = 1;
                        }else if(ans.first==l){
                            ans.second++;
                        }
                        break;
                    }
                }

            }
        }
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}