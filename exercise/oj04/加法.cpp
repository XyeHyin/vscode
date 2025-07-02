#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, m;
    cin >> s;
    bool jinWei = false;
    if (s[s.size() - 1] == '9')
    {
        jinWei = true;
    }
    if (jinWei)
    {
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '9')
            {
                s[i] = '0';
            }
            else
            {
                s[i] = (s[i] - '0' + 1) + '0';
                break;
            }
        }
    }
    else
    {
        s[s.size() - 1] = (s[s.size() - 1] - '0' + 1) + '0';
    }
    cout << s << endl;
}