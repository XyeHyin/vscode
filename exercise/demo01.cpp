#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    string jian;
    getline(cin, s);
    getline(cin, jian);
    for (int i = 0;i< s.length(); i++)
    {
        bool flag = false;
        for (int j = 0; j<jian.length(); j++)
        {
            if (jian[j] == s[i])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << s[i];
        }
    }
    cout << endl;
}