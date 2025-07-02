#include <bits/stdc++.h>
using namespace std;
int main()
{
    string pingyin[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    string s;
    cin >> s;
    if (s[0] == '-')
    {
        cout << "fu ";
    }
    
        for (int i = 0; i < s.size(); i++)
        {
            cout << pingyin[s[i] - '0'];
            if (i != s.size())
            {
                cout << " ";
            }
        }
    
}