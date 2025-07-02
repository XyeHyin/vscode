#include <bits/stdc++.h>
using namespace std;
bool play(string s)
{
    bool haveP = false;
    bool haveT = false;
    bool haveA = false;
    int positionP = 0;
    int positionT = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'P')
        {
            haveP = true;
            positionP = i;
        }
        if (s[i] == 'A')
        {
            haveA = true;
        }
        if (s[i] == 'T')
        {
            haveT = true;
            positionT = i;
        }
    }
    if (!haveP || !haveA || !haveT || positionP >= positionT||positionT-positionP==1)
    {
        return false;
    }
    if (count(s.begin(), s.end(), 'P') != 1 || count(s.begin(), s.end(), 'T') != 1)
    {
        return false;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != 'P' && s[i] != 'A' && s[i] != 'T')
        {
            return false;
        }
    }
    int a = positionP, b = positionT - positionP - 1, c = s.length() - positionT - 1;
    if (a * b != c)
        return false;
    return true;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (play(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}