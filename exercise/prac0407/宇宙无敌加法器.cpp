#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, ans;
    string n1, n2;
    cin >> s >> n1 >> n2;
    if (n1.size() < n2.size())
    {
        n1.insert(0, n2.size() - n1.size(), '0');
    }
    else if (n1.size() > n2.size())
    {
        n2.insert(0, n1.size() - n2.size(), '0');
    }
    if (s.size() < n1.size())
    {
        s.insert(0, n1.size() - s.size(), '0');
    }
    int jinWei = 0;
    for (int i = n1.size() - 1; i >= 0; i--)
    {
        int n = n1[i] - '0' + n2[i] - '0' + jinWei;
        jinWei = -1;
        int radix = s[i] == '0' ? 10 : s[i] - '0';
        bool flag = false;
        while (n != 0)
        {
            if (!flag)
            {
                if (to_string(n % radix)!="-1"){
                    ans.insert(0, to_string(n % radix));
                }
                flag = true;
            }
            n /= radix;
            jinWei++;
        }
    }
    if (jinWei != 0 && jinWei != -1)
    {
        ans.insert(0, to_string(jinWei));
    }
    if (ans.empty())
    {
        cout << "0";
    }
    else
    {
        cout << ans;
    }
}
