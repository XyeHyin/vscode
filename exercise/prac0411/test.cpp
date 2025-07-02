#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    vector<vector<int>> pos(n, vector<int>(d));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> pos[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        int superior = -1;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            bool isSuperior = true;
            for (int k = 0; k < d; k++)
            {
                if (pos[j][k] <= pos[i][k])
                {
                    isSuperior = false;
                    break;
                }
            }
            if (isSuperior && (superior == -1 || j < superior))
            {
                superior = j;
            }
        }
        cout << (superior == -1 ? 0 : superior + 1) << endl;
    }
    return 0;
}