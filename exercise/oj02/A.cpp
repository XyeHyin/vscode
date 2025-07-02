#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, cnt = 0;
    cin >> n;
    vector<int> nums[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            nums[i].push_back(num);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j && i + j != n - 1) cnt += nums[i][j];
            if (i + j == n - 1&&i!=j) cnt += nums[i][j];
            if (i == j && i + j == n - 1) cnt+=nums[i][j];
        }
    }
    cout << cnt << endl;
}