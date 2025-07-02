#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> count(51, 0);
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++)
            {
                int x;
                cin >> x;
                count[x]++;
            }
        }
        int res = 0;
        for (int i = 1; i <= 50; i++)
        {
            if (count[i] == 1)
            {
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}