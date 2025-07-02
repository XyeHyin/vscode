#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int mini = n, minj = m, maxi = -1, maxj = -1;
    char c2[n][m];
    bool min = false, max = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c2[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (c2[i][j] == '*')
            {
                mini = i;
                minj = j;
                min = true;
                break;
            }
        }
        if (min)
        {
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (c2[i][j] == '*')
            {
                maxi = i;
                maxj = j;
                max = true;
                break;
            }
        }
        if (max)
        {
            break;
        }
    }

    for (int i = mini; i <= maxi; i++)
    {
        for (int j = minj; j <= maxj; j++)
        {
            cout << c2[i][j];
        }
        cout << endl;
    }

    return 0;
}