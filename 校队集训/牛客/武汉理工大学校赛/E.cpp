#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, Q;
    string s;
    cin >> n >> Q >> s;
    vector<vector<int>> pos(26);
    for (int i = 0; i < n; ++i)
    {
        pos[s[i] - 'A'].push_back(i);
    }
    for (int i = 0; i < Q; ++i)
    {
        string t;
        cin >> t;
        int l = 0, r = 0;
        int ans = 0;
        while (r < t.size())
        {
            auto &v = pos[t[r] - 'A'];
            auto it = lower_bound(v.begin(), v.end(), l == 0 ? 0 : pos[t[l - 1] - 'A'].back() + 1);
            if (it == v.end())
            {
                l = r = r + 1;
            }
            else
            {
                r++;
                ans = max(ans, r - l);
            }
        }
        cout << ans << endl;
    }
    return 0;
}