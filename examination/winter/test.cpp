#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    char c[n][m];
    char c2[n][m];
    memset(c, '.', sizeof(c));
    bool y = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c2[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        y = true;
        for (int j = 0; j < m; j++)
        {
            if (c2[i][j] == '*')
            {
                y = false;
            }
            if (y == true)
            {
                c[i][j] = '0';
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        y = true;
        for (int j = 0; j < n; j++)
        {
            if (c2[j][i] == '*')
            {
                y = false;
            }
            if (y == true)
            {
                c[j][i] = '0';
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (c[i][j] == '0'){
                c2[i][j] = c[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (c2[i][j] != '.'){
                cout << c2[i][j];
            }
        }
        cout << endl;
    }
}