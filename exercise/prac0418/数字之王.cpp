#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n;
    cin >> s>>n;
    for (int i = 0; i < n; i++)
    {
        int left = 0, right = 0;
        string front, behind;
        cin >> left >> right >> front >> behind;
        string cut = s.substr(left, right - left);
        s.erase(left, right - left);
        for (int i = 0; i < s.size() - front.size(); i++)
        {
            if (front == s.substr(i, front.size()))
            {
                s.insert(i+front.size(), cut);
                i += cut.size();
            }
        }
    }
    cout << s;
}