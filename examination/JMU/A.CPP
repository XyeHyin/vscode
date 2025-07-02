#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592
int main()
{
    string s;
    getline(cin, s);
    int left = 0, right = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (!isalpha(s[i]))
        {
            right = i;
            cout << (right - left)%10;
            for (int j = right; j < s.size(); j++)
            {
                if (isalpha(s[j]))
                {
                    left = j;
                    break;
                }
            }
            i = left;
        }
    }
    if(!isalpha(s[s.size()-1]))cout << (s.size()- left-1)%10 << endl;
    else cout << (s.size()- left)%10 << endl;
}