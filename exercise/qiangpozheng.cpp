#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if (s.size() == 4)
    {
        if (stoi(s.substr(0, 2)) < 22)
        {
            cout << 20 << s.substr(0, 2) << '-' << s.substr(2, 4) << endl;
        }
        else
        {
            cout << 19 << s.substr(0, 2) << '-' << s.substr(2, 4) << endl;
        }
    }
    else if (s.size() == 6)
    {
        cout << s.substr(0, 4) << '-' << s.substr(4, 6) << endl;
    }
}