#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]))
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                sum += s[i] - 'a' + 1;
            }
            else
            {
                sum += s[i] - 'A' + 1;
            }
        }
        else
        {
            continue;
        }
    }
    string radix2;
    while (sum != 0)
    {
        radix2 += to_string(sum % 2);
        sum /= 2;
    }
    int ling = 0, yi = 0;
    for (int i = 0; i < radix2.size(); i++)
    {
        if (radix2[i] == '0')
        {
            ling++;
        }
        else if (radix2[i] == '1')
        {
            yi++;
        }
    }
    cout << ling << " " << yi;
}