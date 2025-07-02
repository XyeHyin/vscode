#include <bits/stdc++.h>
using namespace std;

bool isValid(string s, int qz[], char m[])
{
    int sum = 0;
    for (int i = 0; i < 17; i++)
    {
        sum += (s[i] - '0') * qz[i];
    }
    int z = sum % 11;
    return m[z] == s[17];
}

int main()
{
    char m[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int qz[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

    int n;
    cin >> n;
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (!isValid(s, qz, m))
        {
            ans.push_back(s);
        }
    }
    if (ans.empty())
    {
        cout << "All passed";
    }
    else{
        for (string s : ans)
        {
            cout << s << endl;
        }
    }
}