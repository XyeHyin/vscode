#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> dirt(n, vector<char>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> dirt[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
        {
            if (dirt[i][j] == 'L')
            {
                bool surroundedByL = true;
                for (int dx = -1; dx <= 1; dx++)
                {
                    for (int dy = -1; dy <= 1; dy++)
                    {
                        int x = i + dx, y = j + dy;
                        if (x >= 0 && x < n && y >= 0 && y < m && dirt[x][y] != 'L'){
                            surroundedByL = false;
                            break;
                        }
                    }
                    if (!surroundedByL)
                        break;
                }
                if (surroundedByL && i > 0 && i < n - 1 && j > 0 && j < m - 1) dirt[i][j] = 'S';
                
            }

                if (dirt[i][j] == 'G')
                {
                    bool surroundedByL = false, noH = true;
                    for (int dx = -1; dx <= 1; dx++)
                    {
                        for (int dy = -1; dy <= 1; dy++)
                        {
                            int x = i + dx, y = j + dy;
                            if (x >= 0 && x < n && y >= 0 && y < m)
                            {
                                if (dirt[x][y] == 'L')
                                    surroundedByL = true;
                                if (dirt[x][y] == 'H')
                                    noH = false;
                            }
                        }
                    }
                    if (surroundedByL && noH)
                        dirt[i][j] = 'N';
            }
            if (dirt[i][j] == 'G')
            {
                bool noH = true;
                for (int dx = -1; dx <= 1; dx++)
                {
                    for (int dy = -1; dy <= 1; dy++)
                    {
                        int x = i + dx, y = j + dy;
                        if (x >= 0 && x < n && y >= 0 && y < m && dirt[x][y] == 'H')
                        {
                            noH = false;
                            break;
                        }
                    }
                    if (!noH)
                        break;
                }
                if (noH)
                    dirt[i][j] = 'B';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dirt[i][j];
        }
        cout << endl;
    }
}