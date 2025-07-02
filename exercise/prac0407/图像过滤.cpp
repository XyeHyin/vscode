#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, A, B, change;
    cin >> x >> y >> A >> B >> change;
    int arr[x][y];
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (arr[i][j] >= A && arr[i][j] <= B)
            {
                arr[i][j] = change;
            }
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%03d", arr[i][j]);
            if(j!=y-1){
                cout << " ";
            }
        }
        cout << endl;
    }
}