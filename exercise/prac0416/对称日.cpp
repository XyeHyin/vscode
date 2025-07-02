#include <bits/stdc++.h>
using namespace std;
string dic[13]={"zero","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
int main(){
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        string s;
        string ans="";
        getline(cin, s);
        for (int j = s.size() - 1;;j--){
            if(s[j]==' '){
                ans = s.substr(j + 1);
                break;
            }
        }
        while(ans.size()!=4){
            ans.insert(0, "0");
        }
        for (int j = 0; j < 13; j++)
        {
            if (s.substr(0, 3) == dic[j])
            {
                if (j < 10)
                    ans += "0";
                ans += to_string(j);
            }
        }
            int left = 0, right = 0;
            for (int j = 0;; j++)
            {
                if (s[j] == ' ')
                    left = j;
                if (s[j] == ',')
                {
                    right = j;
                    break;
                }
            }
            if (right - left-1 == 1)
                ans += "0";
            ans += s.substr(left + 1, right - left - 1);
            bool flag = true;
            for (int j = 0, k = ans.size() - 1; j < k;j++,k--){
                if(ans[j]!=ans[k]){
                    flag = false;
                    break;
                }
            }
            if (flag)cout << "Y ";
            else cout << "N ";
                cout << ans << endl;
        }
}