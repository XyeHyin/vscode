#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cnt, weishu;
    string s;
    bool fu = false, ou = false;
    cin >> s;
    if (s[0] == '-')
    {
        fu = true;
    }
    if ((s[s.size() - 1] - '0') % 2 == 0)
    {
        ou = true;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '-')
        {
            weishu++;
        }
        if ((s[i] - '0') == 2)
        {
            cnt++;
        }
    }
    double chengdu = cnt * 1.0 / weishu * 1.0 * (ou ? 2 : 1) * (fu ? 1.5 : 1) * 0.01;
    printf("%.2f", chengdu);
    cout << '%' << endl;
}