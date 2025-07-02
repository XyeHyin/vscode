#include <bits/stdc++.h>
using namespace std;
int main()
{
    string weekend[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    vector<string> s(4);
    bool haveBig = false;
    for (int i = 0; i < 4; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < min(s[0].size(), s[1].size()); i++)
    {   if(!haveBig){
        if (s[0][i] == s[1][i]&&s[0][i]>='A'&&s[0][i]<='G')
        {
            cout<<weekend[s[0][i]-'A']<<" ";
            haveBig = true;
        }
    }else{
        if (s[0][i] == s[1][i] && (s[0][i] >= 'A' && s[0][i] <= 'N')){
           printf("%02d:",s[0][i]-'A'+10);
           break;
        }
        else if (s[0][i] == s[1][i] && (s[0][i]-'0'>=0  && s[0][i]-'0' <= 9)){
            printf("%02d:",s[0][i]-'0');
            break;
        }
    }
    }
    for (int i = 0; i < min(s[2].size(), s[3].size()); i++)
    {
        if (s[2][i] == s[3][i] && isalpha(s[2][i]))
        {
            printf("%02d\n",i);
            break;
        }
    }
}