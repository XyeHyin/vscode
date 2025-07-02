#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> emoji;
    for (int i = 0; i < 3; i++)
    {
        string s;
        getline(cin, s);
        emoji.push_back(s);
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int cnt = -1, cnt2 = 0, cnt3 = 0;
        string s;
        bool edge = true;
        for (int j = 0; j < 5; j++)
        {
            int left = 0, right = 0, count = 0;
            int m;
            cnt3++;
            if (cnt3 > 3)
                cnt--;
            else
                cnt++;
            cin >> m;
            
            if (m < 1)
            {
                edge = false;
                break;
            }
            bool have = false;
            for (int k = 0; k < emoji[cnt].size(); k++)
            {
                if (emoji[cnt][k] == '[')
                {
                    left = k;
                }
                if (emoji[cnt][k] == ']')
                {
                    right = k;
                    count++;
                }
                if (count == m)
                {
                    have = true;
                    cnt2++;
                    if (cnt2 == 2)
                        s += "(";
                    s += emoji[cnt].substr(left + 1, right - left - 1);
                    if (cnt2 == 4)
                        s += ")";
                    break;
                }
            }
        }
        if(!edge){
            cout << "Are you kidding me? @\\/@"<<endl;
            continue;
        }
        if (cnt2 == 5)
            cout << s;
        else
            cout << "Are you kidding me? @\\/@";
        cout << endl;
    }
}