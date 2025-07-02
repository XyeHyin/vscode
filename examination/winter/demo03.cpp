#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, y;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '.')
        {
            y += "0";
            
        }
        else if (s[i] == '-' && s[i + 1] == '.')
        {
            y += "1";
            i++;
            
        }
        else if (s[i] == '-' && s[i + 1] == '-')
        {
            y += "2";
            s[i] == 'a';
            s[i + 1] == 'a';
            i++;
           
        }
    }
    cout << y << endl;
}