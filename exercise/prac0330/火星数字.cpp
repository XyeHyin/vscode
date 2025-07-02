#include <bits/stdc++.h>
using namespace std;
int main()
{
    string diqiuNum[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string marsNum[] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        int ans = 0;
        string s;
        bool haveBai = false;
        int whitePos = 0;
        getline(cin, s);
        if (isalpha(s[0]))
        {
            for (int j = 0; j < s.length(); j++)
            {
                if (s[j] == ' ')
                {
                    haveBai = true;
                    whitePos = j;
                    break;
                }
            }
            if (haveBai)
            {
                for (int j = 0; j < 13; j++)
                {
                    if (s.substr(0, 3) == marsNum[j])
                    {
                        ans += j * 13;
                    }
                }
                for (int j = 0; j < 13; j++)
                {
                    if (s.substr(whitePos + 1, 3) == diqiuNum[j])
                    {
                        ans += j;
                    }
                }
                cout << ans << endl;
            }
            else
            {
                for (int j = 0; j < 13; j++)
                {
                    if (s == marsNum[j])
                    {
                        ans = j * 13;
                        break;
                    }
                    if (s == diqiuNum[j])
                    {
                        ans = j;
                        break;
                    }
                }
                cout << ans << endl;
            }
        }
        else if (isdigit(s[0]))
        {
            int num = stoi(s);
            if (num < 13)
            {
                cout << diqiuNum[num] << endl;
            }
            else if (num % 13 == 0)
            {
                cout << marsNum[num / 13] << endl;
            }
            else
            {
                cout << marsNum[num / 13] << " " << diqiuNum[num % 13] << endl;
            }
        }
    }
}