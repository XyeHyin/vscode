#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    bool flag = false;

    for (int i = 0; i < s.size()/2 ; i++)
    {
        int j=s.size()-1-i;
            if (s[i] != s[j])
            {
                flag = true;
                break;
            }
        }
    
    if (flag)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
    }
    