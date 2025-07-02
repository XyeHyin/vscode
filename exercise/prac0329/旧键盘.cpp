#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, realS, ans;
    cin >> s >> realS;
    for (int i = 0, j = 0; i < s.size(); i++)
    {
        if (s[i] == realS[j])
        {
            j++;
        }
        else{
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                bool flag = false;
                for (int k = 0;k<ans.size();k++){
                    if (ans[k]==s[i] - 'a' + 'A'){
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    ans += s[i] - 'a' + 'A';
                }
            }
            else{
                bool flag2 = false;
                for (int k = 0; k < ans.size(); k++)
                {
                    if (ans[k] == s[i])
                    {
                        flag2 = true;
                        break;
                    }
                }
                if (!flag2)
                {
                    ans += s[i];
                }
            }
        }   
        }
    cout << ans<<endl;
}