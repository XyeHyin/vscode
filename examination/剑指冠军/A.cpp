#include <bits/stdc++.h>
using namespace std;

int m, n;

int dfs(int a, int b, int *map)
{
    if (a == m - 1 && b == n - 1){
        return 1;
    }
    else
    {
        int count = 0;
        if (a + 1 < m&&map[a+1][b]==0)
        {
            count += dfs(a + 1, b, map);
        }
        if (b + 1 < n)
        {
            count += dfs(a, b + 1,map);
        }
        return count;
    }
}

int main()
{
    cin >> m >> n;
    int map[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    cout << dfs(0, 0,*map) << endl;
    return 0;
}