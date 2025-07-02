#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            s[i] = '0';
        }
    }
    int ans = stoi(s.substr(0, 3)) + stoi(s.substr(s.size() - 3, 3));
    cout << ans << endl;
}