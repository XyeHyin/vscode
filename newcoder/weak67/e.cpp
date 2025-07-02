#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int ans = 0;
        int a=l1+l2,b=r1+r2;
        string s=to_string(b);
        if(max(l1,b-r2)<=min(r1,b-l2)){
            int num = 0;
            for(int i=0;i<s.size();i++){
                num+=s[i]-'0';
            }
            ans=max(ans,num);
        }
        for (int i = 1;i<=s.size();i++){
            string ss = s;
            if (ss[i - 1] > '0'){
                ss[i - 1]--;
                for (int j = i;j<s.size();j++){
                    ss[j] = '9';
                }
            }
            int tmp = stoll(ss);
            if(tmp>=a){
               if(max(l1,tmp-r2)<=min(r1,tmp-l2)){
                   int num = 0;
                     for(int j=0;j<ss.size();j++){
                          num+=ss[j]-'0';
                     }
                   ans=max(ans,num);
               }
            }
        }
        cout << ans << endl;
    }
    return 0;
}