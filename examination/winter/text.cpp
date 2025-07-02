#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int mini = n, minj = m, maxi = -1, maxj = -1;
    char c2[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c2[i][j];
            if (c2[i][j] == '*')
            {
                mini = min(mini, i);
                minj = min(minj, j);
                maxi = max(maxi, i);
                maxj = max(maxj, j);
            }
        }
    }
    cout<<mini<<" "<<minj<<" "<<maxi<<" "<<maxj<<endl;
    for (int i = mini; i <= maxi; i++)
    {
        for (int j = minj; j <= maxj; j++)
        {
            cout << c2[i][j];
        }
        cout << endl;
    }
}