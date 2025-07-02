#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main()
{
    int M, N, TOL;
    cin >> M >> N >> TOL;
    ll a[N][M];
    map<ll, int> mp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> a[i][j];
            mp[a[i][j]]++;
        }
    }
    int count = 0;
    int ansX, ansY, ans;
    vector<int> tmp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (mp[a[i][j]] == 1)
            {
                bool flag = true;
                for (int k = 0; k < 8; k++)
                {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni >= 0 && ni < N && nj >= 0 && nj < M && abs(a[i][j] - a[ni][nj]) <= TOL)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    count++;
                    ansX = j + 1;
                    ansY = i + 1;
                    ans = a[i][j];
                }
            }
        }
    }
    switch (count)
    {
    case 0:
        cout << "Not Exist";
        break;
    case 1:
        cout << "(" << ansX << ", " << ansY << "): " << ans;
        break;
    default:
        cout << "Not Unique";
    }
}