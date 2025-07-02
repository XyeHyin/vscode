#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    vector<int> n(10, 0);
    vector<int> m(10, 0);
    for (char c : s)
    {
        n[c - '0']++;
    }
    string t;
    int carry = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        int temp = (s[i] - '0') * 2 + carry;
        t.insert(t.begin(), temp % 10 + '0');
        carry = temp / 10;
    }
    if (carry > 0)
    {
        t.insert(t.begin(), carry + '0');
    }
    for (char c : t)
    {
        m[c - '0']++;
    }
    if (n == m)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    cout << t << endl;
}